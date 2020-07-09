#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include<ros/ros.h>
#include<tf/transform_broadcaster.h>
#include<tf/transform_listener.h>
#include<geometry_msgs/PointStamped.h>

namespace UParkSlam{
    class Transform{
        public:
            Transform();
            virtual ~Transform();
            void init();
            void transformBroadcaster();
        private:
            ros::NodeHandle nh_;
            ros::Rate rate_;
            tf::Transform laser_to_base_;
            tf::TransformBroadcaster tf_braocaster_;
            tf::TransformListener tf_listener_;
            


            double x_;
            double y_;
            double z_;
            double yaw_;
            double pitch_;
            double roll_;
         }
}

#endif