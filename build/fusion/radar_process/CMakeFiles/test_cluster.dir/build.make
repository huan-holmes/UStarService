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
include fusion/radar_process/CMakeFiles/test_cluster.dir/depend.make

# Include the progress variables for this target.
include fusion/radar_process/CMakeFiles/test_cluster.dir/progress.make

# Include the compile flags for this target's objects.
include fusion/radar_process/CMakeFiles/test_cluster.dir/flags.make

fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.o: fusion/radar_process/CMakeFiles/test_cluster.dir/flags.make
fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.o: /home/boocax/UstarService/src/fusion/radar_process/src/radar_process/cluster.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boocax/UstarService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.o"
	cd /home/boocax/UstarService/build/fusion/radar_process && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.o   -c /home/boocax/UstarService/src/fusion/radar_process/src/radar_process/cluster.c

fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.i"
	cd /home/boocax/UstarService/build/fusion/radar_process && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/boocax/UstarService/src/fusion/radar_process/src/radar_process/cluster.c > CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.i

fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.s"
	cd /home/boocax/UstarService/build/fusion/radar_process && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/boocax/UstarService/src/fusion/radar_process/src/radar_process/cluster.c -o CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.s

fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.o.requires:

.PHONY : fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.o.requires

fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.o.provides: fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.o.requires
	$(MAKE) -f fusion/radar_process/CMakeFiles/test_cluster.dir/build.make fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.o.provides.build
.PHONY : fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.o.provides

fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.o.provides.build: fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.o


fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.o: fusion/radar_process/CMakeFiles/test_cluster.dir/flags.make
fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.o: /home/boocax/UstarService/src/fusion/radar_process/src/radar_process/kd_tree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boocax/UstarService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.o"
	cd /home/boocax/UstarService/build/fusion/radar_process && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.o   -c /home/boocax/UstarService/src/fusion/radar_process/src/radar_process/kd_tree.c

fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.i"
	cd /home/boocax/UstarService/build/fusion/radar_process && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/boocax/UstarService/src/fusion/radar_process/src/radar_process/kd_tree.c > CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.i

fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.s"
	cd /home/boocax/UstarService/build/fusion/radar_process && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/boocax/UstarService/src/fusion/radar_process/src/radar_process/kd_tree.c -o CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.s

fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.o.requires:

.PHONY : fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.o.requires

fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.o.provides: fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.o.requires
	$(MAKE) -f fusion/radar_process/CMakeFiles/test_cluster.dir/build.make fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.o.provides.build
.PHONY : fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.o.provides

fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.o.provides.build: fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.o


# Object files for target test_cluster
test_cluster_OBJECTS = \
"CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.o" \
"CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.o"

# External object files for target test_cluster
test_cluster_EXTERNAL_OBJECTS =

/home/boocax/UstarService/devel/lib/libtest_cluster.so: fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.o
/home/boocax/UstarService/devel/lib/libtest_cluster.so: fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.o
/home/boocax/UstarService/devel/lib/libtest_cluster.so: fusion/radar_process/CMakeFiles/test_cluster.dir/build.make
/home/boocax/UstarService/devel/lib/libtest_cluster.so: fusion/radar_process/CMakeFiles/test_cluster.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/boocax/UstarService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C shared library /home/boocax/UstarService/devel/lib/libtest_cluster.so"
	cd /home/boocax/UstarService/build/fusion/radar_process && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_cluster.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
fusion/radar_process/CMakeFiles/test_cluster.dir/build: /home/boocax/UstarService/devel/lib/libtest_cluster.so

.PHONY : fusion/radar_process/CMakeFiles/test_cluster.dir/build

fusion/radar_process/CMakeFiles/test_cluster.dir/requires: fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/cluster.c.o.requires
fusion/radar_process/CMakeFiles/test_cluster.dir/requires: fusion/radar_process/CMakeFiles/test_cluster.dir/src/radar_process/kd_tree.c.o.requires

.PHONY : fusion/radar_process/CMakeFiles/test_cluster.dir/requires

fusion/radar_process/CMakeFiles/test_cluster.dir/clean:
	cd /home/boocax/UstarService/build/fusion/radar_process && $(CMAKE_COMMAND) -P CMakeFiles/test_cluster.dir/cmake_clean.cmake
.PHONY : fusion/radar_process/CMakeFiles/test_cluster.dir/clean

fusion/radar_process/CMakeFiles/test_cluster.dir/depend:
	cd /home/boocax/UstarService/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/boocax/UstarService/src /home/boocax/UstarService/src/fusion/radar_process /home/boocax/UstarService/build /home/boocax/UstarService/build/fusion/radar_process /home/boocax/UstarService/build/fusion/radar_process/CMakeFiles/test_cluster.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : fusion/radar_process/CMakeFiles/test_cluster.dir/depend

