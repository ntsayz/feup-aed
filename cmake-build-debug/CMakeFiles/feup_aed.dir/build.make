# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /snap/clion/209/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/209/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ntsayz/Documents/feup-aed

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ntsayz/Documents/feup-aed/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/feup_aed.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/feup_aed.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/feup_aed.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/feup_aed.dir/flags.make

CMakeFiles/feup_aed.dir/main.cpp.o: CMakeFiles/feup_aed.dir/flags.make
CMakeFiles/feup_aed.dir/main.cpp.o: ../main.cpp
CMakeFiles/feup_aed.dir/main.cpp.o: CMakeFiles/feup_aed.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ntsayz/Documents/feup-aed/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/feup_aed.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/feup_aed.dir/main.cpp.o -MF CMakeFiles/feup_aed.dir/main.cpp.o.d -o CMakeFiles/feup_aed.dir/main.cpp.o -c /home/ntsayz/Documents/feup-aed/main.cpp

CMakeFiles/feup_aed.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/feup_aed.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ntsayz/Documents/feup-aed/main.cpp > CMakeFiles/feup_aed.dir/main.cpp.i

CMakeFiles/feup_aed.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/feup_aed.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ntsayz/Documents/feup-aed/main.cpp -o CMakeFiles/feup_aed.dir/main.cpp.s

CMakeFiles/feup_aed.dir/src/Manager.cpp.o: CMakeFiles/feup_aed.dir/flags.make
CMakeFiles/feup_aed.dir/src/Manager.cpp.o: ../src/Manager.cpp
CMakeFiles/feup_aed.dir/src/Manager.cpp.o: CMakeFiles/feup_aed.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ntsayz/Documents/feup-aed/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/feup_aed.dir/src/Manager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/feup_aed.dir/src/Manager.cpp.o -MF CMakeFiles/feup_aed.dir/src/Manager.cpp.o.d -o CMakeFiles/feup_aed.dir/src/Manager.cpp.o -c /home/ntsayz/Documents/feup-aed/src/Manager.cpp

CMakeFiles/feup_aed.dir/src/Manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/feup_aed.dir/src/Manager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ntsayz/Documents/feup-aed/src/Manager.cpp > CMakeFiles/feup_aed.dir/src/Manager.cpp.i

CMakeFiles/feup_aed.dir/src/Manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/feup_aed.dir/src/Manager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ntsayz/Documents/feup-aed/src/Manager.cpp -o CMakeFiles/feup_aed.dir/src/Manager.cpp.s

CMakeFiles/feup_aed.dir/src/Student.cpp.o: CMakeFiles/feup_aed.dir/flags.make
CMakeFiles/feup_aed.dir/src/Student.cpp.o: ../src/Student.cpp
CMakeFiles/feup_aed.dir/src/Student.cpp.o: CMakeFiles/feup_aed.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ntsayz/Documents/feup-aed/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/feup_aed.dir/src/Student.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/feup_aed.dir/src/Student.cpp.o -MF CMakeFiles/feup_aed.dir/src/Student.cpp.o.d -o CMakeFiles/feup_aed.dir/src/Student.cpp.o -c /home/ntsayz/Documents/feup-aed/src/Student.cpp

CMakeFiles/feup_aed.dir/src/Student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/feup_aed.dir/src/Student.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ntsayz/Documents/feup-aed/src/Student.cpp > CMakeFiles/feup_aed.dir/src/Student.cpp.i

CMakeFiles/feup_aed.dir/src/Student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/feup_aed.dir/src/Student.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ntsayz/Documents/feup-aed/src/Student.cpp -o CMakeFiles/feup_aed.dir/src/Student.cpp.s

CMakeFiles/feup_aed.dir/src/Turma.cpp.o: CMakeFiles/feup_aed.dir/flags.make
CMakeFiles/feup_aed.dir/src/Turma.cpp.o: ../src/Turma.cpp
CMakeFiles/feup_aed.dir/src/Turma.cpp.o: CMakeFiles/feup_aed.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ntsayz/Documents/feup-aed/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/feup_aed.dir/src/Turma.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/feup_aed.dir/src/Turma.cpp.o -MF CMakeFiles/feup_aed.dir/src/Turma.cpp.o.d -o CMakeFiles/feup_aed.dir/src/Turma.cpp.o -c /home/ntsayz/Documents/feup-aed/src/Turma.cpp

CMakeFiles/feup_aed.dir/src/Turma.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/feup_aed.dir/src/Turma.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ntsayz/Documents/feup-aed/src/Turma.cpp > CMakeFiles/feup_aed.dir/src/Turma.cpp.i

CMakeFiles/feup_aed.dir/src/Turma.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/feup_aed.dir/src/Turma.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ntsayz/Documents/feup-aed/src/Turma.cpp -o CMakeFiles/feup_aed.dir/src/Turma.cpp.s

CMakeFiles/feup_aed.dir/src/Utilities.cpp.o: CMakeFiles/feup_aed.dir/flags.make
CMakeFiles/feup_aed.dir/src/Utilities.cpp.o: ../src/Utilities.cpp
CMakeFiles/feup_aed.dir/src/Utilities.cpp.o: CMakeFiles/feup_aed.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ntsayz/Documents/feup-aed/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/feup_aed.dir/src/Utilities.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/feup_aed.dir/src/Utilities.cpp.o -MF CMakeFiles/feup_aed.dir/src/Utilities.cpp.o.d -o CMakeFiles/feup_aed.dir/src/Utilities.cpp.o -c /home/ntsayz/Documents/feup-aed/src/Utilities.cpp

CMakeFiles/feup_aed.dir/src/Utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/feup_aed.dir/src/Utilities.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ntsayz/Documents/feup-aed/src/Utilities.cpp > CMakeFiles/feup_aed.dir/src/Utilities.cpp.i

CMakeFiles/feup_aed.dir/src/Utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/feup_aed.dir/src/Utilities.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ntsayz/Documents/feup-aed/src/Utilities.cpp -o CMakeFiles/feup_aed.dir/src/Utilities.cpp.s

CMakeFiles/feup_aed.dir/src/Slot.cpp.o: CMakeFiles/feup_aed.dir/flags.make
CMakeFiles/feup_aed.dir/src/Slot.cpp.o: ../src/Slot.cpp
CMakeFiles/feup_aed.dir/src/Slot.cpp.o: CMakeFiles/feup_aed.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ntsayz/Documents/feup-aed/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/feup_aed.dir/src/Slot.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/feup_aed.dir/src/Slot.cpp.o -MF CMakeFiles/feup_aed.dir/src/Slot.cpp.o.d -o CMakeFiles/feup_aed.dir/src/Slot.cpp.o -c /home/ntsayz/Documents/feup-aed/src/Slot.cpp

CMakeFiles/feup_aed.dir/src/Slot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/feup_aed.dir/src/Slot.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ntsayz/Documents/feup-aed/src/Slot.cpp > CMakeFiles/feup_aed.dir/src/Slot.cpp.i

CMakeFiles/feup_aed.dir/src/Slot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/feup_aed.dir/src/Slot.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ntsayz/Documents/feup-aed/src/Slot.cpp -o CMakeFiles/feup_aed.dir/src/Slot.cpp.s

# Object files for target feup_aed
feup_aed_OBJECTS = \
"CMakeFiles/feup_aed.dir/main.cpp.o" \
"CMakeFiles/feup_aed.dir/src/Manager.cpp.o" \
"CMakeFiles/feup_aed.dir/src/Student.cpp.o" \
"CMakeFiles/feup_aed.dir/src/Turma.cpp.o" \
"CMakeFiles/feup_aed.dir/src/Utilities.cpp.o" \
"CMakeFiles/feup_aed.dir/src/Slot.cpp.o"

# External object files for target feup_aed
feup_aed_EXTERNAL_OBJECTS =

feup_aed: CMakeFiles/feup_aed.dir/main.cpp.o
feup_aed: CMakeFiles/feup_aed.dir/src/Manager.cpp.o
feup_aed: CMakeFiles/feup_aed.dir/src/Student.cpp.o
feup_aed: CMakeFiles/feup_aed.dir/src/Turma.cpp.o
feup_aed: CMakeFiles/feup_aed.dir/src/Utilities.cpp.o
feup_aed: CMakeFiles/feup_aed.dir/src/Slot.cpp.o
feup_aed: CMakeFiles/feup_aed.dir/build.make
feup_aed: CMakeFiles/feup_aed.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ntsayz/Documents/feup-aed/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable feup_aed"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/feup_aed.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/feup_aed.dir/build: feup_aed
.PHONY : CMakeFiles/feup_aed.dir/build

CMakeFiles/feup_aed.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/feup_aed.dir/cmake_clean.cmake
.PHONY : CMakeFiles/feup_aed.dir/clean

CMakeFiles/feup_aed.dir/depend:
	cd /home/ntsayz/Documents/feup-aed/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ntsayz/Documents/feup-aed /home/ntsayz/Documents/feup-aed /home/ntsayz/Documents/feup-aed/cmake-build-debug /home/ntsayz/Documents/feup-aed/cmake-build-debug /home/ntsayz/Documents/feup-aed/cmake-build-debug/CMakeFiles/feup_aed.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/feup_aed.dir/depend

