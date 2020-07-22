#ifndef USTAR_SIM_NODE_H_
#define USTAR_SIM_NODE_H_

#include<string>
#include <ros/ros.h>
#include <boost/thread.hpp>
#include "visualization_msgs/MarkerArray.h"
#include "nav_msgs/GetMap.h"

namespace Simulation{
    class UStarSimulation{
        public:
            UStarSimulation();
            virtual ~UStarSimulation();
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
            
            int num_;
            int count_;
            uint32_t shape_;

            int s_xmin_;
            int s_ymin_;
            int s_xmax_;
            int s_ymax_;
            
    };
};
#endif