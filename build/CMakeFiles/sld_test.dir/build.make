# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jhoselbadillocortes/Documents/sdl_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jhoselbadillocortes/Documents/sdl_test/build

# Include any dependencies generated for this target.
include CMakeFiles/sld_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sld_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sld_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sld_test.dir/flags.make

CMakeFiles/sld_test.dir/main.cpp.o: CMakeFiles/sld_test.dir/flags.make
CMakeFiles/sld_test.dir/main.cpp.o: /Users/jhoselbadillocortes/Documents/sdl_test/main.cpp
CMakeFiles/sld_test.dir/main.cpp.o: CMakeFiles/sld_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jhoselbadillocortes/Documents/sdl_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sld_test.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sld_test.dir/main.cpp.o -MF CMakeFiles/sld_test.dir/main.cpp.o.d -o CMakeFiles/sld_test.dir/main.cpp.o -c /Users/jhoselbadillocortes/Documents/sdl_test/main.cpp

CMakeFiles/sld_test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sld_test.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jhoselbadillocortes/Documents/sdl_test/main.cpp > CMakeFiles/sld_test.dir/main.cpp.i

CMakeFiles/sld_test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sld_test.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jhoselbadillocortes/Documents/sdl_test/main.cpp -o CMakeFiles/sld_test.dir/main.cpp.s

CMakeFiles/sld_test.dir/player.cpp.o: CMakeFiles/sld_test.dir/flags.make
CMakeFiles/sld_test.dir/player.cpp.o: /Users/jhoselbadillocortes/Documents/sdl_test/player.cpp
CMakeFiles/sld_test.dir/player.cpp.o: CMakeFiles/sld_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jhoselbadillocortes/Documents/sdl_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sld_test.dir/player.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sld_test.dir/player.cpp.o -MF CMakeFiles/sld_test.dir/player.cpp.o.d -o CMakeFiles/sld_test.dir/player.cpp.o -c /Users/jhoselbadillocortes/Documents/sdl_test/player.cpp

CMakeFiles/sld_test.dir/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sld_test.dir/player.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jhoselbadillocortes/Documents/sdl_test/player.cpp > CMakeFiles/sld_test.dir/player.cpp.i

CMakeFiles/sld_test.dir/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sld_test.dir/player.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jhoselbadillocortes/Documents/sdl_test/player.cpp -o CMakeFiles/sld_test.dir/player.cpp.s

CMakeFiles/sld_test.dir/projectile.cpp.o: CMakeFiles/sld_test.dir/flags.make
CMakeFiles/sld_test.dir/projectile.cpp.o: /Users/jhoselbadillocortes/Documents/sdl_test/projectile.cpp
CMakeFiles/sld_test.dir/projectile.cpp.o: CMakeFiles/sld_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jhoselbadillocortes/Documents/sdl_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sld_test.dir/projectile.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sld_test.dir/projectile.cpp.o -MF CMakeFiles/sld_test.dir/projectile.cpp.o.d -o CMakeFiles/sld_test.dir/projectile.cpp.o -c /Users/jhoselbadillocortes/Documents/sdl_test/projectile.cpp

CMakeFiles/sld_test.dir/projectile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sld_test.dir/projectile.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jhoselbadillocortes/Documents/sdl_test/projectile.cpp > CMakeFiles/sld_test.dir/projectile.cpp.i

CMakeFiles/sld_test.dir/projectile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sld_test.dir/projectile.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jhoselbadillocortes/Documents/sdl_test/projectile.cpp -o CMakeFiles/sld_test.dir/projectile.cpp.s

CMakeFiles/sld_test.dir/enemy.cpp.o: CMakeFiles/sld_test.dir/flags.make
CMakeFiles/sld_test.dir/enemy.cpp.o: /Users/jhoselbadillocortes/Documents/sdl_test/enemy.cpp
CMakeFiles/sld_test.dir/enemy.cpp.o: CMakeFiles/sld_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jhoselbadillocortes/Documents/sdl_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sld_test.dir/enemy.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sld_test.dir/enemy.cpp.o -MF CMakeFiles/sld_test.dir/enemy.cpp.o.d -o CMakeFiles/sld_test.dir/enemy.cpp.o -c /Users/jhoselbadillocortes/Documents/sdl_test/enemy.cpp

CMakeFiles/sld_test.dir/enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sld_test.dir/enemy.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jhoselbadillocortes/Documents/sdl_test/enemy.cpp > CMakeFiles/sld_test.dir/enemy.cpp.i

CMakeFiles/sld_test.dir/enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sld_test.dir/enemy.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jhoselbadillocortes/Documents/sdl_test/enemy.cpp -o CMakeFiles/sld_test.dir/enemy.cpp.s

# Object files for target sld_test
sld_test_OBJECTS = \
"CMakeFiles/sld_test.dir/main.cpp.o" \
"CMakeFiles/sld_test.dir/player.cpp.o" \
"CMakeFiles/sld_test.dir/projectile.cpp.o" \
"CMakeFiles/sld_test.dir/enemy.cpp.o"

# External object files for target sld_test
sld_test_EXTERNAL_OBJECTS =

sld_test: CMakeFiles/sld_test.dir/main.cpp.o
sld_test: CMakeFiles/sld_test.dir/player.cpp.o
sld_test: CMakeFiles/sld_test.dir/projectile.cpp.o
sld_test: CMakeFiles/sld_test.dir/enemy.cpp.o
sld_test: CMakeFiles/sld_test.dir/build.make
sld_test: /opt/homebrew/lib/libSDL2.dylib
sld_test: /opt/homebrew/lib/libSDL2_ttf.dylib
sld_test: /opt/homebrew/lib/libSDL2_image.dylib
sld_test: CMakeFiles/sld_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/jhoselbadillocortes/Documents/sdl_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable sld_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sld_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sld_test.dir/build: sld_test
.PHONY : CMakeFiles/sld_test.dir/build

CMakeFiles/sld_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sld_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sld_test.dir/clean

CMakeFiles/sld_test.dir/depend:
	cd /Users/jhoselbadillocortes/Documents/sdl_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jhoselbadillocortes/Documents/sdl_test /Users/jhoselbadillocortes/Documents/sdl_test /Users/jhoselbadillocortes/Documents/sdl_test/build /Users/jhoselbadillocortes/Documents/sdl_test/build /Users/jhoselbadillocortes/Documents/sdl_test/build/CMakeFiles/sld_test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/sld_test.dir/depend

