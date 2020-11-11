cmake_minimum_required(VERSION 3.0.2)
project(mapping)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED
  std_msgs
  sensor_msgs
  nav_msgs
  tf
  rosbag
)
include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES utils sensor map particlefilter scanmatcher
)
add_library(scanmatcher
  src/gmapping/scanmatcher/matchprocessor.cpp
  src/gmapping/scanmatcher/scanmatcher.new.cpp
  src/gmapping/scanmatcher/motionmodel.cpp
  src/gmapping/scanmatcher/matchprocessor_tree.cpp
)
add_library(sensor
  src/gmapping/sensor/rangesensor.cpp  
  src/gmapping/sensor/odometrysensor.cpp
  src/gmapping/sensor/rangereading.cpp
  src/gmapping/sensor/rangesensor.cpp
  src/gmapping/sensor/sensor.cpp
  src/gmapping/sensor/sensorreading.cpp
)
add_library(utils
  src/gmapping/utils/stat.cpp
)

add_executable(gmapping_node src/gmapping/main.cpp src/gmapping/gmapping.cpp)


add_dependencies(gmapping_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(gmapping_node
  scanmatcher
  sensor
  utils
  ${catkin_LIBRARIES}
)

#############
## Install ##
#############

## Install excutable python script
install(
    PROGRAMS
      scripts/cmd_keyboard_control.py
    DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(TARGETS gmapping_node
   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
 )

## Install project namespaced headers
install(DIRECTORY include/gmapping/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
  PATTERN ".svn" EXCLUDE)

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
install(DIRECTORY rviz
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)