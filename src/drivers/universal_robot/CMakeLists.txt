cmake_minimum_required(VERSION 2.8.3)
project(universal_robot)
#-------------------------------------- 编译器设置 --------------------------------------
set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_BUILD_TYPE Debug)
if(WIN32 AND NOT CYGWIN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
else()
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++11 -fPIC")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -std=c++11 -fPIC -rdynamic")
    endif()
endif()
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  nav_msgs
  tf
  dynamic_reconfigure
)
 generate_dynamic_reconfigure_options(
   cfg/CmdTest.cfg
 )
catkin_package(
  CATKIN_DEPENDS
  nav_msgs
  tf

)


###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include ${catkin_INCLUDE_DIRS}
)
add_library(${PROJECT_NAME}_lib
    ${SOURCE_FILES}
    )
target_link_libraries(${PROJECT_NAME}_lib ${catkin_LIBRARIES})

add_executable(universal_robot
  ${SOURCE_FILES}
  main.cpp

)
add_dependencies(universal_robot ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(universal_robot
  ${catkin_LIBRARIES}
  #${CMAKE_CURRENT_SOURCE_DIR}/lib${PROJECT_NAME}_lib.so

)
add_executable(cmd_test_node test/cmd_test.cpp)
target_link_libraries(cmd_test_node ${catkin_LIBRARIES})
#-------------------------------------- -安装项目---------------------------------------
install( TARGETS
universal_robot  ${PROJECT_NAME}_lib
ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
DESTINATION "${CMAKE_INSTALL_PREFIX}" COMPONENT header)

install(DIRECTORY launch/
DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch)
