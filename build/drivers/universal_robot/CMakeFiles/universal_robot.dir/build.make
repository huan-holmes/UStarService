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
include drivers/universal_robot/CMakeFiles/universal_robot.dir/depend.make

# Include the progress variables for this target.
include drivers/universal_robot/CMakeFiles/universal_robot.dir/progress.make

# Include the compile flags for this target's objects.
include drivers/universal_robot/CMakeFiles/universal_robot.dir/flags.make

drivers/universal_robot/CMakeFiles/universal_robot.dir/src/universal_driver.cpp.o: drivers/universal_robot/CMakeFiles/universal_robot.dir/flags.make
drivers/universal_robot/CMakeFiles/universal_robot.dir/src/universal_driver.cpp.o: /home/boocax/UstarService/src/drivers/universal_robot/src/universal_driver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boocax/UstarService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object drivers/universal_robot/CMakeFiles/universal_robot.dir/src/universal_driver.cpp.o"
	cd /home/boocax/UstarService/build/drivers/universal_robot && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/universal_robot.dir/src/universal_driver.cpp.o -c /home/boocax/UstarService/src/drivers/universal_robot/src/universal_driver.cpp

drivers/universal_robot/CMakeFiles/universal_robot.dir/src/universal_driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/universal_robot.dir/src/universal_driver.cpp.i"
	cd /home/boocax/UstarService/build/drivers/universal_robot && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/boocax/UstarService/src/drivers/universal_robot/src/universal_driver.cpp > CMakeFiles/universal_robot.dir/src/universal_driver.cpp.i

drivers/universal_robot/CMakeFiles/universal_robot.dir/src/universal_driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/universal_robot.dir/src/universal_driver.cpp.s"
	cd /home/boocax/UstarService/build/drivers/universal_robot && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/boocax/UstarService/src/drivers/universal_robot/src/universal_driver.cpp -o CMakeFiles/universal_robot.dir/src/universal_driver.cpp.s

drivers/universal_robot/CMakeFiles/universal_robot.dir/src/universal_driver.cpp.o.requires:

.PHONY : drivers/universal_robot/CMakeFiles/universal_robot.dir/src/universal_driver.cpp.o.requires

drivers/universal_robot/CMakeFiles/universal_robot.dir/src/universal_driver.cpp.o.provides: drivers/universal_robot/CMakeFiles/universal_robot.dir/src/universal_driver.cpp.o.requires
	$(MAKE) -f drivers/universal_robot/CMakeFiles/universal_robot.dir/build.make drivers/universal_robot/CMakeFiles/universal_robot.dir/src/universal_driver.cpp.o.provides.build
.PHONY : drivers/universal_robot/CMakeFiles/universal_robot.dir/src/universal_driver.cpp.o.provides

drivers/universal_robot/CMakeFiles/universal_robot.dir/src/universal_driver.cpp.o.provides.build: drivers/universal_robot/CMakeFiles/universal_robot.dir/src/universal_driver.cpp.o


drivers/universal_robot/CMakeFiles/universal_robot.dir/main.cpp.o: drivers/universal_robot/CMakeFiles/universal_robot.dir/flags.make
drivers/universal_robot/CMakeFiles/universal_robot.dir/main.cpp.o: /home/boocax/UstarService/src/drivers/universal_robot/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boocax/UstarService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object drivers/universal_robot/CMakeFiles/universal_robot.dir/main.cpp.o"
	cd /home/boocax/UstarService/build/drivers/universal_robot && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/universal_robot.dir/main.cpp.o -c /home/boocax/UstarService/src/drivers/universal_robot/main.cpp

drivers/universal_robot/CMakeFiles/universal_robot.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/universal_robot.dir/main.cpp.i"
	cd /home/boocax/UstarService/build/drivers/universal_robot && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/boocax/UstarService/src/drivers/universal_robot/main.cpp > CMakeFiles/universal_robot.dir/main.cpp.i

drivers/universal_robot/CMakeFiles/universal_robot.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/universal_robot.dir/main.cpp.s"
	cd /home/boocax/UstarService/build/drivers/universal_robot && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/boocax/UstarService/src/drivers/universal_robot/main.cpp -o CMakeFiles/universal_robot.dir/main.cpp.s

drivers/universal_robot/CMakeFiles/universal_robot.dir/main.cpp.o.requires:

.PHONY : drivers/universal_robot/CMakeFiles/universal_robot.dir/main.cpp.o.requires

drivers/universal_robot/CMakeFiles/universal_robot.dir/main.cpp.o.provides: drivers/universal_robot/CMakeFiles/universal_robot.dir/main.cpp.o.requires
	$(MAKE) -f drivers/universal_robot/CMakeFiles/universal_robot.dir/build.make drivers/universal_robot/CMakeFiles/universal_robot.dir/main.cpp.o.provides.build
.PHONY : drivers/universal_robot/CMakeFiles/universal_robot.dir/main.cpp.o.provides

drivers/universal_robot/CMakeFiles/universal_robot.dir/main.cpp.o.provides.build: drivers/universal_robot/CMakeFiles/universal_robot.dir/main.cpp.o


# Object files for target universal_robot
universal_robot_OBJECTS = \
"CMakeFiles/universal_robot.dir/src/universal_driver.cpp.o" \
"CMakeFiles/universal_robot.dir/main.cpp.o"

# External object files for target universal_robot
universal_robot_EXTERNAL_OBJECTS =

/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: drivers/universal_robot/CMakeFiles/universal_robot.dir/src/universal_driver.cpp.o
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: drivers/universal_robot/CMakeFiles/universal_robot.dir/main.cpp.o
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: drivers/universal_robot/CMakeFiles/universal_robot.dir/build.make
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /opt/ros/kinetic/lib/libtf.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /opt/ros/kinetic/lib/libtf2_ros.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /opt/ros/kinetic/lib/libactionlib.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /opt/ros/kinetic/lib/libmessage_filters.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /opt/ros/kinetic/lib/libroscpp.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /opt/ros/kinetic/lib/libtf2.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /opt/ros/kinetic/lib/librosconsole.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /opt/ros/kinetic/lib/libdynamic_reconfigure_config_init_mutex.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /opt/ros/kinetic/lib/librostime.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /opt/ros/kinetic/lib/libcpp_common.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/boocax/UstarService/devel/lib/universal_robot/universal_robot: drivers/universal_robot/CMakeFiles/universal_robot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/boocax/UstarService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable /home/boocax/UstarService/devel/lib/universal_robot/universal_robot"
	cd /home/boocax/UstarService/build/drivers/universal_robot && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/universal_robot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
drivers/universal_robot/CMakeFiles/universal_robot.dir/build: /home/boocax/UstarService/devel/lib/universal_robot/universal_robot

.PHONY : drivers/universal_robot/CMakeFiles/universal_robot.dir/build

# Object files for target universal_robot
universal_robot_OBJECTS = \
"CMakeFiles/universal_robot.dir/src/universal_driver.cpp.o" \
"CMakeFiles/universal_robot.dir/main.cpp.o"

# External object files for target universal_robot
universal_robot_EXTERNAL_OBJECTS =

drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: drivers/universal_robot/CMakeFiles/universal_robot.dir/src/universal_driver.cpp.o
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: drivers/universal_robot/CMakeFiles/universal_robot.dir/main.cpp.o
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: drivers/universal_robot/CMakeFiles/universal_robot.dir/build.make
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /opt/ros/kinetic/lib/libtf.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /opt/ros/kinetic/lib/libtf2_ros.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /opt/ros/kinetic/lib/libactionlib.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /opt/ros/kinetic/lib/libmessage_filters.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /opt/ros/kinetic/lib/libroscpp.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /usr/lib/x86_64-linux-gnu/libboost_signals.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /opt/ros/kinetic/lib/libxmlrpcpp.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /opt/ros/kinetic/lib/libtf2.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /opt/ros/kinetic/lib/librosconsole.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /usr/lib/x86_64-linux-gnu/libboost_regex.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /opt/ros/kinetic/lib/libdynamic_reconfigure_config_init_mutex.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /opt/ros/kinetic/lib/libroscpp_serialization.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /opt/ros/kinetic/lib/librostime.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /opt/ros/kinetic/lib/libcpp_common.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /usr/lib/x86_64-linux-gnu/libboost_system.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /usr/lib/x86_64-linux-gnu/libboost_thread.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /usr/lib/x86_64-linux-gnu/libpthread.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot: drivers/universal_robot/CMakeFiles/universal_robot.dir/relink.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/boocax/UstarService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable CMakeFiles/CMakeRelink.dir/universal_robot"
	cd /home/boocax/UstarService/build/drivers/universal_robot && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/universal_robot.dir/relink.txt --verbose=$(VERBOSE)

# Rule to relink during preinstall.
drivers/universal_robot/CMakeFiles/universal_robot.dir/preinstall: drivers/universal_robot/CMakeFiles/CMakeRelink.dir/universal_robot

.PHONY : drivers/universal_robot/CMakeFiles/universal_robot.dir/preinstall

drivers/universal_robot/CMakeFiles/universal_robot.dir/requires: drivers/universal_robot/CMakeFiles/universal_robot.dir/src/universal_driver.cpp.o.requires
drivers/universal_robot/CMakeFiles/universal_robot.dir/requires: drivers/universal_robot/CMakeFiles/universal_robot.dir/main.cpp.o.requires

.PHONY : drivers/universal_robot/CMakeFiles/universal_robot.dir/requires

drivers/universal_robot/CMakeFiles/universal_robot.dir/clean:
	cd /home/boocax/UstarService/build/drivers/universal_robot && $(CMAKE_COMMAND) -P CMakeFiles/universal_robot.dir/cmake_clean.cmake
.PHONY : drivers/universal_robot/CMakeFiles/universal_robot.dir/clean

drivers/universal_robot/CMakeFiles/universal_robot.dir/depend:
	cd /home/boocax/UstarService/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/boocax/UstarService/src /home/boocax/UstarService/src/drivers/universal_robot /home/boocax/UstarService/build /home/boocax/UstarService/build/drivers/universal_robot /home/boocax/UstarService/build/drivers/universal_robot/CMakeFiles/universal_robot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : drivers/universal_robot/CMakeFiles/universal_robot.dir/depend

