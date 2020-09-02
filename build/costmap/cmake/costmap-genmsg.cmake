# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "costmap: 1 messages, 0 services")

set(MSG_I_FLAGS "-Icostmap:/home/boocax/UstarService/src/costmap/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg;-Imap_msgs:/opt/ros/kinetic/share/map_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/kinetic/share/sensor_msgs/cmake/../msg;-Inav_msgs:/opt/ros/kinetic/share/nav_msgs/cmake/../msg;-Iactionlib_msgs:/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(costmap_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/boocax/UstarService/src/costmap/msg/VoxelGrid.msg" NAME_WE)
add_custom_target(_costmap_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "costmap" "/home/boocax/UstarService/src/costmap/msg/VoxelGrid.msg" "geometry_msgs/Point32:std_msgs/Header:geometry_msgs/Vector3"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(costmap
  "/home/boocax/UstarService/src/costmap/msg/VoxelGrid.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/costmap
)

### Generating Services

### Generating Module File
_generate_module_cpp(costmap
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/costmap
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(costmap_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(costmap_generate_messages costmap_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/boocax/UstarService/src/costmap/msg/VoxelGrid.msg" NAME_WE)
add_dependencies(costmap_generate_messages_cpp _costmap_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(costmap_gencpp)
add_dependencies(costmap_gencpp costmap_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS costmap_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(costmap
  "/home/boocax/UstarService/src/costmap/msg/VoxelGrid.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/costmap
)

### Generating Services

### Generating Module File
_generate_module_eus(costmap
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/costmap
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(costmap_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(costmap_generate_messages costmap_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/boocax/UstarService/src/costmap/msg/VoxelGrid.msg" NAME_WE)
add_dependencies(costmap_generate_messages_eus _costmap_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(costmap_geneus)
add_dependencies(costmap_geneus costmap_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS costmap_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(costmap
  "/home/boocax/UstarService/src/costmap/msg/VoxelGrid.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/costmap
)

### Generating Services

### Generating Module File
_generate_module_lisp(costmap
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/costmap
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(costmap_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(costmap_generate_messages costmap_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/boocax/UstarService/src/costmap/msg/VoxelGrid.msg" NAME_WE)
add_dependencies(costmap_generate_messages_lisp _costmap_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(costmap_genlisp)
add_dependencies(costmap_genlisp costmap_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS costmap_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(costmap
  "/home/boocax/UstarService/src/costmap/msg/VoxelGrid.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/costmap
)

### Generating Services

### Generating Module File
_generate_module_nodejs(costmap
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/costmap
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(costmap_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(costmap_generate_messages costmap_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/boocax/UstarService/src/costmap/msg/VoxelGrid.msg" NAME_WE)
add_dependencies(costmap_generate_messages_nodejs _costmap_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(costmap_gennodejs)
add_dependencies(costmap_gennodejs costmap_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS costmap_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(costmap
  "/home/boocax/UstarService/src/costmap/msg/VoxelGrid.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/costmap
)

### Generating Services

### Generating Module File
_generate_module_py(costmap
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/costmap
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(costmap_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(costmap_generate_messages costmap_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/boocax/UstarService/src/costmap/msg/VoxelGrid.msg" NAME_WE)
add_dependencies(costmap_generate_messages_py _costmap_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(costmap_genpy)
add_dependencies(costmap_genpy costmap_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS costmap_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/costmap)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/costmap
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(costmap_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(costmap_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET map_msgs_generate_messages_cpp)
  add_dependencies(costmap_generate_messages_cpp map_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/costmap)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/costmap
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(costmap_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(costmap_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET map_msgs_generate_messages_eus)
  add_dependencies(costmap_generate_messages_eus map_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/costmap)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/costmap
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(costmap_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(costmap_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET map_msgs_generate_messages_lisp)
  add_dependencies(costmap_generate_messages_lisp map_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/costmap)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/costmap
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(costmap_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(costmap_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET map_msgs_generate_messages_nodejs)
  add_dependencies(costmap_generate_messages_nodejs map_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/costmap)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/costmap\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/costmap
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(costmap_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(costmap_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET map_msgs_generate_messages_py)
  add_dependencies(costmap_generate_messages_py map_msgs_generate_messages_py)
endif()
