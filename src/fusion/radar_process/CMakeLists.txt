cmake_minimum_required(VERSION 3.0.2)
project(radar_process)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  sensor_msgs
)

catkin_package(
  CATKIN_DEPENDS
  sensor_msgs
  INCLUDE_DIRS include
  LIBRARIES radar_process
  CATKIN_DEPENDS roscpp rospy
  DEPENDS system_lib
)



include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(test_cluster 
  src/radar_process/kd_tree.c
  #src/radar_process/cluster.cpp
)
add_executable(test_cluster_node test/test_cluster.cpp)
target_link_libraries(test_cluster_node test_cluster ${catkin_LIBRARIES})