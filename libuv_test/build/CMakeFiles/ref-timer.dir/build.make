# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /home/crissu/codeplace/cpp_projects/CppLearning/libuv_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/crissu/codeplace/cpp_projects/CppLearning/libuv_test/build

# Include any dependencies generated for this target.
include CMakeFiles/ref-timer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ref-timer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ref-timer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ref-timer.dir/flags.make

CMakeFiles/ref-timer.dir/src/ref-timer.cpp.o: CMakeFiles/ref-timer.dir/flags.make
CMakeFiles/ref-timer.dir/src/ref-timer.cpp.o: ../src/ref-timer.cpp
CMakeFiles/ref-timer.dir/src/ref-timer.cpp.o: CMakeFiles/ref-timer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crissu/codeplace/cpp_projects/CppLearning/libuv_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ref-timer.dir/src/ref-timer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ref-timer.dir/src/ref-timer.cpp.o -MF CMakeFiles/ref-timer.dir/src/ref-timer.cpp.o.d -o CMakeFiles/ref-timer.dir/src/ref-timer.cpp.o -c /home/crissu/codeplace/cpp_projects/CppLearning/libuv_test/src/ref-timer.cpp

CMakeFiles/ref-timer.dir/src/ref-timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ref-timer.dir/src/ref-timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crissu/codeplace/cpp_projects/CppLearning/libuv_test/src/ref-timer.cpp > CMakeFiles/ref-timer.dir/src/ref-timer.cpp.i

CMakeFiles/ref-timer.dir/src/ref-timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ref-timer.dir/src/ref-timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crissu/codeplace/cpp_projects/CppLearning/libuv_test/src/ref-timer.cpp -o CMakeFiles/ref-timer.dir/src/ref-timer.cpp.s

# Object files for target ref-timer
ref__timer_OBJECTS = \
"CMakeFiles/ref-timer.dir/src/ref-timer.cpp.o"

# External object files for target ref-timer
ref__timer_EXTERNAL_OBJECTS =

../bin/ref-timer: CMakeFiles/ref-timer.dir/src/ref-timer.cpp.o
../bin/ref-timer: CMakeFiles/ref-timer.dir/build.make
../bin/ref-timer: CMakeFiles/ref-timer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/crissu/codeplace/cpp_projects/CppLearning/libuv_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/ref-timer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ref-timer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ref-timer.dir/build: ../bin/ref-timer
.PHONY : CMakeFiles/ref-timer.dir/build

CMakeFiles/ref-timer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ref-timer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ref-timer.dir/clean

CMakeFiles/ref-timer.dir/depend:
	cd /home/crissu/codeplace/cpp_projects/CppLearning/libuv_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/crissu/codeplace/cpp_projects/CppLearning/libuv_test /home/crissu/codeplace/cpp_projects/CppLearning/libuv_test /home/crissu/codeplace/cpp_projects/CppLearning/libuv_test/build /home/crissu/codeplace/cpp_projects/CppLearning/libuv_test/build /home/crissu/codeplace/cpp_projects/CppLearning/libuv_test/build/CMakeFiles/ref-timer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ref-timer.dir/depend
