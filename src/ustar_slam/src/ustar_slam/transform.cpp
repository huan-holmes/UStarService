#include<ros/ros.h>
#include<tf/transform_broadcaster.h>
#include<transform.h>

UParkSlam::Transform::Transform():
    rate_(10), x_(0), y_(0), z_(0), yaw_(0), pitch_(), roll_(0),
{

}

void UParkSlam::Transform::init(){

}

void UParkSlam::Transform::transformBroadcaster(){
    while(nh_.ok()){
        laser_to_base_ = tf::Transform(tf::createQuaternionFormRPY(roll_, pitch_, yaw_), tf::Vector3(x_, y_, z_));
        tf_broadcaster_.sendTransform(tf::StampTransform(laser_to_base_, ros::Time::now(), "base_link", "base_laser"));
        rate_.sleep();
    }
}