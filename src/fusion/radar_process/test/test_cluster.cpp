
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include "radar_process/kd_tree.h"




	


void Callback(const sensor_msgs::LaserScan &msg)
{
	ROS_INFO_STREAM("====Callback()====");

	int num_ranges = msg.ranges.size();

	double *ranges_double = new double[num_ranges];
	double *laser_angles = new double[num_ranges];
	double theta = -std::fabs(msg.angle_min - msg.angle_max) / 2;

	for (int i = 0; i < num_ranges; i++)
	{
		if (msg.ranges[i] < msg.range_min)
			ranges_double[i] = (double)msg.range_max;
		else
			ranges_double[i] = (double)msg.ranges[i];
		laser_angles[i] = theta;
		theta += std::fabs(msg.angle_increment);
	}
	p_vector pose;
	for (int i = 0; i < num_ranges; i++)
	{	
		//pose = p_vector_zero();
		double x = ranges_double[i] * cos(laser_angles[i]);
		double y = ranges_double[i] * sin(laser_angles[i]);
		double d = sqrt(x * x + y * y);
		pose.p[0] = x;
		pose.p[1] = y;
		pose.p[2] = laser_angles[i];
		ROS_INFO_STREAM(pose.p[0]);
		
	}
	

}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "test_cluster_node");
	ros::NodeHandle nh; //定义节点的句柄，实例化节点。
	ros::Subscriber sub = nh.subscribe("scan", 20, Callback);
	
	ros::spin();

	return (0); 
}