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
CMAKE_SOURCE_DIR = /home/xpomin/Prog/EngineSimulator/cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xpomin/Prog/EngineSimulator/cmake/build

# Include any dependencies generated for this target.
include src/CMakeFiles/Executable.out.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/Executable.out.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Executable.out.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Executable.out.dir/flags.make

src/CMakeFiles/Executable.out.dir/main.cpp.o: src/CMakeFiles/Executable.out.dir/flags.make
src/CMakeFiles/Executable.out.dir/main.cpp.o: ../src/main.cpp
src/CMakeFiles/Executable.out.dir/main.cpp.o: src/CMakeFiles/Executable.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xpomin/Prog/EngineSimulator/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/Executable.out.dir/main.cpp.o"
	cd /home/xpomin/Prog/EngineSimulator/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/Executable.out.dir/main.cpp.o -MF CMakeFiles/Executable.out.dir/main.cpp.o.d -o CMakeFiles/Executable.out.dir/main.cpp.o -c /home/xpomin/Prog/EngineSimulator/cmake/src/main.cpp

src/CMakeFiles/Executable.out.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Executable.out.dir/main.cpp.i"
	cd /home/xpomin/Prog/EngineSimulator/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xpomin/Prog/EngineSimulator/cmake/src/main.cpp > CMakeFiles/Executable.out.dir/main.cpp.i

src/CMakeFiles/Executable.out.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Executable.out.dir/main.cpp.s"
	cd /home/xpomin/Prog/EngineSimulator/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xpomin/Prog/EngineSimulator/cmake/src/main.cpp -o CMakeFiles/Executable.out.dir/main.cpp.s

# Object files for target Executable.out
Executable_out_OBJECTS = \
"CMakeFiles/Executable.out.dir/main.cpp.o"

# External object files for target Executable.out
Executable_out_EXTERNAL_OBJECTS =

src/Executable.out: src/CMakeFiles/Executable.out.dir/main.cpp.o
src/Executable.out: src/CMakeFiles/Executable.out.dir/build.make
src/Executable.out: engine_lib/libengines.a
src/Executable.out: engine_lib_tests/libengines_tests.a
src/Executable.out: engine_lib/libengines.a
src/Executable.out: src/CMakeFiles/Executable.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xpomin/Prog/EngineSimulator/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Executable.out"
	cd /home/xpomin/Prog/EngineSimulator/cmake/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Executable.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Executable.out.dir/build: src/Executable.out
.PHONY : src/CMakeFiles/Executable.out.dir/build

src/CMakeFiles/Executable.out.dir/clean:
	cd /home/xpomin/Prog/EngineSimulator/cmake/build/src && $(CMAKE_COMMAND) -P CMakeFiles/Executable.out.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Executable.out.dir/clean

src/CMakeFiles/Executable.out.dir/depend:
	cd /home/xpomin/Prog/EngineSimulator/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xpomin/Prog/EngineSimulator/cmake /home/xpomin/Prog/EngineSimulator/cmake/src /home/xpomin/Prog/EngineSimulator/cmake/build /home/xpomin/Prog/EngineSimulator/cmake/build/src /home/xpomin/Prog/EngineSimulator/cmake/build/src/CMakeFiles/Executable.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Executable.out.dir/depend
