cmake_minimum_required(VERSION 3.0.2)
project(localization)
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 11)
endif()
## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED
  COMPONENTS
    diagnostic_updater
    dynamic_reconfigure
    geometry_msgs
    message_filters
    nav_msgs
    rosbag
    roscpp
    sensor_msgs
    std_srvs
    tf2
    tf2_geometry_msgs
    tf2_msgs
    tf2_ros
)

find_package(Boost REQUIRED)

# dynamic reconfigure
generate_dynamic_reconfigure_options(
    cfg/LOCALIZATION.cfg
)

catkin_package(
  CATKIN_DEPENDS
    diagnostic_updater
    dynamic_reconfigure
    geometry_msgs
    nav_msgs
    rosbag
    roscpp 
    sensor_msgs
    std_srvs
    tf2
    tf2_msgs
    tf2_ros
  INCLUDE_DIRS include
  LIBRARIES sensor map pf
)

include_directories(include)
include_directories(${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
check_include_file(unistd.h HAVE_UNISTD_H)
if (HAVE_UNISTD_H)
  add_definitions(-DHAVE_UNISTD_H)
endif (HAVE_UNISTD_H)

check_symbol_exists(drand48 stdlib.h HAVE_DRAND48)
if (HAVE_DRAND48)
  add_definitions(-DHAVE_DRAND48)
endif (HAVE_DRAND48)
add_library(localization_pf
                    src/localization/pf/pf.c
                    src/localization/pf/pf_kdtree.c
                    src/localization/pf/pf_pdf.c
                    src/localization/pf/pf_vector.c
                    src/localization/pf/eig3.c
                    src/localization/pf/pf_draw.c)

add_library(localization_map
                    src/localization/map/map.c
                    src/localization/map/map_cspace.cpp
                    src/localization/map/map_range.c
                    src/localization/map/map_store.c
                    src/localization/map/map_draw.c)

add_library(localization_sensor
                    src/localization/sensor/sensor.cpp
                    src/localization/sensor/odometrysensor.cpp
                    src/localization/sensor/lasersensor.cpp)
target_link_libraries(localization_sensor localization_map localization_pf)

target_link_libraries(localization_sensor localization_map localization_pf)
add_executable(localization_node src/localization_node.cpp)


add_dependencies(localization_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(localization_node
  localization_sensor localization_map localization_pf
  ${Boost_LIBRARIES}
  ${catkin_LIBRARIES}
)


