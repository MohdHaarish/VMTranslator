# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Haari\CLionProjects\VMTranslator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Haari\CLionProjects\VMTranslator\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/VMTranslator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/VMTranslator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VMTranslator.dir/flags.make

CMakeFiles/VMTranslator.dir/main.cpp.obj: CMakeFiles/VMTranslator.dir/flags.make
CMakeFiles/VMTranslator.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Haari\CLionProjects\VMTranslator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VMTranslator.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\VMTranslator.dir\main.cpp.obj -c C:\Users\Haari\CLionProjects\VMTranslator\main.cpp

CMakeFiles/VMTranslator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VMTranslator.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Haari\CLionProjects\VMTranslator\main.cpp > CMakeFiles\VMTranslator.dir\main.cpp.i

CMakeFiles/VMTranslator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VMTranslator.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Haari\CLionProjects\VMTranslator\main.cpp -o CMakeFiles\VMTranslator.dir\main.cpp.s

# Object files for target VMTranslator
VMTranslator_OBJECTS = \
"CMakeFiles/VMTranslator.dir/main.cpp.obj"

# External object files for target VMTranslator
VMTranslator_EXTERNAL_OBJECTS =

VMTranslator.exe: CMakeFiles/VMTranslator.dir/main.cpp.obj
VMTranslator.exe: CMakeFiles/VMTranslator.dir/build.make
VMTranslator.exe: CMakeFiles/VMTranslator.dir/linklibs.rsp
VMTranslator.exe: CMakeFiles/VMTranslator.dir/objects1.rsp
VMTranslator.exe: CMakeFiles/VMTranslator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Haari\CLionProjects\VMTranslator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable VMTranslator.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\VMTranslator.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VMTranslator.dir/build: VMTranslator.exe

.PHONY : CMakeFiles/VMTranslator.dir/build

CMakeFiles/VMTranslator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\VMTranslator.dir\cmake_clean.cmake
.PHONY : CMakeFiles/VMTranslator.dir/clean

CMakeFiles/VMTranslator.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Haari\CLionProjects\VMTranslator C:\Users\Haari\CLionProjects\VMTranslator C:\Users\Haari\CLionProjects\VMTranslator\cmake-build-debug C:\Users\Haari\CLionProjects\VMTranslator\cmake-build-debug C:\Users\Haari\CLionProjects\VMTranslator\cmake-build-debug\CMakeFiles\VMTranslator.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/VMTranslator.dir/depend

