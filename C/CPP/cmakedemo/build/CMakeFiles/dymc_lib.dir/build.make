# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo/build

# Include any dependencies generated for this target.
include CMakeFiles/dymc_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dymc_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dymc_lib.dir/flags.make

CMakeFiles/dymc_lib.dir/src/test_a.c.o: CMakeFiles/dymc_lib.dir/flags.make
CMakeFiles/dymc_lib.dir/src/test_a.c.o: ../src/test_a.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/dymc_lib.dir/src/test_a.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dymc_lib.dir/src/test_a.c.o   -c /home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo/src/test_a.c

CMakeFiles/dymc_lib.dir/src/test_a.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dymc_lib.dir/src/test_a.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo/src/test_a.c > CMakeFiles/dymc_lib.dir/src/test_a.c.i

CMakeFiles/dymc_lib.dir/src/test_a.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dymc_lib.dir/src/test_a.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo/src/test_a.c -o CMakeFiles/dymc_lib.dir/src/test_a.c.s

CMakeFiles/dymc_lib.dir/src/test_b.c.o: CMakeFiles/dymc_lib.dir/flags.make
CMakeFiles/dymc_lib.dir/src/test_b.c.o: ../src/test_b.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/dymc_lib.dir/src/test_b.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dymc_lib.dir/src/test_b.c.o   -c /home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo/src/test_b.c

CMakeFiles/dymc_lib.dir/src/test_b.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dymc_lib.dir/src/test_b.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo/src/test_b.c > CMakeFiles/dymc_lib.dir/src/test_b.c.i

CMakeFiles/dymc_lib.dir/src/test_b.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dymc_lib.dir/src/test_b.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo/src/test_b.c -o CMakeFiles/dymc_lib.dir/src/test_b.c.s

CMakeFiles/dymc_lib.dir/src/test_c.c.o: CMakeFiles/dymc_lib.dir/flags.make
CMakeFiles/dymc_lib.dir/src/test_c.c.o: ../src/test_c.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/dymc_lib.dir/src/test_c.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dymc_lib.dir/src/test_c.c.o   -c /home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo/src/test_c.c

CMakeFiles/dymc_lib.dir/src/test_c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dymc_lib.dir/src/test_c.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo/src/test_c.c > CMakeFiles/dymc_lib.dir/src/test_c.c.i

CMakeFiles/dymc_lib.dir/src/test_c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dymc_lib.dir/src/test_c.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo/src/test_c.c -o CMakeFiles/dymc_lib.dir/src/test_c.c.s

# Object files for target dymc_lib
dymc_lib_OBJECTS = \
"CMakeFiles/dymc_lib.dir/src/test_a.c.o" \
"CMakeFiles/dymc_lib.dir/src/test_b.c.o" \
"CMakeFiles/dymc_lib.dir/src/test_c.c.o"

# External object files for target dymc_lib
dymc_lib_EXTERNAL_OBJECTS =

../lib/libdymc_lib.so: CMakeFiles/dymc_lib.dir/src/test_a.c.o
../lib/libdymc_lib.so: CMakeFiles/dymc_lib.dir/src/test_b.c.o
../lib/libdymc_lib.so: CMakeFiles/dymc_lib.dir/src/test_c.c.o
../lib/libdymc_lib.so: CMakeFiles/dymc_lib.dir/build.make
../lib/libdymc_lib.so: CMakeFiles/dymc_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C shared library ../lib/libdymc_lib.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dymc_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dymc_lib.dir/build: ../lib/libdymc_lib.so

.PHONY : CMakeFiles/dymc_lib.dir/build

CMakeFiles/dymc_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dymc_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dymc_lib.dir/clean

CMakeFiles/dymc_lib.dir/depend:
	cd /home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo /home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo /home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo/build /home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo/build /home/thundersoft/HDD/wood/work/Research/CPP/cmakedemo/build/CMakeFiles/dymc_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dymc_lib.dir/depend
