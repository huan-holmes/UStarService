cmake_minimum_required(VERSION 3.0.2)
project(planning)

find_package(catkin REQUIRED
  COMPONENTS
    angles
    costmap
    dynamic_reconfigure
    geometry_msgs
    nav_core
    navfn
    nav_msgs
    pluginlib
    roscpp
    tf2_geometry_msgs
    tf2_ros
)
find_package(Eigen3 REQUIRED)




include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)
catkin_python_setup()
generate_dynamic_reconfigure_options(
  cfg/GlobalPlanner.cfg
  cfg/DWAPlanner.cfg
)
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS
    costmap
    dynamic_reconfigure
    geometry_msgs
    nav_core
    navfn
    nav_msgs
    pluginlib
    roscpp
    tf2_ros
)
catkin_package(
    INCLUDE_DIRS include
    LIBRARIES dwa_local_planner
    CATKIN_DEPENDS
        dynamic_reconfigure
        nav_msgs
        pluginlib
        sensor_msgs
        roscpp
        tf2
        tf2_ros
)
add_library(global_planner
  src/planning/global_planner/quadratic_calculator.cpp
  src/planning/global_planner/dijkstra.cpp
  src/planning/global_planner/astar.cpp
  src/planning/global_planner/grid_path.cpp
  src/planning/global_planner/gradient_path.cpp
  src/planning/global_planner/orientation_filter.cpp
  src/planning/global_planner/planner_core.cpp
)
add_dependencies(global_planner ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(global_planner ${catkin_LIBRARIES})

add_executable(global_planner_node
  src/plan_node.cpp
)
add_dependencies(global_planner_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(global_planner_node
global_planner
 
  ${catkin_LIBRARIES}
)

install(TARGETS global_planner
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION})

install(TARGETS global_planner_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  PATTERN ".svn" EXCLUDE)

install(FILES bgp_plugin.xml
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

add_library(dwa_local_planner src/dwa_planner.cpp src/dwa_planner_ros.cpp)
add_dependencies(dwa_local_planner ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(dwa_local_planner ${catkin_LIBRARIES})

install(TARGETS dwa_local_planner
       ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
       LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
       RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
       )

install(FILES blp_plugin.xml
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  PATTERN ".svn" EXCLUDE
)
