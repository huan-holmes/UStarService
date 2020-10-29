#include <ros/ros.h>

#include "sim_obstacle.h"

#include "visualization_msgs/Marker.h"
#include "visualization_msgs/MarkerArray.h"
#include "nav_msgs/GetMap.h"
#include <boost/foreach.hpp>

#define MAP_IDX(sx, i, j) ((sx) * (j) + (i))

using namespace Simulation;

UstarSimulation::UstarSimulation() : s_xmin_(-100), s_ymin_(-100), s_xmax_(100), s_ymax_(100), marker_ptr_(NULL),
                                     count_(0), r_(1), num_(3), shape_(visualization_msgs::Marker::CUBE), got_map_(false)
{
} 

UstarSimulation::~UstarSimulation()
{
}

void UstarSimulation::run()
{
    markerArr_pub_ = nh_.advertise<visualization_msgs::MarkerArray>("visualization_marker_array", 5);
    map_sub_ = nh_.subscribe("map", 10, &UstarSimulation::mapCallback, this);
    markerPublish();
}

void UstarSimulation::markerPublish()
{
    // if (count_ == num_)
    // {
    //     //UpdateMarkerState();
    //     return;
    //     // continue;
    // }
    marker_array_.markers.clear();
    for (int i = 0; i < num_; i++)
    {
        count_++;
        visualization_msgs::Marker marker;
        marker.header.frame_id = "map";
        marker.header.stamp = ros::Time::now();
        marker.ns = "sim_obstacle_node";
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
        

        marker.scale.x = 0.5;
        marker.scale.y = 0.5;
        marker.scale.z = 1.5;

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

void UstarSimulation::UpdateMarkerState()
{
    for (size_t i = 0; i < marker_array_.markers.size(); i++)
    {
        marker_ptr_ = &marker_array_.markers[i];
        obstacle_pose_ = marker_array_.markers[i].pose;
        int cell_x;
        int cell_y;
        int occ;
        obstacle_pose_.position.x += rand()%10000/10000.0;
        obstacle_pose_.position.y += rand()%10000/10000.0;
        cell_x = int((obstacle_pose_.position.x - origin_pose_.position.x) / map_resolution_);
        cell_y = int((obstacle_pose_.position.y - origin_pose_.position.y) / map_resolution_);
        occ = round(map_ptr_->data[MAP_IDX(map_width_, cell_x, cell_y)]);
        while (occ != 0)
        {
            obstacle_pose_.position.x -= 1.0;
            obstacle_pose_.position.y -= 0.5;
            cell_x = int((obstacle_pose_.position.x - origin_pose_.position.x) / map_resolution_);
            cell_y = int((obstacle_pose_.position.y - origin_pose_.position.y) / map_resolution_);
            occ = round(map_ptr_->data[MAP_IDX(map_width_, cell_x, cell_y)]);
        }
        marker_ptr_->pose = obstacle_pose_;
    }
    markerArr_pub_.publish(marker_array_);
    r_.sleep();
}
void UstarSimulation::mapCallback(const nav_msgs::OccupancyGrid::ConstPtr &msg)
{

    if (got_map_)
    {

        return;
    }
    map_ptr_ = msg;
    map_width_ = msg->info.width;
    map_height_ = msg->info.height;
    map_resolution_ = msg->info.resolution;
    origin_pose_ = msg->info.origin;
    got_map_ = true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "sim_obstacle_node");

    Simulation::UstarSimulation uss;

    while (ros::ok())
    {
        uss.run();
        ros::spinOnce();
    }
    return (0);
}
