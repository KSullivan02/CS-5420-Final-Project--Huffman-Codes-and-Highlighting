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
CMAKE_SOURCE_DIR = "/home/moistlad/Documents/UMSL FALL 2024/CMP_SCI_5420/krs8dd.6/huffman"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/moistlad/Documents/UMSL FALL 2024/CMP_SCI_5420/krs8dd.6/huffman/build"

# Include any dependencies generated for this target.
include CMakeFiles/huffman.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/huffman.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/huffman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/huffman.dir/flags.make

CMakeFiles/huffman.dir/huffman.cpp.o: CMakeFiles/huffman.dir/flags.make
CMakeFiles/huffman.dir/huffman.cpp.o: ../huffman.cpp
CMakeFiles/huffman.dir/huffman.cpp.o: CMakeFiles/huffman.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/moistlad/Documents/UMSL FALL 2024/CMP_SCI_5420/krs8dd.6/huffman/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/huffman.dir/huffman.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/huffman.dir/huffman.cpp.o -MF CMakeFiles/huffman.dir/huffman.cpp.o.d -o CMakeFiles/huffman.dir/huffman.cpp.o -c "/home/moistlad/Documents/UMSL FALL 2024/CMP_SCI_5420/krs8dd.6/huffman/huffman.cpp"

CMakeFiles/huffman.dir/huffman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/huffman.dir/huffman.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/moistlad/Documents/UMSL FALL 2024/CMP_SCI_5420/krs8dd.6/huffman/huffman.cpp" > CMakeFiles/huffman.dir/huffman.cpp.i

CMakeFiles/huffman.dir/huffman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/huffman.dir/huffman.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/moistlad/Documents/UMSL FALL 2024/CMP_SCI_5420/krs8dd.6/huffman/huffman.cpp" -o CMakeFiles/huffman.dir/huffman.cpp.s

# Object files for target huffman
huffman_OBJECTS = \
"CMakeFiles/huffman.dir/huffman.cpp.o"

# External object files for target huffman
huffman_EXTERNAL_OBJECTS =

huffman: CMakeFiles/huffman.dir/huffman.cpp.o
huffman: CMakeFiles/huffman.dir/build.make
huffman: /usr/local/lib/libopencv_gapi.so.4.10.0
huffman: /usr/local/lib/libopencv_highgui.so.4.10.0
huffman: /usr/local/lib/libopencv_ml.so.4.10.0
huffman: /usr/local/lib/libopencv_objdetect.so.4.10.0
huffman: /usr/local/lib/libopencv_photo.so.4.10.0
huffman: /usr/local/lib/libopencv_stitching.so.4.10.0
huffman: /usr/local/lib/libopencv_video.so.4.10.0
huffman: /usr/local/lib/libopencv_videoio.so.4.10.0
huffman: /usr/local/lib/libopencv_imgcodecs.so.4.10.0
huffman: /usr/local/lib/libopencv_dnn.so.4.10.0
huffman: /usr/local/lib/libopencv_calib3d.so.4.10.0
huffman: /usr/local/lib/libopencv_features2d.so.4.10.0
huffman: /usr/local/lib/libopencv_flann.so.4.10.0
huffman: /usr/local/lib/libopencv_imgproc.so.4.10.0
huffman: /usr/local/lib/libopencv_core.so.4.10.0
huffman: CMakeFiles/huffman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/moistlad/Documents/UMSL FALL 2024/CMP_SCI_5420/krs8dd.6/huffman/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable huffman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/huffman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/huffman.dir/build: huffman
.PHONY : CMakeFiles/huffman.dir/build

CMakeFiles/huffman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/huffman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/huffman.dir/clean

CMakeFiles/huffman.dir/depend:
	cd "/home/moistlad/Documents/UMSL FALL 2024/CMP_SCI_5420/krs8dd.6/huffman/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/moistlad/Documents/UMSL FALL 2024/CMP_SCI_5420/krs8dd.6/huffman" "/home/moistlad/Documents/UMSL FALL 2024/CMP_SCI_5420/krs8dd.6/huffman" "/home/moistlad/Documents/UMSL FALL 2024/CMP_SCI_5420/krs8dd.6/huffman/build" "/home/moistlad/Documents/UMSL FALL 2024/CMP_SCI_5420/krs8dd.6/huffman/build" "/home/moistlad/Documents/UMSL FALL 2024/CMP_SCI_5420/krs8dd.6/huffman/build/CMakeFiles/huffman.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/huffman.dir/depend

