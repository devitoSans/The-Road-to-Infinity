# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\devit\C++ Program VSCode\zOpenGL\PRACTICE"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\devit\C++ Program VSCode\zOpenGL\PRACTICE\build"

# Include any dependencies generated for this target.
include CMakeFiles/GLAD.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GLAD.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GLAD.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GLAD.dir/flags.make

CMakeFiles/GLAD.dir/glad.c.obj: CMakeFiles/GLAD.dir/flags.make
CMakeFiles/GLAD.dir/glad.c.obj: CMakeFiles/GLAD.dir/includes_C.rsp
CMakeFiles/GLAD.dir/glad.c.obj: C:/Users/devit/C++\ Program\ VSCode/zOpenGL/PRACTICE/glad.c
CMakeFiles/GLAD.dir/glad.c.obj: CMakeFiles/GLAD.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\devit\C++ Program VSCode\zOpenGL\PRACTICE\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/GLAD.dir/glad.c.obj"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GLAD.dir/glad.c.obj -MF CMakeFiles\GLAD.dir\glad.c.obj.d -o CMakeFiles\GLAD.dir\glad.c.obj -c "C:\Users\devit\C++ Program VSCode\zOpenGL\PRACTICE\glad.c"

CMakeFiles/GLAD.dir/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GLAD.dir/glad.c.i"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\devit\C++ Program VSCode\zOpenGL\PRACTICE\glad.c" > CMakeFiles\GLAD.dir\glad.c.i

CMakeFiles/GLAD.dir/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GLAD.dir/glad.c.s"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\devit\C++ Program VSCode\zOpenGL\PRACTICE\glad.c" -o CMakeFiles\GLAD.dir\glad.c.s

# Object files for target GLAD
GLAD_OBJECTS = \
"CMakeFiles/GLAD.dir/glad.c.obj"

# External object files for target GLAD
GLAD_EXTERNAL_OBJECTS =

libGLAD.a: CMakeFiles/GLAD.dir/glad.c.obj
libGLAD.a: CMakeFiles/GLAD.dir/build.make
libGLAD.a: CMakeFiles/GLAD.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\devit\C++ Program VSCode\zOpenGL\PRACTICE\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libGLAD.a"
	$(CMAKE_COMMAND) -P CMakeFiles\GLAD.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\GLAD.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GLAD.dir/build: libGLAD.a
.PHONY : CMakeFiles/GLAD.dir/build

CMakeFiles/GLAD.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GLAD.dir\cmake_clean.cmake
.PHONY : CMakeFiles/GLAD.dir/clean

CMakeFiles/GLAD.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\devit\C++ Program VSCode\zOpenGL\PRACTICE" "C:\Users\devit\C++ Program VSCode\zOpenGL\PRACTICE" "C:\Users\devit\C++ Program VSCode\zOpenGL\PRACTICE\build" "C:\Users\devit\C++ Program VSCode\zOpenGL\PRACTICE\build" "C:\Users\devit\C++ Program VSCode\zOpenGL\PRACTICE\build\CMakeFiles\GLAD.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/GLAD.dir/depend
