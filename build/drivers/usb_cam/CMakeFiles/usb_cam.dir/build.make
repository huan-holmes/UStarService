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
include drivers/usb_cam/CMakeFiles/usb_cam.dir/depend.make

# Include the progress variables for this target.
include drivers/usb_cam/CMakeFiles/usb_cam.dir/progress.make

# Include the compile flags for this target's objects.
include drivers/usb_cam/CMakeFiles/usb_cam.dir/flags.make

drivers/usb_cam/CMakeFiles/usb_cam.dir/src/usb_cam.cpp.o: drivers/usb_cam/CMakeFiles/usb_cam.dir/flags.make
drivers/usb_cam/CMakeFiles/usb_cam.dir/src/usb_cam.cpp.o: /home/boocax/UstarService/src/drivers/usb_cam/src/usb_cam.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boocax/UstarService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object drivers/usb_cam/CMakeFiles/usb_cam.dir/src/usb_cam.cpp.o"
	cd /home/boocax/UstarService/build/drivers/usb_cam && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/usb_cam.dir/src/usb_cam.cpp.o -c /home/boocax/UstarService/src/drivers/usb_cam/src/usb_cam.cpp

drivers/usb_cam/CMakeFiles/usb_cam.dir/src/usb_cam.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/usb_cam.dir/src/usb_cam.cpp.i"
	cd /home/boocax/UstarService/build/drivers/usb_cam && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/boocax/UstarService/src/drivers/usb_cam/src/usb_cam.cpp > CMakeFiles/usb_cam.dir/src/usb_cam.cpp.i

drivers/usb_cam/CMakeFiles/usb_cam.dir/src/usb_cam.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/usb_cam.dir/src/usb_cam.cpp.s"
	cd /home/boocax/UstarService/build/drivers/usb_cam && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/boocax/UstarService/src/drivers/usb_cam/src/usb_cam.cpp -o CMakeFiles/usb_cam.dir/src/usb_cam.cpp.s

drivers/usb_cam/CMakeFiles/usb_cam.dir/src/usb_cam.cpp.o.requires:

.PHONY : drivers/usb_cam/CMakeFiles/usb_cam.dir/src/usb_cam.cpp.o.requires

drivers/usb_cam/CMakeFiles/usb_cam.dir/src/usb_cam.cpp.o.provides: drivers/usb_cam/CMakeFiles/usb_cam.dir/src/usb_cam.cpp.o.requires
	$(MAKE) -f drivers/usb_cam/CMakeFiles/usb_cam.dir/build.make drivers/usb_cam/CMakeFiles/usb_cam.dir/src/usb_cam.cpp.o.provides.build
.PHONY : drivers/usb_cam/CMakeFiles/usb_cam.dir/src/usb_cam.cpp.o.provides

drivers/usb_cam/CMakeFiles/usb_cam.dir/src/usb_cam.cpp.o.provides.build: drivers/usb_cam/CMakeFiles/usb_cam.dir/src/usb_cam.cpp.o


# Object files for target usb_cam
usb_cam_OBJECTS = \
"CMakeFiles/usb_cam.dir/src/usb_cam.cpp.o"

# External object files for target usb_cam
usb_cam_EXTERNAL_OBJECTS =

/home/boocax/UstarService/devel/lib/libusb_cam.so: drivers/usb_cam/CMakeFiles/usb_cam.dir/src/usb_cam.cpp.o
/home/boocax/UstarService/devel/lib/libusb_cam.so: drivers/usb_cam/CMakeFiles/usb_cam.dir/build.make
/home/boocax/UstarService/devel/lib/libusb_cam.so: /opt/ros/kinetic/lib/libimage_transport.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /opt/ros/kinetic/lib/libmessage_filters.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /opt/ros/kinetic/lib/libclass_loader.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /usr/lib/libPocoFoundation.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /usr/lib/x86_64-linux-gnu/libdl.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /opt/ros/kinetic/lib/libroslib.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /opt/ros/kinetic/lib/librospack.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /usr/lib/x86_64-linux-gnu/libpython2.7.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /usr/lib/x86_64-linux-gnu/libtinyxml.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /opt/ros/kinetic/lib/libcamera_info_manager.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /opt/ros/kinetic/lib/libcamera_calibration_parsers.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /opt/ros/kinetic/lib/libroscpp.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /opt/ros/kinetic/lib/librosconsole.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /opt/ros/kinetic/lib/librostime.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /opt/ros/kinetic/lib/libcpp_common.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/boocax/UstarService/devel/lib/libusb_cam.so: drivers/usb_cam/CMakeFiles/usb_cam.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/boocax/UstarService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /home/boocax/UstarService/devel/lib/libusb_cam.so"
	cd /home/boocax/UstarService/build/drivers/usb_cam && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/usb_cam.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
drivers/usb_cam/CMakeFiles/usb_cam.dir/build: /home/boocax/UstarService/devel/lib/libusb_cam.so

.PHONY : drivers/usb_cam/CMakeFiles/usb_cam.dir/build

drivers/usb_cam/CMakeFiles/usb_cam.dir/requires: drivers/usb_cam/CMakeFiles/usb_cam.dir/src/usb_cam.cpp.o.requires

.PHONY : drivers/usb_cam/CMakeFiles/usb_cam.dir/requires

drivers/usb_cam/CMakeFiles/usb_cam.dir/clean:
	cd /home/boocax/UstarService/build/drivers/usb_cam && $(CMAKE_COMMAND) -P CMakeFiles/usb_cam.dir/cmake_clean.cmake
.PHONY : drivers/usb_cam/CMakeFiles/usb_cam.dir/clean

drivers/usb_cam/CMakeFiles/usb_cam.dir/depend:
	cd /home/boocax/UstarService/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/boocax/UstarService/src /home/boocax/UstarService/src/drivers/usb_cam /home/boocax/UstarService/build /home/boocax/UstarService/build/drivers/usb_cam /home/boocax/UstarService/build/drivers/usb_cam/CMakeFiles/usb_cam.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : drivers/usb_cam/CMakeFiles/usb_cam.dir/depend
