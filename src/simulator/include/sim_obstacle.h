#ifndef _SIM_OBSTACLE_H_
#define _SIM_OBSTACLE_H_

#include <string>
#include <ros/ros.h>
#include <boost/thread.hpp>
#include "visualization_msgs/MarkerArray.h"
#include "nav_msgs/GetMap.h"
#include <boost/shared_ptr.hpp>
#include <geometry_msgs/Pose.h>

namespace Simulation{
    class UstarSimulation{
        public:
            UstarSimulation();
            virtual ~UstarSimulation();
            void run();
            void markerPublish();
            void UpdateMarkerState();
            void mapCallback(const nav_msgs::OccupancyGrid::ConstPtr& msg);

            
        private:
            ros::NodeHandle nh_;
            ros::Publisher markerArr_pub_;
            ros::Subscriber map_sub_;
            ros::Rate r_;

            visualization_msgs::MarkerArray marker_array_;

            geometry_msgs::Pose obstacle_pose_;
            visualization_msgs::Marker *marker_ptr_;
            
            int num_;
            int count_;
            uint32_t shape_;

            int s_xmin_;
            int s_ymin_;
            int s_xmax_;
            int s_ymax_;

            bool got_map_;
            boost::shared_ptr<nav_msgs::OccupancyGrid const> map_ptr_;
            int map_width_;
            int map_height_;
            float map_resolution_;
            geometry_msgs::Pose origin_pose_;    
    };
};
#endif