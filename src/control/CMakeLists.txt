cmake_minimum_required(VERSION 3.0.2)
project(control)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
  serial
  tf
  nav_msgs
)
catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES base_controller
  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${serial_INCLUDE_DIRS}
)
add_executable(controller src/main.cpp src/control.cpp)
target_link_libraries(controller ${catkin_LIBRARIES})