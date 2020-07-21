#ifndef USTAR_SIM_NODE_H_
#define USTAR_SIM_NODE_H_

#include<string>
#include <ros/ros.h>
#include "visualization_msgs/MarkerArray.h"

namespace Simulation{
    class UStarSimulation{
        public:
            UStarSimulation();
            virtual ~UStarSimulation();
            void run();
            void markerPublish();
            void UpdateMarkerState();
            
        private:
            ros::NodeHandle nh_;
            ros::Publisher markerArr_pub_;
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