# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/mingo/UStarService/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mingo/UStarService/build

# Include any dependencies generated for this target.
include openslam_gmapping/CMakeFiles/scanmatch_test.dir/depend.make

# Include the progress variables for this target.
include openslam_gmapping/CMakeFiles/scanmatch_test.dir/progress.make

# Include the compile flags for this target's objects.
include openslam_gmapping/CMakeFiles/scanmatch_test.dir/flags.make

openslam_gmapping/CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.o: openslam_gmapping/CMakeFiles/scanmatch_test.dir/flags.make
openslam_gmapping/CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.o: /home/mingo/UStarService/src/openslam_gmapping/scanmatcher/scanmatch_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mingo/UStarService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object openslam_gmapping/CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.o"
	cd /home/mingo/UStarService/build/openslam_gmapping && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.o -c /home/mingo/UStarService/src/openslam_gmapping/scanmatcher/scanmatch_test.cpp

openslam_gmapping/CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.i"
	cd /home/mingo/UStarService/build/openslam_gmapping && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mingo/UStarService/src/openslam_gmapping/scanmatcher/scanmatch_test.cpp > CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.i

openslam_gmapping/CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.s"
	cd /home/mingo/UStarService/build/openslam_gmapping && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mingo/UStarService/src/openslam_gmapping/scanmatcher/scanmatch_test.cpp -o CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.s

openslam_gmapping/CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.o.requires:

.PHONY : openslam_gmapping/CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.o.requires

openslam_gmapping/CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.o.provides: openslam_gmapping/CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.o.requires
	$(MAKE) -f openslam_gmapping/CMakeFiles/scanmatch_test.dir/build.make openslam_gmapping/CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.o.provides.build
.PHONY : openslam_gmapping/CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.o.provides

openslam_gmapping/CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.o.provides.build: openslam_gmapping/CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.o


# Object files for target scanmatch_test
scanmatch_test_OBJECTS = \
"CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.o"

# External object files for target scanmatch_test
scanmatch_test_EXTERNAL_OBJECTS =

/home/mingo/UStarService/devel/lib/openslam_gmapping/scanmatch_test: openslam_gmapping/CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.o
/home/mingo/UStarService/devel/lib/openslam_gmapping/scanmatch_test: openslam_gmapping/CMakeFiles/scanmatch_test.dir/build.make
/home/mingo/UStarService/devel/lib/openslam_gmapping/scanmatch_test: /home/mingo/UStarService/devel/lib/libscanmatcher.so
/home/mingo/UStarService/devel/lib/openslam_gmapping/scanmatch_test: /home/mingo/UStarService/devel/lib/liblog.so
/home/mingo/UStarService/devel/lib/openslam_gmapping/scanmatch_test: /home/mingo/UStarService/devel/lib/libsensor_range.so
/home/mingo/UStarService/devel/lib/openslam_gmapping/scanmatch_test: /home/mingo/UStarService/devel/lib/libsensor_odometry.so
/home/mingo/UStarService/devel/lib/openslam_gmapping/scanmatch_test: /home/mingo/UStarService/devel/lib/libsensor_base.so
/home/mingo/UStarService/devel/lib/openslam_gmapping/scanmatch_test: /home/mingo/UStarService/devel/lib/libutils.so
/home/mingo/UStarService/devel/lib/openslam_gmapping/scanmatch_test: openslam_gmapping/CMakeFiles/scanmatch_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mingo/UStarService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/mingo/UStarService/devel/lib/openslam_gmapping/scanmatch_test"
	cd /home/mingo/UStarService/build/openslam_gmapping && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scanmatch_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
openslam_gmapping/CMakeFiles/scanmatch_test.dir/build: /home/mingo/UStarService/devel/lib/openslam_gmapping/scanmatch_test

.PHONY : openslam_gmapping/CMakeFiles/scanmatch_test.dir/build

openslam_gmapping/CMakeFiles/scanmatch_test.dir/requires: openslam_gmapping/CMakeFiles/scanmatch_test.dir/scanmatcher/scanmatch_test.cpp.o.requires

.PHONY : openslam_gmapping/CMakeFiles/scanmatch_test.dir/requires

openslam_gmapping/CMakeFiles/scanmatch_test.dir/clean:
	cd /home/mingo/UStarService/build/openslam_gmapping && $(CMAKE_COMMAND) -P CMakeFiles/scanmatch_test.dir/cmake_clean.cmake
.PHONY : openslam_gmapping/CMakeFiles/scanmatch_test.dir/clean

openslam_gmapping/CMakeFiles/scanmatch_test.dir/depend:
	cd /home/mingo/UStarService/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mingo/UStarService/src /home/mingo/UStarService/src/openslam_gmapping /home/mingo/UStarService/build /home/mingo/UStarService/build/openslam_gmapping /home/mingo/UStarService/build/openslam_gmapping/CMakeFiles/scanmatch_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : openslam_gmapping/CMakeFiles/scanmatch_test.dir/depend

