#include "ustar_sim_node.h"

#include "ros/ros.h"
#include "visualization_msgs/Marker.h"
#include "visualization_msgs/MarkerArray.h"

namespace Simulation
{
    UStarSimulation::UStarSimulation() : count_(0), r_(1), num_(3), shape_(visualization_msgs::Marker::CUBE)
    {
    }

    UStarSimulation::~UStarSimulation()
    {
    }

    void UStarSimulation::run()
    {
        markerArr_pub_ = nh_.advertise<visualization_msgs::MarkerArray>("visualization_marker_array", 5);
        markerPublish();
    }

    void UStarSimulation::markerPublish()
    {
        while (ros::ok())
        {
            if (count_ == num_){
                UpdateMarkerState();
                continue;
            }
            //marker_array_.markers.clear();
            for (int i = 0; i < num_; i++)
            {
                count_++;
                visualization_msgs::Marker marker;
                marker.header.frame_id = "/map";
                marker.header.stamp = ros::Time::now();
                marker.ns = "ustar_sim_node";
                marker.id = i;
                marker.type = shape_;
                marker.action = visualization_msgs::Marker::ADD;

                marker.pose.position.x = 2;
                marker.pose.position.y = 2 + i;
                marker.pose.position.z = 0;
                marker.pose.orientation.x = 0.0;
                marker.pose.orientation.y = 0.0;
                marker.pose.orientation.z = 0.0;
                marker.pose.orientation.w = 1.0;

                marker.scale.x = 0.15;
                marker.scale.y = 0.15;
                marker.scale.z = 1.0;

                marker.color.r = 0.0f;
                marker.color.g = 1.0f;
                marker.color.b = 0.0f;
                marker.color.a = 1.0;

                marker.lifetime = ros::Duration();
                marker_array_.markers.push_back(marker);
            }
           markerArr_pub_.publish(marker_array_);
            r_.sleep();
        }
    }

    void UStarSimulation::UpdateMarkerState()
    {
        visualization_msgs::Marker *marker;
        marker = &marker_array_.markers[0];
        marker->pose.position.x += 0.05; 
        markerArr_pub_.publish(marker_array_);
        r_.sleep();
    }
}; // namespace UStarSlam