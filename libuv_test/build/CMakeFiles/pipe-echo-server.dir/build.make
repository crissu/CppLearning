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
include CMakeFiles/pipe-echo-server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pipe-echo-server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pipe-echo-server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pipe-echo-server.dir/flags.make

CMakeFiles/pipe-echo-server.dir/src/pipe-echo-server.cpp.o: CMakeFiles/pipe-echo-server.dir/flags.make
CMakeFiles/pipe-echo-server.dir/src/pipe-echo-server.cpp.o: ../src/pipe-echo-server.cpp
CMakeFiles/pipe-echo-server.dir/src/pipe-echo-server.cpp.o: CMakeFiles/pipe-echo-server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crissu/codeplace/cpp_projects/CppLearning/libuv_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pipe-echo-server.dir/src/pipe-echo-server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pipe-echo-server.dir/src/pipe-echo-server.cpp.o -MF CMakeFiles/pipe-echo-server.dir/src/pipe-echo-server.cpp.o.d -o CMakeFiles/pipe-echo-server.dir/src/pipe-echo-server.cpp.o -c /home/crissu/codeplace/cpp_projects/CppLearning/libuv_test/src/pipe-echo-server.cpp

CMakeFiles/pipe-echo-server.dir/src/pipe-echo-server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pipe-echo-server.dir/src/pipe-echo-server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crissu/codeplace/cpp_projects/CppLearning/libuv_test/src/pipe-echo-server.cpp > CMakeFiles/pipe-echo-server.dir/src/pipe-echo-server.cpp.i

CMakeFiles/pipe-echo-server.dir/src/pipe-echo-server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pipe-echo-server.dir/src/pipe-echo-server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crissu/codeplace/cpp_projects/CppLearning/libuv_test/src/pipe-echo-server.cpp -o CMakeFiles/pipe-echo-server.dir/src/pipe-echo-server.cpp.s

# Object files for target pipe-echo-server
pipe__echo__server_OBJECTS = \
"CMakeFiles/pipe-echo-server.dir/src/pipe-echo-server.cpp.o"

# External object files for target pipe-echo-server
pipe__echo__server_EXTERNAL_OBJECTS =

../bin/pipe-echo-server: CMakeFiles/pipe-echo-server.dir/src/pipe-echo-server.cpp.o
../bin/pipe-echo-server: CMakeFiles/pipe-echo-server.dir/build.make
../bin/pipe-echo-server: CMakeFiles/pipe-echo-server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/crissu/codeplace/cpp_projects/CppLearning/libuv_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/pipe-echo-server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pipe-echo-server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pipe-echo-server.dir/build: ../bin/pipe-echo-server
.PHONY : CMakeFiles/pipe-echo-server.dir/build

CMakeFiles/pipe-echo-server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pipe-echo-server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pipe-echo-server.dir/clean

CMakeFiles/pipe-echo-server.dir/depend:
	cd /home/crissu/codeplace/cpp_projects/CppLearning/libuv_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/crissu/codeplace/cpp_projects/CppLearning/libuv_test /home/crissu/codeplace/cpp_projects/CppLearning/libuv_test /home/crissu/codeplace/cpp_projects/CppLearning/libuv_test/build /home/crissu/codeplace/cpp_projects/CppLearning/libuv_test/build /home/crissu/codeplace/cpp_projects/CppLearning/libuv_test/build/CMakeFiles/pipe-echo-server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pipe-echo-server.dir/depend

