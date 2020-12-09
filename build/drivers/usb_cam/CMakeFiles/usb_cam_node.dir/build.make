# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/boocax/UstarService/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/boocax/UstarService/build

# Include any dependencies generated for this target.
include drivers/usb_cam/CMakeFiles/usb_cam_node.dir/depend.make

# Include the progress variables for this target.
include drivers/usb_cam/CMakeFiles/usb_cam_node.dir/progress.make

# Include the compile flags for this target's objects.
include drivers/usb_cam/CMakeFiles/usb_cam_node.dir/flags.make

drivers/usb_cam/CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.o: drivers/usb_cam/CMakeFiles/usb_cam_node.dir/flags.make
drivers/usb_cam/CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.o: /home/boocax/UstarService/src/drivers/usb_cam/nodes/usb_cam_node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boocax/UstarService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object drivers/usb_cam/CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.o"
	cd /home/boocax/UstarService/build/drivers/usb_cam && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.o -c /home/boocax/UstarService/src/drivers/usb_cam/nodes/usb_cam_node.cpp

drivers/usb_cam/CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.i"
	cd /home/boocax/UstarService/build/drivers/usb_cam && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/boocax/UstarService/src/drivers/usb_cam/nodes/usb_cam_node.cpp > CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.i

drivers/usb_cam/CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.s"
	cd /home/boocax/UstarService/build/drivers/usb_cam && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/boocax/UstarService/src/drivers/usb_cam/nodes/usb_cam_node.cpp -o CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.s

drivers/usb_cam/CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.o.requires:

.PHONY : drivers/usb_cam/CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.o.requires

drivers/usb_cam/CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.o.provides: drivers/usb_cam/CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.o.requires
	$(MAKE) -f drivers/usb_cam/CMakeFiles/usb_cam_node.dir/build.make drivers/usb_cam/CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.o.provides.build
.PHONY : drivers/usb_cam/CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.o.provides

drivers/usb_cam/CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.o.provides.build: drivers/usb_cam/CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.o


# Object files for target usb_cam_node
usb_cam_node_OBJECTS = \
"CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.o"

# External object files for target usb_cam_node
usb_cam_node_EXTERNAL_OBJECTS =

/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: drivers/usb_cam/CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.o
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: drivers/usb_cam/CMakeFiles/usb_cam_node.dir/build.make
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /home/boocax/UstarService/devel/lib/libusb_cam.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /opt/ros/kinetic/lib/libimage_transport.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /opt/ros/kinetic/lib/libmessage_filters.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /opt/ros/kinetic/lib/libclass_loader.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /usr/lib/libPocoFoundation.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /usr/lib/x86_64-linux-gnu/libdl.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /opt/ros/kinetic/lib/libroslib.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /opt/ros/kinetic/lib/librospack.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /usr/lib/x86_64-linux-gnu/libpython2.7.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /usr/lib/x86_64-linux-gnu/libtinyxml.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /opt/ros/kinetic/lib/libcamera_info_manager.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /opt/ros/kinetic/lib/libcamera_calibration_parsers.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /opt/ros/kinetic/lib/libroscpp.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /opt/ros/kinetic/lib/librosconsole.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /opt/ros/kinetic/lib/librostime.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /opt/ros/kinetic/lib/libcpp_common.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node: drivers/usb_cam/CMakeFiles/usb_cam_node.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/boocax/UstarService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node"
	cd /home/boocax/UstarService/build/drivers/usb_cam && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/usb_cam_node.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
drivers/usb_cam/CMakeFiles/usb_cam_node.dir/build: /home/boocax/UstarService/devel/lib/usb_cam/usb_cam_node

.PHONY : drivers/usb_cam/CMakeFiles/usb_cam_node.dir/build

# Object files for target usb_cam_node
usb_cam_node_OBJECTS = \
"CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.o"

# External object files for target usb_cam_node
usb_cam_node_EXTERNAL_OBJECTS =

drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: drivers/usb_cam/CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.o
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: drivers/usb_cam/CMakeFiles/usb_cam_node.dir/build.make
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /home/boocax/UstarService/devel/lib/libusb_cam.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /opt/ros/kinetic/lib/libimage_transport.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /opt/ros/kinetic/lib/libmessage_filters.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /opt/ros/kinetic/lib/libclass_loader.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /usr/lib/libPocoFoundation.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /usr/lib/x86_64-linux-gnu/libdl.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /opt/ros/kinetic/lib/libroslib.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /opt/ros/kinetic/lib/librospack.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /usr/lib/x86_64-linux-gnu/libpython2.7.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /usr/lib/x86_64-linux-gnu/libtinyxml.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /opt/ros/kinetic/lib/libcamera_info_manager.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /opt/ros/kinetic/lib/libcamera_calibration_parsers.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /opt/ros/kinetic/lib/libroscpp.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /usr/lib/x86_64-linux-gnu/libboost_signals.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /opt/ros/kinetic/lib/librosconsole.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /usr/lib/x86_64-linux-gnu/libboost_regex.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /opt/ros/kinetic/lib/libxmlrpcpp.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /opt/ros/kinetic/lib/libroscpp_serialization.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /opt/ros/kinetic/lib/librostime.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /opt/ros/kinetic/lib/libcpp_common.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /usr/lib/x86_64-linux-gnu/libboost_system.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /usr/lib/x86_64-linux-gnu/libboost_thread.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /usr/lib/x86_64-linux-gnu/libpthread.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node: drivers/usb_cam/CMakeFiles/usb_cam_node.dir/relink.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/boocax/UstarService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable CMakeFiles/CMakeRelink.dir/usb_cam_node"
	cd /home/boocax/UstarService/build/drivers/usb_cam && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/usb_cam_node.dir/relink.txt --verbose=$(VERBOSE)

# Rule to relink during preinstall.
drivers/usb_cam/CMakeFiles/usb_cam_node.dir/preinstall: drivers/usb_cam/CMakeFiles/CMakeRelink.dir/usb_cam_node

.PHONY : drivers/usb_cam/CMakeFiles/usb_cam_node.dir/preinstall

drivers/usb_cam/CMakeFiles/usb_cam_node.dir/requires: drivers/usb_cam/CMakeFiles/usb_cam_node.dir/nodes/usb_cam_node.cpp.o.requires

.PHONY : drivers/usb_cam/CMakeFiles/usb_cam_node.dir/requires

drivers/usb_cam/CMakeFiles/usb_cam_node.dir/clean:
	cd /home/boocax/UstarService/build/drivers/usb_cam && $(CMAKE_COMMAND) -P CMakeFiles/usb_cam_node.dir/cmake_clean.cmake
.PHONY : drivers/usb_cam/CMakeFiles/usb_cam_node.dir/clean

drivers/usb_cam/CMakeFiles/usb_cam_node.dir/depend:
	cd /home/boocax/UstarService/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/boocax/UstarService/src /home/boocax/UstarService/src/drivers/usb_cam /home/boocax/UstarService/build /home/boocax/UstarService/build/drivers/usb_cam /home/boocax/UstarService/build/drivers/usb_cam/CMakeFiles/usb_cam_node.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : drivers/usb_cam/CMakeFiles/usb_cam_node.dir/depend

