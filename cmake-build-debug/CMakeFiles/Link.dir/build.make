# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mrrightli/Documents/workplace/Data/DSA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mrrightli/Documents/workplace/Data/DSA/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Link.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Link.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Link.dir/flags.make

CMakeFiles/Link.dir/Queue.c.o: CMakeFiles/Link.dir/flags.make
CMakeFiles/Link.dir/Queue.c.o: ../Queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mrrightli/Documents/workplace/Data/DSA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Link.dir/Queue.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Link.dir/Queue.c.o   -c /Users/mrrightli/Documents/workplace/Data/DSA/Queue.c

CMakeFiles/Link.dir/Queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Link.dir/Queue.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mrrightli/Documents/workplace/Data/DSA/Queue.c > CMakeFiles/Link.dir/Queue.c.i

CMakeFiles/Link.dir/Queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Link.dir/Queue.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mrrightli/Documents/workplace/Data/DSA/Queue.c -o CMakeFiles/Link.dir/Queue.c.s

CMakeFiles/Link.dir/Queue.c.o.requires:

.PHONY : CMakeFiles/Link.dir/Queue.c.o.requires

CMakeFiles/Link.dir/Queue.c.o.provides: CMakeFiles/Link.dir/Queue.c.o.requires
	$(MAKE) -f CMakeFiles/Link.dir/build.make CMakeFiles/Link.dir/Queue.c.o.provides.build
.PHONY : CMakeFiles/Link.dir/Queue.c.o.provides

CMakeFiles/Link.dir/Queue.c.o.provides.build: CMakeFiles/Link.dir/Queue.c.o


# Object files for target Link
Link_OBJECTS = \
"CMakeFiles/Link.dir/Queue.c.o"

# External object files for target Link
Link_EXTERNAL_OBJECTS =

Link: CMakeFiles/Link.dir/Queue.c.o
Link: CMakeFiles/Link.dir/build.make
Link: CMakeFiles/Link.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mrrightli/Documents/workplace/Data/DSA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Link"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Link.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Link.dir/build: Link

.PHONY : CMakeFiles/Link.dir/build

CMakeFiles/Link.dir/requires: CMakeFiles/Link.dir/Queue.c.o.requires

.PHONY : CMakeFiles/Link.dir/requires

CMakeFiles/Link.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Link.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Link.dir/clean

CMakeFiles/Link.dir/depend:
	cd /Users/mrrightli/Documents/workplace/Data/DSA/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mrrightli/Documents/workplace/Data/DSA /Users/mrrightli/Documents/workplace/Data/DSA /Users/mrrightli/Documents/workplace/Data/DSA/cmake-build-debug /Users/mrrightli/Documents/workplace/Data/DSA/cmake-build-debug /Users/mrrightli/Documents/workplace/Data/DSA/cmake-build-debug/CMakeFiles/Link.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Link.dir/depend

