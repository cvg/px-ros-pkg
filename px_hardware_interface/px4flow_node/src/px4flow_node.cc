#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>

// MAVLINK includes
#include <pixhawk/mavlink.h>

// ROS includes
#include <image_transport/image_transport.h>
#include <px_comm/OpticalFlow.h>
#include <ros/ros.h>
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/Image.h>

size_t imageSize = 0;           ///< Image size being transmitted (bytes)
size_t imagePackets = 0;        ///< Number of data packets being sent for this image
int imagePayload;           ///< Payload size per transmitted packet (bytes). Standard is 254, and decreases when image resolution increases.
int imageWidth;             ///< Width of the image stream
int imageHeight;            ///< Width of the image stream
std::vector<uint8_t> imageBuffer;

int systemId = -1;
int compId = 0;

void
syncCallback(const ros::TimerEvent& timerEvent, boost::asio::serial_port* port)
{
    if (systemId == -1)
    {
        return;
    }

    struct timeval tv;
    gettimeofday(&tv, NULL);

    uint64_t timeNow = static_cast<uint64_t>(tv.tv_sec) * 1000000 + tv.tv_usec;

    mavlink_message_t msg;
    uint8_t buffer[MAVLINK_MAX_PACKET_LEN];

    mavlink_msg_system_time_pack(systemId, compId, &msg, timeNow, 0);

    size_t messageLength = mavlink_msg_to_send_buffer(buffer, &msg);
    if (messageLength != boost::asio::write(*port, boost::asio::buffer(buffer, messageLength)))
    {
        ROS_WARN("Unable to send system time over serial port.");
    }
}

void
readStart(boost::asio::serial_port* port, uint8_t* buffer, ros::Publisher* optFlowPub, image_transport::Publisher* imagePub, uint32_t length, uint32_t timeout_ms);

void
readCallback(const boost::system::error_code& error, size_t bytesTransferred, boost::asio::serial_port* port, uint8_t* buffer, ros::Publisher* optFlowPub, image_transport::Publisher* imagePub)
{
    if (error)
    {
        return;
    }

    mavlink_message_t message;
    mavlink_status_t status;

    bool msgReceived = mavlink_parse_char(MAVLINK_COMM_1, buffer[0], &message, &status);

    if (msgReceived)
    {
        systemId = message.sysid;

        switch (message.msgid)
        {
        case MAVLINK_MSG_ID_OPTICAL_FLOW:
        {
            // decode message
            mavlink_optical_flow_t flow;
            mavlink_msg_optical_flow_decode(&message, &flow);

            px_comm::OpticalFlow optFlowMsg;

            optFlowMsg.header.stamp = ros::Time(flow.time_usec / 1000000, flow.time_usec % 1000000);
            optFlowMsg.ground_distance = flow.ground_distance;
            optFlowMsg.flow_x = flow.flow_x;
            optFlowMsg.flow_y = flow.flow_y;
            optFlowMsg.velocity_x = flow.flow_comp_m_x;
            optFlowMsg.velocity_y = flow.flow_comp_m_y;
            optFlowMsg.quality = flow.quality;

            optFlowPub->publish(optFlowMsg);

            break;
        }
        case MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE:
        {
            mavlink_data_transmission_handshake_t handshake;
            mavlink_msg_data_transmission_handshake_decode(&message, &handshake);

            imageSize = handshake.size;
            imagePackets = handshake.packets;
            imagePayload = handshake.payload;
            imageWidth = handshake.width;
            imageHeight = handshake.height;

            if (imageBuffer.size() < imageSize)
            {
                imageBuffer.resize(imageSize);
            }

            break;
        }
        case MAVLINK_MSG_ID_ENCAPSULATED_DATA:
        {
            if (imageSize == 0 || imagePackets == 0)
            {
                break;
            }

            mavlink_encapsulated_data_t img;
            mavlink_msg_encapsulated_data_decode(&message, &img);
            size_t seq = img.seqnr;
            size_t pos = seq * imagePayload;

            if (seq + 1 > imagePackets)
            {
                break;
            }

            size_t bytesToCopy = imagePayload;
            if (pos + imagePayload >= imageSize)
            {
                 bytesToCopy = imageSize - pos;
            }

            memcpy(&imageBuffer[pos], img.data, bytesToCopy);

            if (seq + 1 == imagePackets)
            {
                sensor_msgs::Image image;
                image.height = imageHeight;
                image.width = imageWidth;
                image.encoding = sensor_msgs::image_encodings::MONO8;
                image.is_bigendian = false;
                image.step = imageWidth;

                image.data.resize(imageSize);
                memcpy(&image.data[0], &imageBuffer[0], imageSize);

                imagePub->publish(image);
            }
            break;
        }
        }
    }

    readStart(port, buffer, optFlowPub, imagePub, 1, 1000);
}

void
readStart(boost::asio::serial_port* port, uint8_t* buffer, ros::Publisher* optFlowPub, image_transport::Publisher* imagePub, uint32_t length, uint32_t timeout_ms)
{
    boost::asio::async_read(*port, boost::asio::buffer(buffer, length),
                            boost::bind(&readCallback, boost::asio::placeholders::error,
                                        boost::asio::placeholders::bytes_transferred, port, buffer, optFlowPub, imagePub));
}

void
printTopicInfo(void)
{
    // print published/subscribed topics
    std::string nodeName = ros::this_node::getName();

    ros::V_string topics;
    ros::this_node::getSubscribedTopics(topics);

    std::string topicsStr = nodeName + ":\n\tsubscribed to topics:\n";
    for (unsigned int i = 0; i < topics.size(); ++i)
    {
        topicsStr += ("\t\t" + topics.at(i) + "\n");
    }

    topicsStr += "\tadvertised topics:\n";
    ros::this_node::getAdvertisedTopics(topics);
    for (unsigned int i = 0; i < topics.size(); ++i)
    {
        topicsStr += ("\t\t" + topics.at(i) + "\n");
    }

    ROS_INFO("%s", topicsStr.c_str());
}

int
main(int argc, char** argv)
{
    ros::init(argc, argv, "px4flow");
    ros::NodeHandle nh("px4flow");

    ros::NodeHandle pnh("~");

    std::string portStr;
    pnh.param("serial_port", portStr, std::string("/dev/ttyUSB0"));

    int baudrate;
    pnh.param("baudrate", baudrate, 921600);

    boost::asio::io_service uartService;
    boost::asio::serial_port port(uartService);

    // open port
    try
    {
        port.open(portStr);

        ROS_INFO("Opened serial port %s.", portStr.c_str());
    }
    catch (boost::system::system_error::exception e)
    {
        ROS_ERROR("Could not open serial port %s. Reason: %s.", portStr.c_str(), e.what());

        return -1;
    }

    // configure baud rate
    try
    {
        port.set_option(boost::asio::serial_port_base::baud_rate(baudrate));
        port.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));
        port.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
        port.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
        port.set_option(boost::asio::serial_port_base::character_size(8));

        ROS_INFO("Set baudrate %d.", baudrate);
    }
    catch (boost::system::system_error::exception e)
    {
        ROS_ERROR("Could not set baudrate %d. Reason: %s.", baudrate, e.what());

        return -1;
    }

    // set up publishers
    ros::Publisher optFlowPub = nh.advertise<px_comm::OpticalFlow>("opt_flow", 5);

    image_transport::ImageTransport it(nh);
    image_transport::Publisher imagePub = it.advertise("camera_image", 5);

    // set up thread to asynchronously read data from serial port
    uint8_t buffer[256];
    readStart(&port, buffer, &optFlowPub, &imagePub, 1, 1000);
    boost::thread uartThread = boost::thread(boost::bind(&boost::asio::io_service::run, &uartService));

    ros::Timer syncTimer = nh.createTimer(ros::Duration(2.0), boost::bind(&syncCallback, _1, &port));

    printTopicInfo();

    ros::spin();

    return 0;
}

