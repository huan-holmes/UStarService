#ifndef MARKERS_NODE_H_
#define MARKERS_NODE_H_

#include<string>
#include <ros/ros.h>
#include "visualization_msgs/MarkerArray.h"

namespace UStarSlam{
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

            int maxX_;
            int maxY_;
            
    };
};
#endif