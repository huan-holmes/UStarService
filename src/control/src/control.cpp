#include <string>
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <math.h>
#include "control/control.h"
#include <boost/foreach.hpp>
#include <geometry_msgs/Twist.h>
#include <serial/serial.h>
namespace UstarController
{
    Controller::Controller(): 
                serial_port_("/dev/ttyUSB0"), serial_baud_(115200), D_(0.2680859f),
                ratio_(1000.0f), linear_temp_(0), angular_temp_(0), publish_period_(0.05),
                data_terminal0_(0x0d), data_terminal1_(0x0a), odom_thread_(NULL)
                
    {
        init();
    }

    Controller::~Controller() 
    {
       
    }
    void Controller::init()
    {
    
        
    }
    void Controller::start()
    {
        odom_pub_ = nh_.advertise<nav_msgs::Odometry>("odom", 1, true);
        vel_sub_ = nh_.subscribe("cmd_vel", 20, &Controller::cmdCallback, this);
        odom_thread_ = new boost::thread(boost::bind(&Controller::publishLoop, this, publish_period_));
    }
    
    
    void Controller::cmdCallback(const geometry_msgs::Twist &cmd_vel)
    {
        serial::Serial my_serial(serial_port_, serial_baud_, serial::Timeout::simpleTimeout(1000));
        unsigned char speed_data[10] = {0};
        angular_temp_ = cmd_vel.angular.z;
        linear_temp_ = cmd_vel.linear.x;
        
        left_speed_data_.d = linear_temp_ - 0.5f * angular_temp_ * D_;
        right_speed_data_.d = linear_temp_ + 0.5f * angular_temp_ * D_;

        left_speed_data_.d *= ratio_;
        right_speed_data_.d *= ratio_;

        for(int i = 0; i < 4; i++)
        {
            speed_data[i] = right_speed_data_.data[i];
            speed_data[i+4] = left_speed_data_.data[i];
        }
        speed_data[8] = data_terminal0_;
        speed_data[9] = data_terminal1_;
        
        my_serial.write(speed_data, 10);
 
    }

    void Controller::publishLoop(double publish_thread)
    {
        if (publish_thread == 0)
            return;

        ros::Rate r(1.0 / publish_thread);
        while (ros::ok())
        {
            odomPublish();
            r.sleep();
        }
    }

    void Controller::odomPublish()
    {
        serial::Serial my_serial(serial_port_, serial_baud_, serial::Timeout::simpleTimeout(1000));
        float covariance[36] = {0.01, 0, 0, 0, 0, 0,  // covariance on gps_x
                                0, 0.01, 0, 0, 0, 0,  // covariance on gps_y
                                0, 0, 99999, 0, 0, 0, // covariance on gps_z
                                0, 0, 0, 99999, 0, 0, // large covariance on rot x
                                0, 0, 0, 0, 99999, 0, // large covariance on rot y
                                0, 0, 0, 0, 0, 0.01}; // large covariance on rot z
        for (int i = 0; i < 36; i++)
        {
            odom_.pose.covariance[i] = covariance[i];
        }
        rec_buffer_ = my_serial.readline(25, "\n");
        const char *receive_data = rec_buffer_.data();
        if (rec_buffer_.length() == 21)
        {
            for (int i = 0; i < 4; i++)
            {
                position_x_.data[i] = receive_data[i];
                position_y_.data[i] = receive_data[i + 4];
                oriention_.data[i] = receive_data[i+8];
                vel_linear_.data[i] = receive_data[i+12];
                vel_angular_.data[i] = receive_data[i+16];
            }
            position_x_.d /= 1000;
            position_y_.d /= 1000;
            vel_linear_.d /= 1000;
            odom_quat_ = tf::createQuaternionMsgFromYaw(oriention_.d);
            
            //载入里程计时间戳
            odom_.header.stamp = ros::Time::now();
            //里程计的父子坐标系
            odom_.header.frame_id = "odom";
            odom_.child_frame_id = "base_footprint";
            //里程计位置数据：x,y,z,方向
            odom_.pose.pose.position.x = position_x_.d;
            odom_.pose.pose.position.y = position_y_.d;
            odom_.pose.pose.position.z = 0.0;
            odom_.pose.pose.orientation = odom_quat_;
            //载入线速度和角速度
            odom_.twist.twist.linear.x = vel_linear_.d;
            //odom.twist.twist.linear.y = odom_vy;
            odom_.twist.twist.angular.z = vel_angular_.d;
            //发布里程计
            odom_pub_.publish(odom_);
            
            tfPublish();
        }

    }

    void Controller::tfPublish()
    {   
        odom_trans_.header.stamp = ros::Time::now();
        odom_trans_.header.frame_id = "odom";
        odom_trans_.child_frame_id = "base_footprint";
        odom_trans_.transform.translation.x = position_x_.d;
        odom_trans_.transform.translation.y = position_y_.d;
        odom_trans_.transform.translation.z = 0.0;
        odom_trans_.transform.rotation = odom_quat_;
        odom_broadcaster_.sendTransform(odom_trans_);
    }

}