# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /mnt/d/mipt/cpp3sem/sem2/lab1/part0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/mipt/cpp3sem/sem2/lab1/part0/build

# Include any dependencies generated for this target.
include CMakeFiles/test2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test2.dir/flags.make

CMakeFiles/test2.dir/tests/test2.cpp.o: CMakeFiles/test2.dir/flags.make
CMakeFiles/test2.dir/tests/test2.cpp.o: /mnt/d/mipt/cpp3sem/sem2/lab1/part0/tests/test2.cpp
CMakeFiles/test2.dir/tests/test2.cpp.o: CMakeFiles/test2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/d/mipt/cpp3sem/sem2/lab1/part0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test2.dir/tests/test2.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test2.dir/tests/test2.cpp.o -MF CMakeFiles/test2.dir/tests/test2.cpp.o.d -o CMakeFiles/test2.dir/tests/test2.cpp.o -c /mnt/d/mipt/cpp3sem/sem2/lab1/part0/tests/test2.cpp

CMakeFiles/test2.dir/tests/test2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test2.dir/tests/test2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/mipt/cpp3sem/sem2/lab1/part0/tests/test2.cpp > CMakeFiles/test2.dir/tests/test2.cpp.i

CMakeFiles/test2.dir/tests/test2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test2.dir/tests/test2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/mipt/cpp3sem/sem2/lab1/part0/tests/test2.cpp -o CMakeFiles/test2.dir/tests/test2.cpp.s

# Object files for target test2
test2_OBJECTS = \
"CMakeFiles/test2.dir/tests/test2.cpp.o"

# External object files for target test2
test2_EXTERNAL_OBJECTS =

test2: CMakeFiles/test2.dir/tests/test2.cpp.o
test2: CMakeFiles/test2.dir/build.make
test2: libmatrix_lib.a
test2: CMakeFiles/test2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/d/mipt/cpp3sem/sem2/lab1/part0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test2.dir/build: test2
.PHONY : CMakeFiles/test2.dir/build

CMakeFiles/test2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test2.dir/clean

CMakeFiles/test2.dir/depend:
	cd /mnt/d/mipt/cpp3sem/sem2/lab1/part0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/mipt/cpp3sem/sem2/lab1/part0 /mnt/d/mipt/cpp3sem/sem2/lab1/part0 /mnt/d/mipt/cpp3sem/sem2/lab1/part0/build /mnt/d/mipt/cpp3sem/sem2/lab1/part0/build /mnt/d/mipt/cpp3sem/sem2/lab1/part0/build/CMakeFiles/test2.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test2.dir/depend

