# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hs/NP_project/verilator_test/DRAMsim3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hs/NP_project/verilator_test/DRAMsim3

# Include any dependencies generated for this target.
include CMakeFiles/dramsim3test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/dramsim3test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/dramsim3test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dramsim3test.dir/flags.make

CMakeFiles/dramsim3test.dir/tests/test_config.cc.o: CMakeFiles/dramsim3test.dir/flags.make
CMakeFiles/dramsim3test.dir/tests/test_config.cc.o: tests/test_config.cc
CMakeFiles/dramsim3test.dir/tests/test_config.cc.o: CMakeFiles/dramsim3test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hs/NP_project/verilator_test/DRAMsim3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dramsim3test.dir/tests/test_config.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dramsim3test.dir/tests/test_config.cc.o -MF CMakeFiles/dramsim3test.dir/tests/test_config.cc.o.d -o CMakeFiles/dramsim3test.dir/tests/test_config.cc.o -c /home/hs/NP_project/verilator_test/DRAMsim3/tests/test_config.cc

CMakeFiles/dramsim3test.dir/tests/test_config.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dramsim3test.dir/tests/test_config.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hs/NP_project/verilator_test/DRAMsim3/tests/test_config.cc > CMakeFiles/dramsim3test.dir/tests/test_config.cc.i

CMakeFiles/dramsim3test.dir/tests/test_config.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dramsim3test.dir/tests/test_config.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hs/NP_project/verilator_test/DRAMsim3/tests/test_config.cc -o CMakeFiles/dramsim3test.dir/tests/test_config.cc.s

CMakeFiles/dramsim3test.dir/tests/test_dramsys.cc.o: CMakeFiles/dramsim3test.dir/flags.make
CMakeFiles/dramsim3test.dir/tests/test_dramsys.cc.o: tests/test_dramsys.cc
CMakeFiles/dramsim3test.dir/tests/test_dramsys.cc.o: CMakeFiles/dramsim3test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hs/NP_project/verilator_test/DRAMsim3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/dramsim3test.dir/tests/test_dramsys.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dramsim3test.dir/tests/test_dramsys.cc.o -MF CMakeFiles/dramsim3test.dir/tests/test_dramsys.cc.o.d -o CMakeFiles/dramsim3test.dir/tests/test_dramsys.cc.o -c /home/hs/NP_project/verilator_test/DRAMsim3/tests/test_dramsys.cc

CMakeFiles/dramsim3test.dir/tests/test_dramsys.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dramsim3test.dir/tests/test_dramsys.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hs/NP_project/verilator_test/DRAMsim3/tests/test_dramsys.cc > CMakeFiles/dramsim3test.dir/tests/test_dramsys.cc.i

CMakeFiles/dramsim3test.dir/tests/test_dramsys.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dramsim3test.dir/tests/test_dramsys.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hs/NP_project/verilator_test/DRAMsim3/tests/test_dramsys.cc -o CMakeFiles/dramsim3test.dir/tests/test_dramsys.cc.s

CMakeFiles/dramsim3test.dir/tests/test_hmcsys.cc.o: CMakeFiles/dramsim3test.dir/flags.make
CMakeFiles/dramsim3test.dir/tests/test_hmcsys.cc.o: tests/test_hmcsys.cc
CMakeFiles/dramsim3test.dir/tests/test_hmcsys.cc.o: CMakeFiles/dramsim3test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hs/NP_project/verilator_test/DRAMsim3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/dramsim3test.dir/tests/test_hmcsys.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dramsim3test.dir/tests/test_hmcsys.cc.o -MF CMakeFiles/dramsim3test.dir/tests/test_hmcsys.cc.o.d -o CMakeFiles/dramsim3test.dir/tests/test_hmcsys.cc.o -c /home/hs/NP_project/verilator_test/DRAMsim3/tests/test_hmcsys.cc

CMakeFiles/dramsim3test.dir/tests/test_hmcsys.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dramsim3test.dir/tests/test_hmcsys.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hs/NP_project/verilator_test/DRAMsim3/tests/test_hmcsys.cc > CMakeFiles/dramsim3test.dir/tests/test_hmcsys.cc.i

CMakeFiles/dramsim3test.dir/tests/test_hmcsys.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dramsim3test.dir/tests/test_hmcsys.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hs/NP_project/verilator_test/DRAMsim3/tests/test_hmcsys.cc -o CMakeFiles/dramsim3test.dir/tests/test_hmcsys.cc.s

# Object files for target dramsim3test
dramsim3test_OBJECTS = \
"CMakeFiles/dramsim3test.dir/tests/test_config.cc.o" \
"CMakeFiles/dramsim3test.dir/tests/test_dramsys.cc.o" \
"CMakeFiles/dramsim3test.dir/tests/test_hmcsys.cc.o"

# External object files for target dramsim3test
dramsim3test_EXTERNAL_OBJECTS =

dramsim3test: CMakeFiles/dramsim3test.dir/tests/test_config.cc.o
dramsim3test: CMakeFiles/dramsim3test.dir/tests/test_dramsys.cc.o
dramsim3test: CMakeFiles/dramsim3test.dir/tests/test_hmcsys.cc.o
dramsim3test: CMakeFiles/dramsim3test.dir/build.make
dramsim3test: libdramsim3.so
dramsim3test: CMakeFiles/dramsim3test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hs/NP_project/verilator_test/DRAMsim3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable dramsim3test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dramsim3test.dir/link.txt --verbose=$(VERBOSE)
	/home/hs/NP_project/verilator_test/DRAMsim3/dramsim3test

# Rule to build all files generated by this target.
CMakeFiles/dramsim3test.dir/build: dramsim3test
.PHONY : CMakeFiles/dramsim3test.dir/build

CMakeFiles/dramsim3test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dramsim3test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dramsim3test.dir/clean

CMakeFiles/dramsim3test.dir/depend:
	cd /home/hs/NP_project/verilator_test/DRAMsim3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hs/NP_project/verilator_test/DRAMsim3 /home/hs/NP_project/verilator_test/DRAMsim3 /home/hs/NP_project/verilator_test/DRAMsim3 /home/hs/NP_project/verilator_test/DRAMsim3 /home/hs/NP_project/verilator_test/DRAMsim3/CMakeFiles/dramsim3test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dramsim3test.dir/depend

