# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yangdi/work/aptiv/HDM_communication_with_HMI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yangdi/work/aptiv/HDM_communication_with_HMI/build

# Include any dependencies generated for this target.
include CMakeFiles/zmq_comm.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/zmq_comm.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/zmq_comm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zmq_comm.dir/flags.make

CMakeFiles/zmq_comm.dir/src/main.cpp.o: CMakeFiles/zmq_comm.dir/flags.make
CMakeFiles/zmq_comm.dir/src/main.cpp.o: /home/yangdi/work/aptiv/HDM_communication_with_HMI/src/main.cpp
CMakeFiles/zmq_comm.dir/src/main.cpp.o: CMakeFiles/zmq_comm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yangdi/work/aptiv/HDM_communication_with_HMI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zmq_comm.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zmq_comm.dir/src/main.cpp.o -MF CMakeFiles/zmq_comm.dir/src/main.cpp.o.d -o CMakeFiles/zmq_comm.dir/src/main.cpp.o -c /home/yangdi/work/aptiv/HDM_communication_with_HMI/src/main.cpp

CMakeFiles/zmq_comm.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zmq_comm.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yangdi/work/aptiv/HDM_communication_with_HMI/src/main.cpp > CMakeFiles/zmq_comm.dir/src/main.cpp.i

CMakeFiles/zmq_comm.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zmq_comm.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yangdi/work/aptiv/HDM_communication_with_HMI/src/main.cpp -o CMakeFiles/zmq_comm.dir/src/main.cpp.s

CMakeFiles/zmq_comm.dir/src/zmq_publisher.cpp.o: CMakeFiles/zmq_comm.dir/flags.make
CMakeFiles/zmq_comm.dir/src/zmq_publisher.cpp.o: /home/yangdi/work/aptiv/HDM_communication_with_HMI/src/zmq_publisher.cpp
CMakeFiles/zmq_comm.dir/src/zmq_publisher.cpp.o: CMakeFiles/zmq_comm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yangdi/work/aptiv/HDM_communication_with_HMI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/zmq_comm.dir/src/zmq_publisher.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zmq_comm.dir/src/zmq_publisher.cpp.o -MF CMakeFiles/zmq_comm.dir/src/zmq_publisher.cpp.o.d -o CMakeFiles/zmq_comm.dir/src/zmq_publisher.cpp.o -c /home/yangdi/work/aptiv/HDM_communication_with_HMI/src/zmq_publisher.cpp

CMakeFiles/zmq_comm.dir/src/zmq_publisher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zmq_comm.dir/src/zmq_publisher.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yangdi/work/aptiv/HDM_communication_with_HMI/src/zmq_publisher.cpp > CMakeFiles/zmq_comm.dir/src/zmq_publisher.cpp.i

CMakeFiles/zmq_comm.dir/src/zmq_publisher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zmq_comm.dir/src/zmq_publisher.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yangdi/work/aptiv/HDM_communication_with_HMI/src/zmq_publisher.cpp -o CMakeFiles/zmq_comm.dir/src/zmq_publisher.cpp.s

CMakeFiles/zmq_comm.dir/src/zmq_subscriber.cpp.o: CMakeFiles/zmq_comm.dir/flags.make
CMakeFiles/zmq_comm.dir/src/zmq_subscriber.cpp.o: /home/yangdi/work/aptiv/HDM_communication_with_HMI/src/zmq_subscriber.cpp
CMakeFiles/zmq_comm.dir/src/zmq_subscriber.cpp.o: CMakeFiles/zmq_comm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yangdi/work/aptiv/HDM_communication_with_HMI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/zmq_comm.dir/src/zmq_subscriber.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zmq_comm.dir/src/zmq_subscriber.cpp.o -MF CMakeFiles/zmq_comm.dir/src/zmq_subscriber.cpp.o.d -o CMakeFiles/zmq_comm.dir/src/zmq_subscriber.cpp.o -c /home/yangdi/work/aptiv/HDM_communication_with_HMI/src/zmq_subscriber.cpp

CMakeFiles/zmq_comm.dir/src/zmq_subscriber.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zmq_comm.dir/src/zmq_subscriber.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yangdi/work/aptiv/HDM_communication_with_HMI/src/zmq_subscriber.cpp > CMakeFiles/zmq_comm.dir/src/zmq_subscriber.cpp.i

CMakeFiles/zmq_comm.dir/src/zmq_subscriber.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zmq_comm.dir/src/zmq_subscriber.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yangdi/work/aptiv/HDM_communication_with_HMI/src/zmq_subscriber.cpp -o CMakeFiles/zmq_comm.dir/src/zmq_subscriber.cpp.s

CMakeFiles/zmq_comm.dir/proto/Person.pb.cc.o: CMakeFiles/zmq_comm.dir/flags.make
CMakeFiles/zmq_comm.dir/proto/Person.pb.cc.o: /home/yangdi/work/aptiv/HDM_communication_with_HMI/proto/Person.pb.cc
CMakeFiles/zmq_comm.dir/proto/Person.pb.cc.o: CMakeFiles/zmq_comm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yangdi/work/aptiv/HDM_communication_with_HMI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/zmq_comm.dir/proto/Person.pb.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zmq_comm.dir/proto/Person.pb.cc.o -MF CMakeFiles/zmq_comm.dir/proto/Person.pb.cc.o.d -o CMakeFiles/zmq_comm.dir/proto/Person.pb.cc.o -c /home/yangdi/work/aptiv/HDM_communication_with_HMI/proto/Person.pb.cc

CMakeFiles/zmq_comm.dir/proto/Person.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zmq_comm.dir/proto/Person.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yangdi/work/aptiv/HDM_communication_with_HMI/proto/Person.pb.cc > CMakeFiles/zmq_comm.dir/proto/Person.pb.cc.i

CMakeFiles/zmq_comm.dir/proto/Person.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zmq_comm.dir/proto/Person.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yangdi/work/aptiv/HDM_communication_with_HMI/proto/Person.pb.cc -o CMakeFiles/zmq_comm.dir/proto/Person.pb.cc.s

CMakeFiles/zmq_comm.dir/proto/common.pb.cc.o: CMakeFiles/zmq_comm.dir/flags.make
CMakeFiles/zmq_comm.dir/proto/common.pb.cc.o: /home/yangdi/work/aptiv/HDM_communication_with_HMI/proto/common.pb.cc
CMakeFiles/zmq_comm.dir/proto/common.pb.cc.o: CMakeFiles/zmq_comm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yangdi/work/aptiv/HDM_communication_with_HMI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/zmq_comm.dir/proto/common.pb.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zmq_comm.dir/proto/common.pb.cc.o -MF CMakeFiles/zmq_comm.dir/proto/common.pb.cc.o.d -o CMakeFiles/zmq_comm.dir/proto/common.pb.cc.o -c /home/yangdi/work/aptiv/HDM_communication_with_HMI/proto/common.pb.cc

CMakeFiles/zmq_comm.dir/proto/common.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zmq_comm.dir/proto/common.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yangdi/work/aptiv/HDM_communication_with_HMI/proto/common.pb.cc > CMakeFiles/zmq_comm.dir/proto/common.pb.cc.i

CMakeFiles/zmq_comm.dir/proto/common.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zmq_comm.dir/proto/common.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yangdi/work/aptiv/HDM_communication_with_HMI/proto/common.pb.cc -o CMakeFiles/zmq_comm.dir/proto/common.pb.cc.s

CMakeFiles/zmq_comm.dir/proto/frame.pb.cc.o: CMakeFiles/zmq_comm.dir/flags.make
CMakeFiles/zmq_comm.dir/proto/frame.pb.cc.o: /home/yangdi/work/aptiv/HDM_communication_with_HMI/proto/frame.pb.cc
CMakeFiles/zmq_comm.dir/proto/frame.pb.cc.o: CMakeFiles/zmq_comm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yangdi/work/aptiv/HDM_communication_with_HMI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/zmq_comm.dir/proto/frame.pb.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zmq_comm.dir/proto/frame.pb.cc.o -MF CMakeFiles/zmq_comm.dir/proto/frame.pb.cc.o.d -o CMakeFiles/zmq_comm.dir/proto/frame.pb.cc.o -c /home/yangdi/work/aptiv/HDM_communication_with_HMI/proto/frame.pb.cc

CMakeFiles/zmq_comm.dir/proto/frame.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zmq_comm.dir/proto/frame.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yangdi/work/aptiv/HDM_communication_with_HMI/proto/frame.pb.cc > CMakeFiles/zmq_comm.dir/proto/frame.pb.cc.i

CMakeFiles/zmq_comm.dir/proto/frame.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zmq_comm.dir/proto/frame.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yangdi/work/aptiv/HDM_communication_with_HMI/proto/frame.pb.cc -o CMakeFiles/zmq_comm.dir/proto/frame.pb.cc.s

CMakeFiles/zmq_comm.dir/proto/topics.pb.cc.o: CMakeFiles/zmq_comm.dir/flags.make
CMakeFiles/zmq_comm.dir/proto/topics.pb.cc.o: /home/yangdi/work/aptiv/HDM_communication_with_HMI/proto/topics.pb.cc
CMakeFiles/zmq_comm.dir/proto/topics.pb.cc.o: CMakeFiles/zmq_comm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yangdi/work/aptiv/HDM_communication_with_HMI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/zmq_comm.dir/proto/topics.pb.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zmq_comm.dir/proto/topics.pb.cc.o -MF CMakeFiles/zmq_comm.dir/proto/topics.pb.cc.o.d -o CMakeFiles/zmq_comm.dir/proto/topics.pb.cc.o -c /home/yangdi/work/aptiv/HDM_communication_with_HMI/proto/topics.pb.cc

CMakeFiles/zmq_comm.dir/proto/topics.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zmq_comm.dir/proto/topics.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yangdi/work/aptiv/HDM_communication_with_HMI/proto/topics.pb.cc > CMakeFiles/zmq_comm.dir/proto/topics.pb.cc.i

CMakeFiles/zmq_comm.dir/proto/topics.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zmq_comm.dir/proto/topics.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yangdi/work/aptiv/HDM_communication_with_HMI/proto/topics.pb.cc -o CMakeFiles/zmq_comm.dir/proto/topics.pb.cc.s

# Object files for target zmq_comm
zmq_comm_OBJECTS = \
"CMakeFiles/zmq_comm.dir/src/main.cpp.o" \
"CMakeFiles/zmq_comm.dir/src/zmq_publisher.cpp.o" \
"CMakeFiles/zmq_comm.dir/src/zmq_subscriber.cpp.o" \
"CMakeFiles/zmq_comm.dir/proto/Person.pb.cc.o" \
"CMakeFiles/zmq_comm.dir/proto/common.pb.cc.o" \
"CMakeFiles/zmq_comm.dir/proto/frame.pb.cc.o" \
"CMakeFiles/zmq_comm.dir/proto/topics.pb.cc.o"

# External object files for target zmq_comm
zmq_comm_EXTERNAL_OBJECTS =

output/bin/zmq_comm: CMakeFiles/zmq_comm.dir/src/main.cpp.o
output/bin/zmq_comm: CMakeFiles/zmq_comm.dir/src/zmq_publisher.cpp.o
output/bin/zmq_comm: CMakeFiles/zmq_comm.dir/src/zmq_subscriber.cpp.o
output/bin/zmq_comm: CMakeFiles/zmq_comm.dir/proto/Person.pb.cc.o
output/bin/zmq_comm: CMakeFiles/zmq_comm.dir/proto/common.pb.cc.o
output/bin/zmq_comm: CMakeFiles/zmq_comm.dir/proto/frame.pb.cc.o
output/bin/zmq_comm: CMakeFiles/zmq_comm.dir/proto/topics.pb.cc.o
output/bin/zmq_comm: CMakeFiles/zmq_comm.dir/build.make
output/bin/zmq_comm: /usr/local/lib/libprotobuf.so
output/bin/zmq_comm: CMakeFiles/zmq_comm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yangdi/work/aptiv/HDM_communication_with_HMI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable output/bin/zmq_comm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zmq_comm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zmq_comm.dir/build: output/bin/zmq_comm
.PHONY : CMakeFiles/zmq_comm.dir/build

CMakeFiles/zmq_comm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zmq_comm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zmq_comm.dir/clean

CMakeFiles/zmq_comm.dir/depend:
	cd /home/yangdi/work/aptiv/HDM_communication_with_HMI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yangdi/work/aptiv/HDM_communication_with_HMI /home/yangdi/work/aptiv/HDM_communication_with_HMI /home/yangdi/work/aptiv/HDM_communication_with_HMI/build /home/yangdi/work/aptiv/HDM_communication_with_HMI/build /home/yangdi/work/aptiv/HDM_communication_with_HMI/build/CMakeFiles/zmq_comm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zmq_comm.dir/depend

