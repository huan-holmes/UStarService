#include "ustar_sim_node.h"

#include "ros/ros.h"
#include "visualization_msgs/Marker.h"
#include "visualization_msgs/MarkerArray.h"
#include "nav_msgs/GetMap.h"
#include <boost/foreach.hpp>

#define MAP_IDX(sx, i, j) ((sx) * (j) + (i))

namespace Simulation
{
    UStarSimulation::UStarSimulation() : s_xmin_(-100), s_ymin_(-100), s_xmax_(100), s_ymax_(100),
                                         count_(0), r_(1), num_(3), shape_(visualization_msgs::Marker::CUBE), got_map_(false)
    {
    }

    UStarSimulation::~UStarSimulation()
    {
    }

    void UStarSimulation::run()
    {
        markerArr_pub_ = nh_.advertise<visualization_msgs::MarkerArray>("visualization_marker_array", 5);
        map_sub_ = nh_.subscribe("map", 10, &UStarSimulation::mapCallback, this);
        markerPublish();
    }

    void UStarSimulation::markerPublish()
    {

        if (count_ == num_)
        {
            UpdateMarkerState();
            return;
            // continue;
        }
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

    void UStarSimulation::UpdateMarkerState()
    {

        for (size_t i = 0; i < marker_array_.markers.size(); i++)
        {
            visualization_msgs::Marker *marker_ptr;
            marker_ptr = &marker_array_.markers[i];
            int cell_x;
            int cell_y;
            int occ;
            if (i == 0)
            {
                marker_ptr->pose.position.x += 0.5;
                cell_x = int((marker_ptr->pose.position.x - origin_pose_.position.x) / map_resolution_);
                cell_y = int((marker_ptr->pose.position.y - origin_pose_.position.y) / map_resolution_);
                occ = round(map_ptr_->data[MAP_IDX(map_width_, cell_x, cell_y)]);
                while (occ != -1)
                {
                    marker_ptr->pose.position.x -= 1.0;
                    marker_ptr->pose.position.y -= 0.5;
                    cell_x = int((marker_ptr->pose.position.x - origin_pose_.position.x) / map_resolution_);
                    cell_y = int((marker_ptr->pose.position.y - origin_pose_.position.y) / map_resolution_);
                    occ = round(map_ptr_->data[MAP_IDX(map_width_, cell_x, cell_y)]);
                }
            }
            if (i == 1)
            {
                marker_ptr->pose.position.y += 0.5;
                cell_x = int((marker_ptr->pose.position.x - origin_pose_.position.x) / map_resolution_);
                cell_y = int((marker_ptr->pose.position.y - origin_pose_.position.y) / map_resolution_);
                occ = round(map_ptr_->data[MAP_IDX(map_width_, cell_x, cell_y)]);
                while (occ != -1)
                {
                    marker_ptr->pose.position.x += 0.5;
                    marker_ptr->pose.position.y -= 1.0;
                    cell_x = int((marker_ptr->pose.position.x - origin_pose_.position.x) / map_resolution_);
                    cell_y = int((marker_ptr->pose.position.y - origin_pose_.position.y) / map_resolution_);
                    occ = round(map_ptr_->data[MAP_IDX(map_width_, cell_x, cell_y)]);
                }
            }
            if (i == 2)
            {
                marker_ptr->pose.position.y -= 0.5;
                cell_x = int((marker_ptr->pose.position.x - origin_pose_.position.x) / map_resolution_);
                cell_y = int((marker_ptr->pose.position.y - origin_pose_.position.y) / map_resolution_);
                occ = round(map_ptr_->data[MAP_IDX(map_width_, cell_x, cell_y)]);
                while (occ != -1)
                {
                    marker_ptr->pose.position.x -= 0.5;
                    marker_ptr->pose.position.y += 0.5;
                    cell_x = int((marker_ptr->pose.position.x - origin_pose_.position.x) / map_resolution_);
                    cell_y = int((marker_ptr->pose.position.y - origin_pose_.position.y) / map_resolution_);
                    occ = round(map_ptr_->data[MAP_IDX(map_width_, cell_x, cell_y)]);
                }
            }
            //delete marker_ptr;
        }
            markerArr_pub_.publish(marker_array_);
            r_.sleep();
        }
        void UStarSimulation::mapCallback(const nav_msgs::OccupancyGrid::ConstPtr &msg)
        {

            if (got_map_)
            {

                return;
            }
            ROS_INFO_STREAM("----mapCallback()----");
            map_ptr_ = msg;
            map_width_ = msg->info.width;
            map_height_ = msg->info.height;
            map_resolution_ = msg->info.resolution;
            origin_pose_ = msg->info.origin;
            got_map_ = true;
        }
    }; // namespace Simulation