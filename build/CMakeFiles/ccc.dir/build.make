# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = D:\QT\Tools\CMake_64\bin\cmake.exe

# The command to remove a file.
RM = D:\QT\Tools\CMake_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\zdj\Automata (3)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\zdj\Automata (3)\build"

# Include any dependencies generated for this target.
include CMakeFiles/ccc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ccc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ccc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ccc.dir/flags.make

CMakeFiles/ccc.dir/main.cpp.obj: CMakeFiles/ccc.dir/flags.make
CMakeFiles/ccc.dir/main.cpp.obj: CMakeFiles/ccc.dir/includes_CXX.rsp
CMakeFiles/ccc.dir/main.cpp.obj: E:/zdj/Automata\ (3)/main.cpp
CMakeFiles/ccc.dir/main.cpp.obj: CMakeFiles/ccc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\zdj\Automata (3)\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ccc.dir/main.cpp.obj"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ccc.dir/main.cpp.obj -MF CMakeFiles\ccc.dir\main.cpp.obj.d -o CMakeFiles\ccc.dir\main.cpp.obj -c "E:\zdj\Automata (3)\main.cpp"

CMakeFiles/ccc.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ccc.dir/main.cpp.i"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\zdj\Automata (3)\main.cpp" > CMakeFiles\ccc.dir\main.cpp.i

CMakeFiles/ccc.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ccc.dir/main.cpp.s"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\zdj\Automata (3)\main.cpp" -o CMakeFiles\ccc.dir\main.cpp.s

CMakeFiles/ccc.dir/DFA.cpp.obj: CMakeFiles/ccc.dir/flags.make
CMakeFiles/ccc.dir/DFA.cpp.obj: CMakeFiles/ccc.dir/includes_CXX.rsp
CMakeFiles/ccc.dir/DFA.cpp.obj: E:/zdj/Automata\ (3)/DFA.cpp
CMakeFiles/ccc.dir/DFA.cpp.obj: CMakeFiles/ccc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\zdj\Automata (3)\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ccc.dir/DFA.cpp.obj"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ccc.dir/DFA.cpp.obj -MF CMakeFiles\ccc.dir\DFA.cpp.obj.d -o CMakeFiles\ccc.dir\DFA.cpp.obj -c "E:\zdj\Automata (3)\DFA.cpp"

CMakeFiles/ccc.dir/DFA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ccc.dir/DFA.cpp.i"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\zdj\Automata (3)\DFA.cpp" > CMakeFiles\ccc.dir\DFA.cpp.i

CMakeFiles/ccc.dir/DFA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ccc.dir/DFA.cpp.s"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\zdj\Automata (3)\DFA.cpp" -o CMakeFiles\ccc.dir\DFA.cpp.s

CMakeFiles/ccc.dir/NFA.cpp.obj: CMakeFiles/ccc.dir/flags.make
CMakeFiles/ccc.dir/NFA.cpp.obj: CMakeFiles/ccc.dir/includes_CXX.rsp
CMakeFiles/ccc.dir/NFA.cpp.obj: E:/zdj/Automata\ (3)/NFA.cpp
CMakeFiles/ccc.dir/NFA.cpp.obj: CMakeFiles/ccc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\zdj\Automata (3)\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ccc.dir/NFA.cpp.obj"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ccc.dir/NFA.cpp.obj -MF CMakeFiles\ccc.dir\NFA.cpp.obj.d -o CMakeFiles\ccc.dir\NFA.cpp.obj -c "E:\zdj\Automata (3)\NFA.cpp"

CMakeFiles/ccc.dir/NFA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ccc.dir/NFA.cpp.i"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\zdj\Automata (3)\NFA.cpp" > CMakeFiles\ccc.dir\NFA.cpp.i

CMakeFiles/ccc.dir/NFA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ccc.dir/NFA.cpp.s"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\zdj\Automata (3)\NFA.cpp" -o CMakeFiles\ccc.dir\NFA.cpp.s

CMakeFiles/ccc.dir/State.cpp.obj: CMakeFiles/ccc.dir/flags.make
CMakeFiles/ccc.dir/State.cpp.obj: CMakeFiles/ccc.dir/includes_CXX.rsp
CMakeFiles/ccc.dir/State.cpp.obj: E:/zdj/Automata\ (3)/State.cpp
CMakeFiles/ccc.dir/State.cpp.obj: CMakeFiles/ccc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\zdj\Automata (3)\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ccc.dir/State.cpp.obj"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ccc.dir/State.cpp.obj -MF CMakeFiles\ccc.dir\State.cpp.obj.d -o CMakeFiles\ccc.dir\State.cpp.obj -c "E:\zdj\Automata (3)\State.cpp"

CMakeFiles/ccc.dir/State.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ccc.dir/State.cpp.i"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\zdj\Automata (3)\State.cpp" > CMakeFiles\ccc.dir\State.cpp.i

CMakeFiles/ccc.dir/State.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ccc.dir/State.cpp.s"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\zdj\Automata (3)\State.cpp" -o CMakeFiles\ccc.dir\State.cpp.s

CMakeFiles/ccc.dir/Transition.cpp.obj: CMakeFiles/ccc.dir/flags.make
CMakeFiles/ccc.dir/Transition.cpp.obj: CMakeFiles/ccc.dir/includes_CXX.rsp
CMakeFiles/ccc.dir/Transition.cpp.obj: E:/zdj/Automata\ (3)/Transition.cpp
CMakeFiles/ccc.dir/Transition.cpp.obj: CMakeFiles/ccc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\zdj\Automata (3)\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ccc.dir/Transition.cpp.obj"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ccc.dir/Transition.cpp.obj -MF CMakeFiles\ccc.dir\Transition.cpp.obj.d -o CMakeFiles\ccc.dir\Transition.cpp.obj -c "E:\zdj\Automata (3)\Transition.cpp"

CMakeFiles/ccc.dir/Transition.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ccc.dir/Transition.cpp.i"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\zdj\Automata (3)\Transition.cpp" > CMakeFiles\ccc.dir\Transition.cpp.i

CMakeFiles/ccc.dir/Transition.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ccc.dir/Transition.cpp.s"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\zdj\Automata (3)\Transition.cpp" -o CMakeFiles\ccc.dir\Transition.cpp.s

CMakeFiles/ccc.dir/RG.cpp.obj: CMakeFiles/ccc.dir/flags.make
CMakeFiles/ccc.dir/RG.cpp.obj: CMakeFiles/ccc.dir/includes_CXX.rsp
CMakeFiles/ccc.dir/RG.cpp.obj: E:/zdj/Automata\ (3)/RG.cpp
CMakeFiles/ccc.dir/RG.cpp.obj: CMakeFiles/ccc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\zdj\Automata (3)\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ccc.dir/RG.cpp.obj"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ccc.dir/RG.cpp.obj -MF CMakeFiles\ccc.dir\RG.cpp.obj.d -o CMakeFiles\ccc.dir\RG.cpp.obj -c "E:\zdj\Automata (3)\RG.cpp"

CMakeFiles/ccc.dir/RG.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ccc.dir/RG.cpp.i"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\zdj\Automata (3)\RG.cpp" > CMakeFiles\ccc.dir\RG.cpp.i

CMakeFiles/ccc.dir/RG.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ccc.dir/RG.cpp.s"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\zdj\Automata (3)\RG.cpp" -o CMakeFiles\ccc.dir\RG.cpp.s

CMakeFiles/ccc.dir/FA.cpp.obj: CMakeFiles/ccc.dir/flags.make
CMakeFiles/ccc.dir/FA.cpp.obj: CMakeFiles/ccc.dir/includes_CXX.rsp
CMakeFiles/ccc.dir/FA.cpp.obj: E:/zdj/Automata\ (3)/FA.cpp
CMakeFiles/ccc.dir/FA.cpp.obj: CMakeFiles/ccc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\zdj\Automata (3)\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ccc.dir/FA.cpp.obj"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ccc.dir/FA.cpp.obj -MF CMakeFiles\ccc.dir\FA.cpp.obj.d -o CMakeFiles\ccc.dir\FA.cpp.obj -c "E:\zdj\Automata (3)\FA.cpp"

CMakeFiles/ccc.dir/FA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ccc.dir/FA.cpp.i"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\zdj\Automata (3)\FA.cpp" > CMakeFiles\ccc.dir\FA.cpp.i

CMakeFiles/ccc.dir/FA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ccc.dir/FA.cpp.s"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\zdj\Automata (3)\FA.cpp" -o CMakeFiles\ccc.dir\FA.cpp.s

CMakeFiles/ccc.dir/helper.cpp.obj: CMakeFiles/ccc.dir/flags.make
CMakeFiles/ccc.dir/helper.cpp.obj: CMakeFiles/ccc.dir/includes_CXX.rsp
CMakeFiles/ccc.dir/helper.cpp.obj: E:/zdj/Automata\ (3)/helper.cpp
CMakeFiles/ccc.dir/helper.cpp.obj: CMakeFiles/ccc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\zdj\Automata (3)\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ccc.dir/helper.cpp.obj"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ccc.dir/helper.cpp.obj -MF CMakeFiles\ccc.dir\helper.cpp.obj.d -o CMakeFiles\ccc.dir\helper.cpp.obj -c "E:\zdj\Automata (3)\helper.cpp"

CMakeFiles/ccc.dir/helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ccc.dir/helper.cpp.i"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\zdj\Automata (3)\helper.cpp" > CMakeFiles\ccc.dir\helper.cpp.i

CMakeFiles/ccc.dir/helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ccc.dir/helper.cpp.s"
	D:\QT\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\zdj\Automata (3)\helper.cpp" -o CMakeFiles\ccc.dir\helper.cpp.s

# Object files for target ccc
ccc_OBJECTS = \
"CMakeFiles/ccc.dir/main.cpp.obj" \
"CMakeFiles/ccc.dir/DFA.cpp.obj" \
"CMakeFiles/ccc.dir/NFA.cpp.obj" \
"CMakeFiles/ccc.dir/State.cpp.obj" \
"CMakeFiles/ccc.dir/Transition.cpp.obj" \
"CMakeFiles/ccc.dir/RG.cpp.obj" \
"CMakeFiles/ccc.dir/FA.cpp.obj" \
"CMakeFiles/ccc.dir/helper.cpp.obj"

# External object files for target ccc
ccc_EXTERNAL_OBJECTS =

ccc.exe: CMakeFiles/ccc.dir/main.cpp.obj
ccc.exe: CMakeFiles/ccc.dir/DFA.cpp.obj
ccc.exe: CMakeFiles/ccc.dir/NFA.cpp.obj
ccc.exe: CMakeFiles/ccc.dir/State.cpp.obj
ccc.exe: CMakeFiles/ccc.dir/Transition.cpp.obj
ccc.exe: CMakeFiles/ccc.dir/RG.cpp.obj
ccc.exe: CMakeFiles/ccc.dir/FA.cpp.obj
ccc.exe: CMakeFiles/ccc.dir/helper.cpp.obj
ccc.exe: CMakeFiles/ccc.dir/build.make
ccc.exe: CMakeFiles/ccc.dir/linklibs.rsp
ccc.exe: CMakeFiles/ccc.dir/objects1.rsp
ccc.exe: CMakeFiles/ccc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\zdj\Automata (3)\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable ccc.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ccc.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ccc.dir/build: ccc.exe
.PHONY : CMakeFiles/ccc.dir/build

CMakeFiles/ccc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ccc.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ccc.dir/clean

CMakeFiles/ccc.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\zdj\Automata (3)" "E:\zdj\Automata (3)" "E:\zdj\Automata (3)\build" "E:\zdj\Automata (3)\build" "E:\zdj\Automata (3)\build\CMakeFiles\ccc.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ccc.dir/depend

