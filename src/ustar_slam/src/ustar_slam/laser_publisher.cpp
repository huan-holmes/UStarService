#include "laser_publisher.h"
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

UParkSlam::LaserPublisher::laserPublisher() {
    laser_pub_ = nh_.advertise<sensor_msgs::LaserScan>("scan", 10,  true);
    ros::Rate r(10);
    while(nh_.ok())
    {
        sensor_msgs::LaserScan scan;
        scan.header.stmp = ros::Time::now();
        scan.header.frame_id = "laser_link";
        
    }
}