# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\marci\Desktop\c++\Lab 2\6"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\marci\Desktop\c++\Lab 2\6\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/6.dir/flags.make

CMakeFiles/6.dir/main.cpp.obj: CMakeFiles/6.dir/flags.make
CMakeFiles/6.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\marci\Desktop\c++\Lab 2\6\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/6.dir/main.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\6.dir\main.cpp.obj -c "C:\Users\marci\Desktop\c++\Lab 2\6\main.cpp"

CMakeFiles/6.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/6.dir/main.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\marci\Desktop\c++\Lab 2\6\main.cpp" > CMakeFiles\6.dir\main.cpp.i

CMakeFiles/6.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/6.dir/main.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\marci\Desktop\c++\Lab 2\6\main.cpp" -o CMakeFiles\6.dir\main.cpp.s

# Object files for target 6
6_OBJECTS = \
"CMakeFiles/6.dir/main.cpp.obj"

# External object files for target 6
6_EXTERNAL_OBJECTS =

6.exe: CMakeFiles/6.dir/main.cpp.obj
6.exe: CMakeFiles/6.dir/build.make
6.exe: CMakeFiles/6.dir/linklibs.rsp
6.exe: CMakeFiles/6.dir/objects1.rsp
6.exe: CMakeFiles/6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\marci\Desktop\c++\Lab 2\6\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 6.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\6.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/6.dir/build: 6.exe

.PHONY : CMakeFiles/6.dir/build

CMakeFiles/6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\6.dir\cmake_clean.cmake
.PHONY : CMakeFiles/6.dir/clean

CMakeFiles/6.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\marci\Desktop\c++\Lab 2\6" "C:\Users\marci\Desktop\c++\Lab 2\6" "C:\Users\marci\Desktop\c++\Lab 2\6\cmake-build-debug" "C:\Users\marci\Desktop\c++\Lab 2\6\cmake-build-debug" "C:\Users\marci\Desktop\c++\Lab 2\6\cmake-build-debug\CMakeFiles\6.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/6.dir/depend
