#ifndef LASER_PUBLISHER_H_
#define LASER_PUBLISHER_H_

#include<string>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

namespace UParkSlam{
    class LaserPublisher{
        public:
            LaserPublisher();
            virtual ~LaserPublisher();
            void laserPublisher();
        private:
            ros::NodeHandle nh_;
            ros::Publisher laser_pub_;
            
    }
}
#endif