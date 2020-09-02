#include <ros/ros.h>
#include "costmap/costmap_ros/costmap_2d_ros.h"
#include <tf2_ros/transform_listener.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "costmap_node");
  tf2_ros::Buffer buffer(ros::Duration(10));
  tf2_ros::TransformListener tf(buffer);
  UstarCostmap::Costmap2DROS lcr("costmap", buffer);

  ros::spin();

  return (0);
}
