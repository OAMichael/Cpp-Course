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
CMAKE_SOURCE_DIR = /home/michael/Documents/C/C++/Triangles

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/michael/Documents/C/C++/Triangles

# Include any dependencies generated for this target.
include CMakeFiles/TrINT.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TrINT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TrINT.dir/flags.make

CMakeFiles/TrINT.dir/TrINT.cpp.o: CMakeFiles/TrINT.dir/flags.make
CMakeFiles/TrINT.dir/TrINT.cpp.o: TrINT.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/Documents/C/C++/Triangles/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TrINT.dir/TrINT.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TrINT.dir/TrINT.cpp.o -c /home/michael/Documents/C/C++/Triangles/TrINT.cpp

CMakeFiles/TrINT.dir/TrINT.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrINT.dir/TrINT.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michael/Documents/C/C++/Triangles/TrINT.cpp > CMakeFiles/TrINT.dir/TrINT.cpp.i

CMakeFiles/TrINT.dir/TrINT.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrINT.dir/TrINT.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michael/Documents/C/C++/Triangles/TrINT.cpp -o CMakeFiles/TrINT.dir/TrINT.cpp.s

# Object files for target TrINT
TrINT_OBJECTS = \
"CMakeFiles/TrINT.dir/TrINT.cpp.o"

# External object files for target TrINT
TrINT_EXTERNAL_OBJECTS =

TrINT: CMakeFiles/TrINT.dir/TrINT.cpp.o
TrINT: CMakeFiles/TrINT.dir/build.make
TrINT: CMakeFiles/TrINT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/michael/Documents/C/C++/Triangles/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TrINT"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TrINT.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TrINT.dir/build: TrINT

.PHONY : CMakeFiles/TrINT.dir/build

CMakeFiles/TrINT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TrINT.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TrINT.dir/clean

CMakeFiles/TrINT.dir/depend:
	cd /home/michael/Documents/C/C++/Triangles && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michael/Documents/C/C++/Triangles /home/michael/Documents/C/C++/Triangles /home/michael/Documents/C/C++/Triangles /home/michael/Documents/C/C++/Triangles /home/michael/Documents/C/C++/Triangles/CMakeFiles/TrINT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TrINT.dir/depend

