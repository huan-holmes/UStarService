cmake_minimum_required(VERSION 3.0.2)
project(costmap)


find_package(catkin REQUIRED
        COMPONENTS
            cmake_modules
            dynamic_reconfigure
            geometry_msgs
            laser_geometry
            map_msgs
            message_filters
            message_generation
            nav_msgs
            pluginlib
            roscpp
            sensor_msgs
            std_msgs
            tf2
            tf2_geometry_msgs
            tf2_ros
            tf2_sensor_msgs
            visualization_msgs
            voxel_grid
        )
find_package(Eigen3 REQUIRED)
find_package(Boost REQUIRED COMPONENTS system thread)
include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
)
add_definitions(${EIGEN3_DEFINITIONS})


# messages
add_message_files(
    DIRECTORY msg
    FILES
    VoxelGrid.msg
)

generate_messages(
    DEPENDENCIES
        std_msgs
        geometry_msgs
        map_msgs
)

# dynamic reconfigure
generate_dynamic_reconfigure_options(
  cfg/Costmap2D.cfg
  cfg/ObstaclePlugin.cfg
  cfg/GenericPlugin.cfg
  cfg/InflationPlugin.cfg
  cfg/VoxelPlugin.cfg
)





catkin_package(
    INCLUDE_DIRS
        include
        ${EIGEN3_INCLUDE_DIRS}
    LIBRARIES costmap layers
    CATKIN_DEPENDS
        dynamic_reconfigure
        geometry_msgs
        laser_geometry
        map_msgs
        message_filters
        message_runtime
        nav_msgs
        pluginlib
        roscpp
        sensor_msgs
        std_msgs
        tf2_ros
        visualization_msgs
        voxel_grid
    DEPENDS
        EIGEN3
        Boost
)

add_library(costmap
  src/costmap/utils/array_parser.cpp
  src/costmap/costmap_2d/costmap_2d.cpp
  src/costmap/utils/observation_buffer.cpp
  src/costmap/layers/layer.cpp
  src/costmap/costmap_ros/layered_costmap.cpp
  src/costmap/costmap_ros/costmap_2d_ros.cpp
  src/costmap/costmap_ros/costmap_2d_publisher.cpp
  src/costmap/utils/costmap_math.cpp
  src/costmap/utils/footprint.cpp
  src/costmap/layers/costmap_layer.cpp
)
add_dependencies(costmap ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(costmap
  ${Boost_LIBRARIES}
  ${catkin_LIBRARIES}
)

add_library(layers
  src/costmap/plugins/inflation_layer.cpp
  src/costmap/plugins/obstacle_layer.cpp
  src/costmap/plugins/static_layer.cpp
  src/costmap/plugins/voxel_layer.cpp
  src/costmap/utils/observation_buffer.cpp
)
add_dependencies(layers ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(layers
  costmap
)

add_executable(costmap_2d_markers src/costmap_2d_markers.cpp)
add_dependencies(costmap_2d_markers ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(costmap_2d_markers
    costmap
    ${Boost_LIBRARIES}
    ${catkin_LIBRARIES}
)

add_executable(costmap_2d_cloud src/costmap_2d_cloud.cpp)
add_dependencies(costmap_2d_cloud ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(costmap_2d_cloud
    costmap
    ${Boost_LIBRARIES}
    ${catkin_LIBRARIES}
)

add_executable(costmap_2d_node src/costmap_2d_node.cpp)
add_dependencies(costmap_2d_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(costmap_2d_node
    costmap
    ${Boost_LIBRARIES}
    ${catkin_LIBRARIES}
)

