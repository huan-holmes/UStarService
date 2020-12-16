cmake_minimum_required(VERSION 3.0.2)
project(lidar_process)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  sensor_msgs
  pcl_conversions
  pcl_ros
  laser_geometry
  jsk_recognition_msgs
)

catkin_package(
  CATKIN_DEPENDS
  sensor_msgs
  INCLUDE_DIRS include
  LIBRARIES lidar_process
  CATKIN_DEPENDS roscpp rospy
  DEPENDS system_lib
)



include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
)




add_library(test_pcl
  src/lidar_process/filter.cpp
  
)
add_library(sensor_fusion
  src/lidar_process/sensor_fusion.cpp
  src/lidar_process/kalman_filter.cpp
)
add_executable(sensor_fusion_node src/lidar_process/sensor_fusion_node.cpp)
target_link_libraries(sensor_fusion_node sensor_fusion ${catkin_LIBRARIES})
add_executable(my_pcl_node test/test_pcl.cpp)
target_link_libraries(my_pcl_node test_pcl ${catkin_LIBRARIES})