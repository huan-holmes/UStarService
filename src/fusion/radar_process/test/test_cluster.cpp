
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include "radar_process/kd_tree.h"
#include "radar_process/cluster.h"


void Callback(const sensor_msgs::LaserScan &msg)
{
	ROS_INFO_STREAM("====Callback()====");

}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "test_cluster_node");
	ros::NodeHandle nh; //定义节点的句柄，实例化节点。
	ros::Subscriber sub = nh.subscribe("scan", 20, Callback);
	
	ros::spin();

	return (0); 
}