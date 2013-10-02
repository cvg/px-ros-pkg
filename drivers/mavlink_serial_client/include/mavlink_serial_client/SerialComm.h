#include <boost/asio.hpp>
#include <boost/thread.hpp>

// MAVLINK includes
#include <pixhawk/mavlink.h>

// ROS includes
#include <image_transport/image_transport.h>
#include <ros/ros.h>

namespace px
{

class SerialComm
{
public:
    SerialComm(ros::NodeHandle& nh, const std::string& frameId);
    ~SerialComm();

    bool open(const std::string& portStr, int baudrate);
    void close(void);

private:
    void readCallback(const boost::system::error_code& error, size_t bytesTransferred);
    void readStart(uint32_t timeout_ms);
    void syncCallback(const ros::TimerEvent& timerEvent);
    void timeoutCallback(const boost::system::error_code& error);

    void rpyToQuaternion(const double& roll, const double& pitch, const double& yaw,
                         double& w, double& x, double& y, double& z) const;
    void publishMAVLINKMessage(const mavlink_message_t& message);

    boost::asio::io_service m_uartService;
    boost::asio::serial_port m_port;
    boost::asio::deadline_timer m_timer;
    boost::thread m_uartThread;

    size_t m_imageSize;       ///< Image size being transmitted (bytes)
    size_t m_imagePackets;    ///< Number of data packets being sent for this image
    int m_imagePayload;       ///< Payload size per transmitted packet (bytes). Standard is 254, and decreases when image resolution increases.
    int m_imageWidth;         ///< Width of the image stream
    int m_imageHeight;        ///< Width of the image stream
    std::vector<uint8_t> m_imageBuffer;

    int m_systemId;
    int m_compId;

    uint8_t m_buffer[MAVLINK_MAX_PACKET_LEN];

    ros::NodeHandle m_nh;
    image_transport::Publisher m_imagePub;
    ros::Publisher m_imuPub;
    ros::Publisher m_imuRawPub;
    ros::Publisher m_magPub;
    ros::Publisher m_mavlinkPub;
    ros::Publisher m_optFlowPub;
    ros::Publisher m_viconPub;

    mavlink_highres_imu_t m_imuRaw;

    std::string m_frameId;

    bool m_timeout;
    int m_errorCount;

    bool m_connected;
};

}
