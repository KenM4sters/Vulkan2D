# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/samuelbrookman/Desktop/Vulkan2D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/samuelbrookman/Desktop/Vulkan2D/build

# Include any dependencies generated for this target.
include CMakeFiles/Vulkan2D.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Vulkan2D.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Vulkan2D.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Vulkan2D.dir/flags.make

CMakeFiles/Vulkan2D.dir/main.cpp.o: CMakeFiles/Vulkan2D.dir/flags.make
CMakeFiles/Vulkan2D.dir/main.cpp.o: /Users/samuelbrookman/Desktop/Vulkan2D/main.cpp
CMakeFiles/Vulkan2D.dir/main.cpp.o: CMakeFiles/Vulkan2D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/samuelbrookman/Desktop/Vulkan2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Vulkan2D.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Vulkan2D.dir/main.cpp.o -MF CMakeFiles/Vulkan2D.dir/main.cpp.o.d -o CMakeFiles/Vulkan2D.dir/main.cpp.o -c /Users/samuelbrookman/Desktop/Vulkan2D/main.cpp

CMakeFiles/Vulkan2D.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Vulkan2D.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/samuelbrookman/Desktop/Vulkan2D/main.cpp > CMakeFiles/Vulkan2D.dir/main.cpp.i

CMakeFiles/Vulkan2D.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Vulkan2D.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/samuelbrookman/Desktop/Vulkan2D/main.cpp -o CMakeFiles/Vulkan2D.dir/main.cpp.s

CMakeFiles/Vulkan2D.dir/Sources/Program.cpp.o: CMakeFiles/Vulkan2D.dir/flags.make
CMakeFiles/Vulkan2D.dir/Sources/Program.cpp.o: /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Program.cpp
CMakeFiles/Vulkan2D.dir/Sources/Program.cpp.o: CMakeFiles/Vulkan2D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/samuelbrookman/Desktop/Vulkan2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Vulkan2D.dir/Sources/Program.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Vulkan2D.dir/Sources/Program.cpp.o -MF CMakeFiles/Vulkan2D.dir/Sources/Program.cpp.o.d -o CMakeFiles/Vulkan2D.dir/Sources/Program.cpp.o -c /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Program.cpp

CMakeFiles/Vulkan2D.dir/Sources/Program.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Vulkan2D.dir/Sources/Program.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Program.cpp > CMakeFiles/Vulkan2D.dir/Sources/Program.cpp.i

CMakeFiles/Vulkan2D.dir/Sources/Program.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Vulkan2D.dir/Sources/Program.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Program.cpp -o CMakeFiles/Vulkan2D.dir/Sources/Program.cpp.s

CMakeFiles/Vulkan2D.dir/Sources/Window.cpp.o: CMakeFiles/Vulkan2D.dir/flags.make
CMakeFiles/Vulkan2D.dir/Sources/Window.cpp.o: /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Window.cpp
CMakeFiles/Vulkan2D.dir/Sources/Window.cpp.o: CMakeFiles/Vulkan2D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/samuelbrookman/Desktop/Vulkan2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Vulkan2D.dir/Sources/Window.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Vulkan2D.dir/Sources/Window.cpp.o -MF CMakeFiles/Vulkan2D.dir/Sources/Window.cpp.o.d -o CMakeFiles/Vulkan2D.dir/Sources/Window.cpp.o -c /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Window.cpp

CMakeFiles/Vulkan2D.dir/Sources/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Vulkan2D.dir/Sources/Window.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Window.cpp > CMakeFiles/Vulkan2D.dir/Sources/Window.cpp.i

CMakeFiles/Vulkan2D.dir/Sources/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Vulkan2D.dir/Sources/Window.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Window.cpp -o CMakeFiles/Vulkan2D.dir/Sources/Window.cpp.s

CMakeFiles/Vulkan2D.dir/Sources/Pipeline.cpp.o: CMakeFiles/Vulkan2D.dir/flags.make
CMakeFiles/Vulkan2D.dir/Sources/Pipeline.cpp.o: /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Pipeline.cpp
CMakeFiles/Vulkan2D.dir/Sources/Pipeline.cpp.o: CMakeFiles/Vulkan2D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/samuelbrookman/Desktop/Vulkan2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Vulkan2D.dir/Sources/Pipeline.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Vulkan2D.dir/Sources/Pipeline.cpp.o -MF CMakeFiles/Vulkan2D.dir/Sources/Pipeline.cpp.o.d -o CMakeFiles/Vulkan2D.dir/Sources/Pipeline.cpp.o -c /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Pipeline.cpp

CMakeFiles/Vulkan2D.dir/Sources/Pipeline.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Vulkan2D.dir/Sources/Pipeline.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Pipeline.cpp > CMakeFiles/Vulkan2D.dir/Sources/Pipeline.cpp.i

CMakeFiles/Vulkan2D.dir/Sources/Pipeline.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Vulkan2D.dir/Sources/Pipeline.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Pipeline.cpp -o CMakeFiles/Vulkan2D.dir/Sources/Pipeline.cpp.s

CMakeFiles/Vulkan2D.dir/Sources/Device.cpp.o: CMakeFiles/Vulkan2D.dir/flags.make
CMakeFiles/Vulkan2D.dir/Sources/Device.cpp.o: /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Device.cpp
CMakeFiles/Vulkan2D.dir/Sources/Device.cpp.o: CMakeFiles/Vulkan2D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/samuelbrookman/Desktop/Vulkan2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Vulkan2D.dir/Sources/Device.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Vulkan2D.dir/Sources/Device.cpp.o -MF CMakeFiles/Vulkan2D.dir/Sources/Device.cpp.o.d -o CMakeFiles/Vulkan2D.dir/Sources/Device.cpp.o -c /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Device.cpp

CMakeFiles/Vulkan2D.dir/Sources/Device.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Vulkan2D.dir/Sources/Device.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Device.cpp > CMakeFiles/Vulkan2D.dir/Sources/Device.cpp.i

CMakeFiles/Vulkan2D.dir/Sources/Device.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Vulkan2D.dir/Sources/Device.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Device.cpp -o CMakeFiles/Vulkan2D.dir/Sources/Device.cpp.s

CMakeFiles/Vulkan2D.dir/Sources/SwapChain.cpp.o: CMakeFiles/Vulkan2D.dir/flags.make
CMakeFiles/Vulkan2D.dir/Sources/SwapChain.cpp.o: /Users/samuelbrookman/Desktop/Vulkan2D/Sources/SwapChain.cpp
CMakeFiles/Vulkan2D.dir/Sources/SwapChain.cpp.o: CMakeFiles/Vulkan2D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/samuelbrookman/Desktop/Vulkan2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Vulkan2D.dir/Sources/SwapChain.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Vulkan2D.dir/Sources/SwapChain.cpp.o -MF CMakeFiles/Vulkan2D.dir/Sources/SwapChain.cpp.o.d -o CMakeFiles/Vulkan2D.dir/Sources/SwapChain.cpp.o -c /Users/samuelbrookman/Desktop/Vulkan2D/Sources/SwapChain.cpp

CMakeFiles/Vulkan2D.dir/Sources/SwapChain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Vulkan2D.dir/Sources/SwapChain.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/samuelbrookman/Desktop/Vulkan2D/Sources/SwapChain.cpp > CMakeFiles/Vulkan2D.dir/Sources/SwapChain.cpp.i

CMakeFiles/Vulkan2D.dir/Sources/SwapChain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Vulkan2D.dir/Sources/SwapChain.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/samuelbrookman/Desktop/Vulkan2D/Sources/SwapChain.cpp -o CMakeFiles/Vulkan2D.dir/Sources/SwapChain.cpp.s

CMakeFiles/Vulkan2D.dir/Sources/Camera.cpp.o: CMakeFiles/Vulkan2D.dir/flags.make
CMakeFiles/Vulkan2D.dir/Sources/Camera.cpp.o: /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Camera.cpp
CMakeFiles/Vulkan2D.dir/Sources/Camera.cpp.o: CMakeFiles/Vulkan2D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/samuelbrookman/Desktop/Vulkan2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Vulkan2D.dir/Sources/Camera.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Vulkan2D.dir/Sources/Camera.cpp.o -MF CMakeFiles/Vulkan2D.dir/Sources/Camera.cpp.o.d -o CMakeFiles/Vulkan2D.dir/Sources/Camera.cpp.o -c /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Camera.cpp

CMakeFiles/Vulkan2D.dir/Sources/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Vulkan2D.dir/Sources/Camera.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Camera.cpp > CMakeFiles/Vulkan2D.dir/Sources/Camera.cpp.i

CMakeFiles/Vulkan2D.dir/Sources/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Vulkan2D.dir/Sources/Camera.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Camera.cpp -o CMakeFiles/Vulkan2D.dir/Sources/Camera.cpp.s

CMakeFiles/Vulkan2D.dir/Sources/Renderer.cpp.o: CMakeFiles/Vulkan2D.dir/flags.make
CMakeFiles/Vulkan2D.dir/Sources/Renderer.cpp.o: /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Renderer.cpp
CMakeFiles/Vulkan2D.dir/Sources/Renderer.cpp.o: CMakeFiles/Vulkan2D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/samuelbrookman/Desktop/Vulkan2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Vulkan2D.dir/Sources/Renderer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Vulkan2D.dir/Sources/Renderer.cpp.o -MF CMakeFiles/Vulkan2D.dir/Sources/Renderer.cpp.o.d -o CMakeFiles/Vulkan2D.dir/Sources/Renderer.cpp.o -c /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Renderer.cpp

CMakeFiles/Vulkan2D.dir/Sources/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Vulkan2D.dir/Sources/Renderer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Renderer.cpp > CMakeFiles/Vulkan2D.dir/Sources/Renderer.cpp.i

CMakeFiles/Vulkan2D.dir/Sources/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Vulkan2D.dir/Sources/Renderer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/samuelbrookman/Desktop/Vulkan2D/Sources/Renderer.cpp -o CMakeFiles/Vulkan2D.dir/Sources/Renderer.cpp.s

CMakeFiles/Vulkan2D.dir/Sources/RenderSystems/PlayerSystem.cpp.o: CMakeFiles/Vulkan2D.dir/flags.make
CMakeFiles/Vulkan2D.dir/Sources/RenderSystems/PlayerSystem.cpp.o: /Users/samuelbrookman/Desktop/Vulkan2D/Sources/RenderSystems/PlayerSystem.cpp
CMakeFiles/Vulkan2D.dir/Sources/RenderSystems/PlayerSystem.cpp.o: CMakeFiles/Vulkan2D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/samuelbrookman/Desktop/Vulkan2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Vulkan2D.dir/Sources/RenderSystems/PlayerSystem.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Vulkan2D.dir/Sources/RenderSystems/PlayerSystem.cpp.o -MF CMakeFiles/Vulkan2D.dir/Sources/RenderSystems/PlayerSystem.cpp.o.d -o CMakeFiles/Vulkan2D.dir/Sources/RenderSystems/PlayerSystem.cpp.o -c /Users/samuelbrookman/Desktop/Vulkan2D/Sources/RenderSystems/PlayerSystem.cpp

CMakeFiles/Vulkan2D.dir/Sources/RenderSystems/PlayerSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Vulkan2D.dir/Sources/RenderSystems/PlayerSystem.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/samuelbrookman/Desktop/Vulkan2D/Sources/RenderSystems/PlayerSystem.cpp > CMakeFiles/Vulkan2D.dir/Sources/RenderSystems/PlayerSystem.cpp.i

CMakeFiles/Vulkan2D.dir/Sources/RenderSystems/PlayerSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Vulkan2D.dir/Sources/RenderSystems/PlayerSystem.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/samuelbrookman/Desktop/Vulkan2D/Sources/RenderSystems/PlayerSystem.cpp -o CMakeFiles/Vulkan2D.dir/Sources/RenderSystems/PlayerSystem.cpp.s

# Object files for target Vulkan2D
Vulkan2D_OBJECTS = \
"CMakeFiles/Vulkan2D.dir/main.cpp.o" \
"CMakeFiles/Vulkan2D.dir/Sources/Program.cpp.o" \
"CMakeFiles/Vulkan2D.dir/Sources/Window.cpp.o" \
"CMakeFiles/Vulkan2D.dir/Sources/Pipeline.cpp.o" \
"CMakeFiles/Vulkan2D.dir/Sources/Device.cpp.o" \
"CMakeFiles/Vulkan2D.dir/Sources/SwapChain.cpp.o" \
"CMakeFiles/Vulkan2D.dir/Sources/Camera.cpp.o" \
"CMakeFiles/Vulkan2D.dir/Sources/Renderer.cpp.o" \
"CMakeFiles/Vulkan2D.dir/Sources/RenderSystems/PlayerSystem.cpp.o"

# External object files for target Vulkan2D
Vulkan2D_EXTERNAL_OBJECTS =

Vulkan2D: CMakeFiles/Vulkan2D.dir/main.cpp.o
Vulkan2D: CMakeFiles/Vulkan2D.dir/Sources/Program.cpp.o
Vulkan2D: CMakeFiles/Vulkan2D.dir/Sources/Window.cpp.o
Vulkan2D: CMakeFiles/Vulkan2D.dir/Sources/Pipeline.cpp.o
Vulkan2D: CMakeFiles/Vulkan2D.dir/Sources/Device.cpp.o
Vulkan2D: CMakeFiles/Vulkan2D.dir/Sources/SwapChain.cpp.o
Vulkan2D: CMakeFiles/Vulkan2D.dir/Sources/Camera.cpp.o
Vulkan2D: CMakeFiles/Vulkan2D.dir/Sources/Renderer.cpp.o
Vulkan2D: CMakeFiles/Vulkan2D.dir/Sources/RenderSystems/PlayerSystem.cpp.o
Vulkan2D: CMakeFiles/Vulkan2D.dir/build.make
Vulkan2D: External/glfw/src/libglfw3.a
Vulkan2D: /usr/local/lib/libvulkan.dylib
Vulkan2D: CMakeFiles/Vulkan2D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/samuelbrookman/Desktop/Vulkan2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable Vulkan2D"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Vulkan2D.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Vulkan2D.dir/build: Vulkan2D
.PHONY : CMakeFiles/Vulkan2D.dir/build

CMakeFiles/Vulkan2D.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Vulkan2D.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Vulkan2D.dir/clean

CMakeFiles/Vulkan2D.dir/depend:
	cd /Users/samuelbrookman/Desktop/Vulkan2D/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/samuelbrookman/Desktop/Vulkan2D /Users/samuelbrookman/Desktop/Vulkan2D /Users/samuelbrookman/Desktop/Vulkan2D/build /Users/samuelbrookman/Desktop/Vulkan2D/build /Users/samuelbrookman/Desktop/Vulkan2D/build/CMakeFiles/Vulkan2D.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Vulkan2D.dir/depend

