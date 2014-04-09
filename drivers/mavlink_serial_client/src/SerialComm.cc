#include <boost/bind.hpp>
#include <Eigen/Dense>

// ROS includes
#include <px_comm/Mavlink.h>
#include <px_comm/OpticalFlow.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/MagneticField.h>

#include "mavlink_serial_client/SerialComm.h"

namespace px
{

SerialComm::SerialComm(ros::NodeHandle& nh, const std::string& frameId)
 : m_port(m_uartService)
 , m_timer(m_uartService)
 , m_imageSize(0)
 , m_imagePackets(0)
 , m_imagePayload(0)
 , m_imageWidth(0)
 , m_imageHeight(0)
 , m_systemId(-1)
 , m_compId(0)
 , m_nh(nh)
 , m_frameId(frameId)
 , m_timeout(false)
 , m_errorCount(0)
 , m_connected(false)
{

}

SerialComm::~SerialComm()
{
    if (m_connected)
    {
        close();
    }
}

bool
SerialComm::open(const std::string& portStr, int baudrate)
{
    m_timeout = false;
    m_errorCount = 0;
    m_connected = false;

    // open port
    try
    {
        m_port.open(portStr);

        ROS_INFO("Opened serial port %s.", portStr.c_str());
    }
    catch (boost::system::system_error::exception e)
    {
        ROS_ERROR("Could not open serial port %s. Reason: %s.", portStr.c_str(), e.what());

        return false;
    }

    // configure baud rate
    try
    {
        m_port.set_option(boost::asio::serial_port_base::baud_rate(baudrate));
        m_port.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));
        m_port.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
        m_port.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
        m_port.set_option(boost::asio::serial_port_base::character_size(8));

        ROS_INFO("Set baudrate %d.", baudrate);
    }
    catch (boost::system::system_error::exception e)
    {
        ROS_ERROR("Could not set baudrate %d. Reason: %s.", baudrate, e.what());

        return false;
    }

    // set up publishers
    m_mavlinkPub = m_nh.advertise<px_comm::Mavlink>("mavlink", 100);
    m_optFlowPub = m_nh.advertise<px_comm::OpticalFlow>("opt_flow", 5);

    image_transport::ImageTransport it(m_nh);
    m_imagePub = it.advertise("camera_image", 5);

    // AscTec-specific
    m_imuPub = m_nh.advertise<sensor_msgs::Imu>("imu", 10);
    m_magPub = m_nh.advertise<sensor_msgs::MagneticField>("mag", 10);
    m_viconPub = m_nh.advertise<geometry_msgs::PoseWithCovarianceStamped>("vicon", 10);

    ros::NodeHandle raw_nh(m_nh, "raw");
    m_imuRawPub = raw_nh.advertise<sensor_msgs::Imu>("imu", 10);

    // set up thread to asynchronously read data from serial port
    readStart(1000);
    m_uartThread = boost::thread(boost::bind(&boost::asio::io_service::run, &m_uartService));

    ros::Timer syncTimer = m_nh.createTimer(ros::Duration(2.0), boost::bind(&SerialComm::syncCallback, this, _1));

    m_connected = true;

    return true;
}

void
SerialComm::close(void)
{
    if (!m_connected)
    {
        return;
    }

    m_uartService.post(boost::bind(&boost::asio::deadline_timer::cancel, &m_timer));
    m_uartService.post(boost::bind(&boost::asio::serial_port::close, &m_port));

    m_uartThread.join();
}

void
SerialComm::readCallback(const boost::system::error_code& error, size_t bytesTransferred)
{
    if (error)
    {
        if (error == boost::asio::error::operation_aborted)
        {
            // if serial connection timed out, try reading again
            if (m_timeout)
            {
                m_timeout = false;
                readStart(1000);

                return;
            }
        }

        ROS_WARN("Read error: %s", error.message().c_str());

        if (m_errorCount < 10)
        {
            readStart(1000);
        }
        else
        {
            ROS_ERROR("# read errors exceeded 10. Aborting...");
            ros::shutdown();
        }

        ++m_errorCount;

        return;
    }

    m_timer.cancel();

    mavlink_message_t message;
    mavlink_status_t status;

    for (size_t i = 0; i < bytesTransferred; i++)
    {
        bool msgReceived = mavlink_parse_char(MAVLINK_COMM_1, m_buffer[i], &message, &status);

        if (msgReceived)
        {
            publishMAVLINKMessage(message);

            m_systemId = message.sysid;

            switch (message.msgid)
            {
            /**
             * Message specs
             * https://pixhawk.ethz.ch/mavlink/#ATTITUDE
             */
            case MAVLINK_MSG_ID_ATTITUDE:
            {
                if (m_imuPub.getNumSubscribers() == 0)
                {
                    break;
                }

                mavlink_attitude_t att;
                mavlink_msg_attitude_decode(&message, &att);

                sensor_msgs::Imu imu_msg;

                rpyToQuaternion(att.roll, -att.pitch, -att.yaw,
                                imu_msg.orientation.w, imu_msg.orientation.x,
                                imu_msg.orientation.y, imu_msg.orientation.z);

                // TODO: check/verify that these are body-fixed
                imu_msg.angular_velocity.x = att.rollspeed;
                imu_msg.angular_velocity.y = -att.pitchspeed;
                imu_msg.angular_velocity.z = -att.yawspeed;

                // take this from imu high res message, this is supposed to arrive before this one and should pretty much be in sync then
                imu_msg.linear_acceleration.x = m_imuRaw.xacc;
                imu_msg.linear_acceleration.y = -m_imuRaw.yacc;
                imu_msg.linear_acceleration.z = -m_imuRaw.zacc;

                // TODO: can we fill in the covariance here from a parameter that we set from the specs/experience?
                for (sensor_msgs::Imu::_orientation_covariance_type::iterator it = imu_msg.orientation_covariance.begin();
                     it != imu_msg.orientation_covariance.end(); ++it)
                {
                    *it = 0;
                }

                for (sensor_msgs::Imu::_angular_velocity_covariance_type::iterator it =
                     imu_msg.angular_velocity_covariance.begin(); it != imu_msg.angular_velocity_covariance.end(); ++it)
                {
                    *it = 0;
                }

                for (sensor_msgs::Imu::_linear_acceleration_covariance_type::iterator it =
                     imu_msg.linear_acceleration_covariance.begin(); it != imu_msg.linear_acceleration_covariance.end();
                     ++it)
                {
                    *it = 0;
                }

                imu_msg.header.frame_id = m_frameId;
                imu_msg.header.seq = m_imuRaw.time_usec / 1000;
                imu_msg.header.stamp = ros::Time::now();
                m_imuPub.publish(imu_msg);
            }
            case MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE:
            {
                mavlink_data_transmission_handshake_t handshake;
                mavlink_msg_data_transmission_handshake_decode(&message, &handshake);

                m_imageSize = handshake.size;
                m_imagePackets = handshake.packets;
                m_imagePayload = handshake.payload;
                m_imageWidth = handshake.width;
                m_imageHeight = handshake.height;

                if (m_imageBuffer.size() < m_imageSize)
                {
                    m_imageBuffer.resize(m_imageSize);
                }

                break;
            }
            case MAVLINK_MSG_ID_ENCAPSULATED_DATA:
            {
                if (m_imageSize == 0 || m_imagePackets == 0)
                {
                    break;
                }

                mavlink_encapsulated_data_t img;
                mavlink_msg_encapsulated_data_decode(&message, &img);
                size_t seq = img.seqnr;
                size_t pos = seq * m_imagePayload;

                if (seq + 1 > m_imagePackets)
                {
                    break;
                }

                size_t bytesToCopy = m_imagePayload;
                if (pos + m_imagePayload >= m_imageSize)
                {
                     bytesToCopy = m_imageSize - pos;
                }

                memcpy(&m_imageBuffer[pos], img.data, bytesToCopy);

                if (seq + 1 == m_imagePackets && m_imagePub.getNumSubscribers() > 0)
                {
                    sensor_msgs::Image image;
                    image.header.frame_id = m_frameId;
                    image.height = m_imageHeight;
                    image.width = m_imageWidth;
                    image.encoding = sensor_msgs::image_encodings::MONO8;
                    image.is_bigendian = false;
                    image.step = m_imageWidth;

                    image.data.resize(m_imageSize);
                    memcpy(&image.data[0], &m_imageBuffer[0], m_imageSize);

                    m_imagePub.publish(image);
                }
                break;
            }
            /*
             * Message specs
             * https://pixhawk.ethz.ch/mavlink/#HIGHRES_IMU
             */
            case MAVLINK_MSG_ID_HIGHRES_IMU:
            {
                mavlink_msg_highres_imu_decode(&message, &m_imuRaw);

                std_msgs::Header header;
                header.stamp = ros::Time::now();
                header.seq = m_imuRaw.time_usec / 1000;
                header.frame_id = m_frameId;

                if (m_imuRawPub.getNumSubscribers() > 0)
                {
                    sensor_msgs::Imu imu_msg;

                    imu_msg.angular_velocity.x = m_imuRaw.xgyro;
                    imu_msg.angular_velocity.y = -m_imuRaw.ygyro;
                    imu_msg.angular_velocity.z = -m_imuRaw.zgyro;

                    imu_msg.linear_acceleration.x = m_imuRaw.xacc;
                    imu_msg.linear_acceleration.y = -m_imuRaw.yacc;
                    imu_msg.linear_acceleration.z = -m_imuRaw.zacc;

                    // TODO: can we fill in the covariance here from a parameter that we set from the specs/experience?
                    for (sensor_msgs::Imu::_angular_velocity_covariance_type::iterator it =
                         imu_msg.angular_velocity_covariance.begin(); it != imu_msg.angular_velocity_covariance.end();
                         ++it)
                    {
                        *it = 0;
                    }

                    for (sensor_msgs::Imu::_linear_acceleration_covariance_type::iterator it =
                         imu_msg.linear_acceleration_covariance.begin(); it != imu_msg.linear_acceleration_covariance.end();
                         ++it)
                    {
                        *it = 0;
                    }

                    imu_msg.orientation_covariance[0] = -1;

                    imu_msg.header = header;

                    m_imuRawPub.publish(imu_msg);
                }

                if (m_magPub.getNumSubscribers() > 0)
                {
                    const double gauss_to_tesla = 1.0e-4;
                    sensor_msgs::MagneticField mag_msg;

                    mag_msg.magnetic_field.x = m_imuRaw.xmag * gauss_to_tesla;
                    mag_msg.magnetic_field.y = m_imuRaw.ymag * gauss_to_tesla;
                    mag_msg.magnetic_field.z = m_imuRaw.zmag * gauss_to_tesla;

                    // TODO: again covariance
                    for (sensor_msgs::MagneticField::_magnetic_field_covariance_type::iterator it =
                         mag_msg.magnetic_field_covariance.begin(); it != mag_msg.magnetic_field_covariance.end(); ++it)
                    {
                        *it = 0;
                    }

                    mag_msg.header = header;
                    m_magPub.publish(mag_msg);
                }
                //TODO: pressure, temperature
                // XXX
                break;
            }
            case MAVLINK_MSG_ID_OPTICAL_FLOW:
            {
                if (m_optFlowPub.getNumSubscribers() == 0)
                {
                    break;
                }

                // decode message
                mavlink_optical_flow_t flow;
                mavlink_msg_optical_flow_decode(&message, &flow);

                px_comm::OpticalFlow optFlowMsg;

                optFlowMsg.header.stamp = ros::Time::now();
                optFlowMsg.header.frame_id = m_frameId;
                optFlowMsg.ground_distance = flow.ground_distance;
                optFlowMsg.flow_x = flow.flow_x;
                optFlowMsg.flow_y = flow.flow_y;
                optFlowMsg.velocity_x = flow.flow_comp_m_x;
                optFlowMsg.velocity_y = flow.flow_comp_m_y;
                optFlowMsg.quality = flow.quality;

                m_optFlowPub.publish(optFlowMsg);

                break;
            }
            case MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE:
            {
                if (m_viconPub.getNumSubscribers() == 0)
                {
                    break;
                }

                mavlink_vicon_position_estimate_t pos;
                mavlink_msg_vicon_position_estimate_decode(&message, &pos);
                geometry_msgs::PoseWithCovarianceStamped poseStampedMsg;

                poseStampedMsg.header.stamp = ros::Time().fromNSec(pos.usec * 1000);

                if (message.compid == 99)
                {
                    poseStampedMsg.header.frame_id = "chessboard";
                }
                else
                {
                    poseStampedMsg.header.frame_id = m_frameId;
                }

                Eigen::Matrix3d R;
                R = Eigen::AngleAxisd(pos.yaw, Eigen::Vector3d::UnitZ()) *
                    Eigen::AngleAxisd(pos.pitch, Eigen::Vector3d::UnitY()) *
                    Eigen::AngleAxisd(pos.roll, Eigen::Vector3d::UnitX());
                Eigen::Quaterniond q(R);

                poseStampedMsg.pose.pose.orientation.x = q.x();
                poseStampedMsg.pose.pose.orientation.y = q.y();
                poseStampedMsg.pose.pose.orientation.z = q.z();
                poseStampedMsg.pose.pose.orientation.w = q.w();

                poseStampedMsg.pose.pose.position.x = pos.x;
                poseStampedMsg.pose.pose.position.y = pos.y;
                poseStampedMsg.pose.pose.position.z = pos.z;

                // set covariance to 0.05m std dev
                poseStampedMsg.pose.covariance[0] = 0.05f * 0.05f;
                poseStampedMsg.pose.covariance[7] = 0.05f * 0.05f;
                poseStampedMsg.pose.covariance[14] = 0.05f * 0.05f;

                // set covariance to 0.01 rad
                poseStampedMsg.pose.covariance[21] = 0.01f * 0.01f;
                poseStampedMsg.pose.covariance[28] = 0.01f * 0.01f;
                poseStampedMsg.pose.covariance[35] = 0.01f * 0.01f;

                m_viconPub.publish(poseStampedMsg);

                break;
            }
            }
        }
    }

    readStart(1000);
}

void
SerialComm::readStart(uint32_t timeout_ms)
{
    m_port.async_read_some(boost::asio::buffer(m_buffer, sizeof(m_buffer)),
                           boost::bind(&SerialComm::readCallback, this, boost::asio::placeholders::error,
                                       boost::asio::placeholders::bytes_transferred));

    if (timeout_ms != 0)
    {
        m_timer.expires_from_now(boost::posix_time::milliseconds(timeout_ms));
        m_timer.async_wait(boost::bind(&SerialComm::timeoutCallback, this, boost::asio::placeholders::error));
    }
}

void
SerialComm::syncCallback(const ros::TimerEvent& timerEvent)
{
    if (m_systemId == -1)
    {
        return;
    }

    struct timeval tv;
    gettimeofday(&tv, NULL);

    uint64_t timeNow = static_cast<uint64_t>(tv.tv_sec) * 1000000 + tv.tv_usec;

    mavlink_message_t msg;
    mavlink_msg_system_time_pack(m_systemId, m_compId, &msg, timeNow, 0);

    size_t messageLength = mavlink_msg_to_send_buffer(m_buffer, &msg);
    if (messageLength != boost::asio::write(m_port, boost::asio::buffer(m_buffer, messageLength)))
    {
        ROS_WARN("Unable to send system time over serial port.");
    }
}

void
SerialComm::timeoutCallback(const boost::system::error_code& error)
{
    if (!error)
    {
        m_port.cancel();
        m_timeout = true;
        ROS_WARN("Serial connection timed out.");
    }
}

void
SerialComm::rpyToQuaternion(const double& roll, const double& pitch, const double& yaw,
                            double& w, double& x, double& y, double& z) const
{
    double sR2, cR2, sP2, cP2, sY2, cY2;
    sR2 = sin(roll * 0.5);
    cR2 = cos(roll * 0.5);
    sP2 = sin(pitch * 0.5);
    cP2 = cos(pitch * 0.5);
    sY2 = sin(yaw * 0.5);
    cY2 = cos(yaw * 0.5);

    // Rz*Ry*Rx for 2012 firmware:
    w = cP2 * cR2 * cY2 + sP2 * sR2 * sY2;
    x = cP2 * cY2 * sR2 - cR2 * sP2 * sY2;
    y = cR2 * cY2 * sP2 + cP2 * sR2 * sY2;
    z = cP2 * cR2 * sY2 - cY2 * sP2 * sR2;
}

void
SerialComm::publishMAVLINKMessage(const mavlink_message_t& message)
{
    px_comm::Mavlink mavlink;
    mavlink.len = message.len;
    mavlink.seq = message.seq;
    mavlink.sysid = message.sysid;
    mavlink.compid = message.compid;
    mavlink.msgid = message.msgid;

    for (int i = 0; i < message.len / 8; ++i)
    {
        mavlink.payload64.push_back(message.payload64[i]);
    }

    m_mavlinkPub.publish(mavlink);
}

}
