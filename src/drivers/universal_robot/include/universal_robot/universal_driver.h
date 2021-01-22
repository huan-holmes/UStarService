#pragma once
#include "protocol.h"


#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/PoseStamped.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/Char.h>
#include <std_msgs/Float64MultiArray.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <angles/angles.h>

struct ModuleType{
    uint8_t four_wheel = 0;
    uint8_t ackerMan_normal = 0;
    uint8_t diff_ = 0;
    uint8_t safe_sensor_ = 0;
    uint8_t battery_ = 0;
    uint8_t safe_sensor_ex_ = 0;
    uint8_t imu_msg = 0;
};

struct KinematicInfo {

    double vel = 0;
    double w = 0;

    double distance = 0;
    double d_w = 0;

    uint32_t stamp = 0;
};

struct KinematicParam {
    float slow_down = 0;
    float wheel_base = 0;
    float wheel_radius = 0;
    float wheel_gauge = 0;
    float encoder_lines = 0;
};

class UniversalDrive {
public:
    UniversalDrive()
    {}
    bool DataGet();
    int  OpenSerial(const char* serial_dev_name);
    int  SerialSet(int fd, int speed, int flow_ctrl, int databits, int stopbits, int parity);
    KinematicInfo info_;
    ModuleType module_type_;
    KinematicParam kinematic_;
    void SentRpm(geometry_msgs::Twist cmd_vel);
    void Test();

public:
    sensor_msgs::Imu imu_msgs_;
    ros::Time last_time_;
    ros::Time now_time_;
private:


    void Decode(const uint8_t dat);
    void CheckData();
    int fd_;
    std::vector<uint8_t> packet_;
    
    unsigned short CRC16(unsigned char *puchMsg, unsigned short usDataLen);
    void SenCmdVel(uint8_t *buffer, const uint8_t size);
};
class UniversalNode {
public:
    UniversalNode();

    void Run();


    void PublicOdom(const double v ,const double distance );
    void PublicImu(const float av);

    double GetDtheta();

    void control_vel(const geometry_msgs::Twist cmd_vel);
    void get_imu_msgs(const sensor_msgs::Imu::ConstPtr& imu_msgs) {
        imu_msgs_ = *imu_msgs;

    }

    //消息订阅与发布
    ros::NodeHandle nh;

    nav_msgs::Odometry odom_msg;
    tf::TransformBroadcaster odom_broadcaster; //里程计与base_link之间的变换发布
    ros::Subscriber sub_cmd_vel , sub_imu_msgs ;
    ros::Publisher odom_pub, imu_pub_;
    std::string odom_dev_;
    KinematicParam kinematic_;
    sensor_msgs::Imu imu_msgs_;
    bool odom_is_update_;
    UniversalDrive drive_;
    

};
