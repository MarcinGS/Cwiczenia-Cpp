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
CMAKE_SOURCE_DIR = "C:\Users\marci\Desktop\c++\Lab 7\ble"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\marci\Desktop\c++\Lab 7\ble\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ble.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ble.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ble.dir/flags.make

CMakeFiles/ble.dir/main.cpp.obj: CMakeFiles/ble.dir/flags.make
CMakeFiles/ble.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\marci\Desktop\c++\Lab 7\ble\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ble.dir/main.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ble.dir\main.cpp.obj -c "C:\Users\marci\Desktop\c++\Lab 7\ble\main.cpp"

CMakeFiles/ble.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ble.dir/main.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\marci\Desktop\c++\Lab 7\ble\main.cpp" > CMakeFiles\ble.dir\main.cpp.i

CMakeFiles/ble.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ble.dir/main.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\marci\Desktop\c++\Lab 7\ble\main.cpp" -o CMakeFiles\ble.dir\main.cpp.s

# Object files for target ble
ble_OBJECTS = \
"CMakeFiles/ble.dir/main.cpp.obj"

# External object files for target ble
ble_EXTERNAL_OBJECTS =

ble.exe: CMakeFiles/ble.dir/main.cpp.obj
ble.exe: CMakeFiles/ble.dir/build.make
ble.exe: CMakeFiles/ble.dir/linklibs.rsp
ble.exe: CMakeFiles/ble.dir/objects1.rsp
ble.exe: CMakeFiles/ble.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\marci\Desktop\c++\Lab 7\ble\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ble.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ble.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ble.dir/build: ble.exe

.PHONY : CMakeFiles/ble.dir/build

CMakeFiles/ble.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ble.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ble.dir/clean

CMakeFiles/ble.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\marci\Desktop\c++\Lab 7\ble" "C:\Users\marci\Desktop\c++\Lab 7\ble" "C:\Users\marci\Desktop\c++\Lab 7\ble\cmake-build-debug" "C:\Users\marci\Desktop\c++\Lab 7\ble\cmake-build-debug" "C:\Users\marci\Desktop\c++\Lab 7\ble\cmake-build-debug\CMakeFiles\ble.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ble.dir/depend

