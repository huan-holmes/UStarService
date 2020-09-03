#ifndef USTAR_CONTROLLER_H_
#define USTAR_CONTROLLER_H_
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <serial/serial.h>
#include <string>
#include <boost/thread.hpp>

namespace UstarController
{
    using std::string;
    union floatData
    {
        float d;
        unsigned char data[4];
    };

    class Controller
    {
        public:
            Controller();
            ~Controller();
            
            void init();
            void start();
            void cmdCallback(const geometry_msgs::Twist &cmd_vel);
            void publishLoop(double publish_period);
            void odomPublish();
            void tfPublish();
            

        private:
            ros::NodeHandle nh_;
            ros::Subscriber vel_sub_;
            ros::Publisher odom_pub_;
            tf::TransformBroadcaster odom_broadcaster_;
            geometry_msgs::TransformStamped odom_trans_;
            geometry_msgs::Quaternion odom_quat_;
            nav_msgs::Odometry odom_;
            boost::thread *odom_thread_;
            double publish_period_;


            string serial_port_;
            unsigned long serial_baud_;
            unsigned char data_terminal0_;
            unsigned char data_terminal1_;
            string rec_buffer_;

            float ratio_;
            float D_;
            float linear_temp_;
            float angular_temp_;

            floatData right_speed_data_;
            floatData left_speed_data_;
            floatData position_x_;
            floatData position_y_;
            floatData oriention_;
            floatData vel_linear_;
            floatData vel_angular_;
    };

}; // namespace UstarController
#endif