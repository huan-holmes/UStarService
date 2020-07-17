#include "ros/ros.h"
#include "visualization_msgs/Marker.h"
#include "visualization_msgs/MarkerArray.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "sim_markers_node");
    ros::NodeHandle n;
    ros::Rate r(1);
    ros::Publisher markerArr_pub = n.advertise<visualization_msgs::MarkerArray>("visualization_marker_array", 5);
    visualization_msgs::MarkerArray marker_array;
    uint32_t shape = visualization_msgs::Marker::CUBE;
    int count = 3;
    while (ros::ok())
    {
        marker_array.markers.clear();
        for (int i = 0; i < count; i++)
        {
            visualization_msgs::Marker marker;
            marker.header.frame_id = "/map";
            marker.header.stamp = ros::Time::now();
            marker.ns = "sim_markers_node";
            marker.id = i;
            marker.type = shape;
            marker.action = visualization_msgs::Marker::ADD;

            marker.pose.position.x = -2;
            marker.pose.position.y = -2 + i;
            marker.pose.position.z = 0;
            marker.pose.orientation.x = 0.0;
            marker.pose.orientation.y = 0.0;
            marker.pose.orientation.z = 0.0;
            marker.pose.orientation.w = 1.0;

            marker.scale.x = 0.05;
            marker.scale.y = 0.05;
            marker.scale.z = 0.3;

            marker.color.r = 0.0f;
            marker.color.g = 1.0f;
            marker.color.b = 0.0f;
            marker.color.a = 1.0;

            marker.lifetime = ros::Duration();
            marker_array.markers.push_back(marker);
        }
        markerArr_pub.publish(marker_array);
        r.sleep();
    }
}