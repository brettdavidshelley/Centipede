# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = "C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\build"

# Include any dependencies generated for this target.
include centipede/CMakeFiles/centipede.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include centipede/CMakeFiles/centipede.dir/compiler_depend.make

# Include the progress variables for this target.
include centipede/CMakeFiles/centipede.dir/progress.make

# Include the compile flags for this target's objects.
include centipede/CMakeFiles/centipede.dir/flags.make

centipede/CMakeFiles/centipede.dir/code/Centipede.cpp.obj: centipede/CMakeFiles/centipede.dir/flags.make
centipede/CMakeFiles/centipede.dir/code/Centipede.cpp.obj: centipede/CMakeFiles/centipede.dir/includes_CXX.rsp
centipede/CMakeFiles/centipede.dir/code/Centipede.cpp.obj: C:/Users/brett/OneDrive/Desktop/Projects/Software/Centipede\ Arcade\ Game/Current\ Version/centipede/code/Centipede.cpp
centipede/CMakeFiles/centipede.dir/code/Centipede.cpp.obj: centipede/CMakeFiles/centipede.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object centipede/CMakeFiles/centipede.dir/code/Centipede.cpp.obj"
	cd /d C:\Users\brett\OneDrive\Desktop\Projects\Software\CENTIP~1\CURREN~1\build\CENTIP~1 && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT centipede/CMakeFiles/centipede.dir/code/Centipede.cpp.obj -MF CMakeFiles\centipede.dir\code\Centipede.cpp.obj.d -o CMakeFiles\centipede.dir\code\Centipede.cpp.obj -c "C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\centipede\code\Centipede.cpp"

centipede/CMakeFiles/centipede.dir/code/Centipede.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/centipede.dir/code/Centipede.cpp.i"
	cd /d C:\Users\brett\OneDrive\Desktop\Projects\Software\CENTIP~1\CURREN~1\build\CENTIP~1 && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\centipede\code\Centipede.cpp" > CMakeFiles\centipede.dir\code\Centipede.cpp.i

centipede/CMakeFiles/centipede.dir/code/Centipede.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/centipede.dir/code/Centipede.cpp.s"
	cd /d C:\Users\brett\OneDrive\Desktop\Projects\Software\CENTIP~1\CURREN~1\build\CENTIP~1 && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\centipede\code\Centipede.cpp" -o CMakeFiles\centipede.dir\code\Centipede.cpp.s

centipede/CMakeFiles/centipede.dir/code/ECE_Centipede.cpp.obj: centipede/CMakeFiles/centipede.dir/flags.make
centipede/CMakeFiles/centipede.dir/code/ECE_Centipede.cpp.obj: centipede/CMakeFiles/centipede.dir/includes_CXX.rsp
centipede/CMakeFiles/centipede.dir/code/ECE_Centipede.cpp.obj: C:/Users/brett/OneDrive/Desktop/Projects/Software/Centipede\ Arcade\ Game/Current\ Version/centipede/code/ECE_Centipede.cpp
centipede/CMakeFiles/centipede.dir/code/ECE_Centipede.cpp.obj: centipede/CMakeFiles/centipede.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object centipede/CMakeFiles/centipede.dir/code/ECE_Centipede.cpp.obj"
	cd /d C:\Users\brett\OneDrive\Desktop\Projects\Software\CENTIP~1\CURREN~1\build\CENTIP~1 && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT centipede/CMakeFiles/centipede.dir/code/ECE_Centipede.cpp.obj -MF CMakeFiles\centipede.dir\code\ECE_Centipede.cpp.obj.d -o CMakeFiles\centipede.dir\code\ECE_Centipede.cpp.obj -c "C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\centipede\code\ECE_Centipede.cpp"

centipede/CMakeFiles/centipede.dir/code/ECE_Centipede.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/centipede.dir/code/ECE_Centipede.cpp.i"
	cd /d C:\Users\brett\OneDrive\Desktop\Projects\Software\CENTIP~1\CURREN~1\build\CENTIP~1 && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\centipede\code\ECE_Centipede.cpp" > CMakeFiles\centipede.dir\code\ECE_Centipede.cpp.i

centipede/CMakeFiles/centipede.dir/code/ECE_Centipede.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/centipede.dir/code/ECE_Centipede.cpp.s"
	cd /d C:\Users\brett\OneDrive\Desktop\Projects\Software\CENTIP~1\CURREN~1\build\CENTIP~1 && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\centipede\code\ECE_Centipede.cpp" -o CMakeFiles\centipede.dir\code\ECE_Centipede.cpp.s

centipede/CMakeFiles/centipede.dir/code/ECE_LaserBlast.cpp.obj: centipede/CMakeFiles/centipede.dir/flags.make
centipede/CMakeFiles/centipede.dir/code/ECE_LaserBlast.cpp.obj: centipede/CMakeFiles/centipede.dir/includes_CXX.rsp
centipede/CMakeFiles/centipede.dir/code/ECE_LaserBlast.cpp.obj: C:/Users/brett/OneDrive/Desktop/Projects/Software/Centipede\ Arcade\ Game/Current\ Version/centipede/code/ECE_LaserBlast.cpp
centipede/CMakeFiles/centipede.dir/code/ECE_LaserBlast.cpp.obj: centipede/CMakeFiles/centipede.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object centipede/CMakeFiles/centipede.dir/code/ECE_LaserBlast.cpp.obj"
	cd /d C:\Users\brett\OneDrive\Desktop\Projects\Software\CENTIP~1\CURREN~1\build\CENTIP~1 && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT centipede/CMakeFiles/centipede.dir/code/ECE_LaserBlast.cpp.obj -MF CMakeFiles\centipede.dir\code\ECE_LaserBlast.cpp.obj.d -o CMakeFiles\centipede.dir\code\ECE_LaserBlast.cpp.obj -c "C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\centipede\code\ECE_LaserBlast.cpp"

centipede/CMakeFiles/centipede.dir/code/ECE_LaserBlast.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/centipede.dir/code/ECE_LaserBlast.cpp.i"
	cd /d C:\Users\brett\OneDrive\Desktop\Projects\Software\CENTIP~1\CURREN~1\build\CENTIP~1 && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\centipede\code\ECE_LaserBlast.cpp" > CMakeFiles\centipede.dir\code\ECE_LaserBlast.cpp.i

centipede/CMakeFiles/centipede.dir/code/ECE_LaserBlast.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/centipede.dir/code/ECE_LaserBlast.cpp.s"
	cd /d C:\Users\brett\OneDrive\Desktop\Projects\Software\CENTIP~1\CURREN~1\build\CENTIP~1 && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\centipede\code\ECE_LaserBlast.cpp" -o CMakeFiles\centipede.dir\code\ECE_LaserBlast.cpp.s

centipede/CMakeFiles/centipede.dir/code/Spider.cpp.obj: centipede/CMakeFiles/centipede.dir/flags.make
centipede/CMakeFiles/centipede.dir/code/Spider.cpp.obj: centipede/CMakeFiles/centipede.dir/includes_CXX.rsp
centipede/CMakeFiles/centipede.dir/code/Spider.cpp.obj: C:/Users/brett/OneDrive/Desktop/Projects/Software/Centipede\ Arcade\ Game/Current\ Version/centipede/code/Spider.cpp
centipede/CMakeFiles/centipede.dir/code/Spider.cpp.obj: centipede/CMakeFiles/centipede.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object centipede/CMakeFiles/centipede.dir/code/Spider.cpp.obj"
	cd /d C:\Users\brett\OneDrive\Desktop\Projects\Software\CENTIP~1\CURREN~1\build\CENTIP~1 && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT centipede/CMakeFiles/centipede.dir/code/Spider.cpp.obj -MF CMakeFiles\centipede.dir\code\Spider.cpp.obj.d -o CMakeFiles\centipede.dir\code\Spider.cpp.obj -c "C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\centipede\code\Spider.cpp"

centipede/CMakeFiles/centipede.dir/code/Spider.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/centipede.dir/code/Spider.cpp.i"
	cd /d C:\Users\brett\OneDrive\Desktop\Projects\Software\CENTIP~1\CURREN~1\build\CENTIP~1 && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\centipede\code\Spider.cpp" > CMakeFiles\centipede.dir\code\Spider.cpp.i

centipede/CMakeFiles/centipede.dir/code/Spider.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/centipede.dir/code/Spider.cpp.s"
	cd /d C:\Users\brett\OneDrive\Desktop\Projects\Software\CENTIP~1\CURREN~1\build\CENTIP~1 && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\centipede\code\Spider.cpp" -o CMakeFiles\centipede.dir\code\Spider.cpp.s

# Object files for target centipede
centipede_OBJECTS = \
"CMakeFiles/centipede.dir/code/Centipede.cpp.obj" \
"CMakeFiles/centipede.dir/code/ECE_Centipede.cpp.obj" \
"CMakeFiles/centipede.dir/code/ECE_LaserBlast.cpp.obj" \
"CMakeFiles/centipede.dir/code/Spider.cpp.obj"

# External object files for target centipede
centipede_EXTERNAL_OBJECTS =

output/bin/centipede.exe: centipede/CMakeFiles/centipede.dir/code/Centipede.cpp.obj
output/bin/centipede.exe: centipede/CMakeFiles/centipede.dir/code/ECE_Centipede.cpp.obj
output/bin/centipede.exe: centipede/CMakeFiles/centipede.dir/code/ECE_LaserBlast.cpp.obj
output/bin/centipede.exe: centipede/CMakeFiles/centipede.dir/code/Spider.cpp.obj
output/bin/centipede.exe: centipede/CMakeFiles/centipede.dir/build.make
output/bin/centipede.exe: output/lib/libsfml-graphics-d.a
output/bin/centipede.exe: output/lib/libsfml-window-d.a
output/bin/centipede.exe: output/lib/libsfml-system-d.a
output/bin/centipede.exe: centipede/CMakeFiles/centipede.dir/linkLibs.rsp
output/bin/centipede.exe: centipede/CMakeFiles/centipede.dir/objects1.rsp
output/bin/centipede.exe: centipede/CMakeFiles/centipede.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ..\output\bin\centipede.exe"
	cd /d C:\Users\brett\OneDrive\Desktop\Projects\Software\CENTIP~1\CURREN~1\build\CENTIP~1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\centipede.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
centipede/CMakeFiles/centipede.dir/build: output/bin/centipede.exe
.PHONY : centipede/CMakeFiles/centipede.dir/build

centipede/CMakeFiles/centipede.dir/clean:
	cd /d C:\Users\brett\OneDrive\Desktop\Projects\Software\CENTIP~1\CURREN~1\build\CENTIP~1 && $(CMAKE_COMMAND) -P CMakeFiles\centipede.dir\cmake_clean.cmake
.PHONY : centipede/CMakeFiles/centipede.dir/clean

centipede/CMakeFiles/centipede.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version" "C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\centipede" "C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\build" "C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\build\centipede" "C:\Users\brett\OneDrive\Desktop\Projects\Software\Centipede Arcade Game\Current Version\build\centipede\CMakeFiles\centipede.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : centipede/CMakeFiles/centipede.dir/depend

