# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib

# Include any dependencies generated for this target.
include deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/depend.make

# Include the progress variables for this target.
include deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/progress.make

# Include the compile flags for this target's objects.
include deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/flags.make

deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.o: deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/flags.make
deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.o: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/deadAndNoisyTools/src/testSimpleMapper.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.o"
	cd /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/deadAndNoisyTools/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.o -c /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/deadAndNoisyTools/src/testSimpleMapper.cpp

deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.i"
	cd /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/deadAndNoisyTools/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/deadAndNoisyTools/src/testSimpleMapper.cpp > CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.i

deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.s"
	cd /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/deadAndNoisyTools/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/deadAndNoisyTools/src/testSimpleMapper.cpp -o CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.s

deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.o.requires:
.PHONY : deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.o.requires

deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.o.provides: deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.o.requires
	$(MAKE) -f deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/build.make deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.o.provides.build
.PHONY : deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.o.provides

deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.o.provides.build: deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.o

# Object files for target testSimpleMapper
testSimpleMapper_OBJECTS = \
"CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.o"

# External object files for target testSimpleMapper
testSimpleMapper_EXTERNAL_OBJECTS =

bin/testSimpleMapper: deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.o
bin/testSimpleMapper: deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/build.make
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libCore.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libCint.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libRIO.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libNet.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libHist.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libGraf.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libGraf3d.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libGpad.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libTree.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libRint.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libPostscript.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libMatrix.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libPhysics.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libMathCore.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libThread.so
bin/testSimpleMapper: /usr/lib64/libdl.so
bin/testSimpleMapper: lib/libDeadAndNoisyTools.so.1.1.0
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libCore.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libCint.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libRIO.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libNet.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libHist.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libGraf.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libGraf3d.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libGpad.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libTree.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libRint.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libPostscript.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libMatrix.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libPhysics.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libMathCore.so
bin/testSimpleMapper: /afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib/libThread.so
bin/testSimpleMapper: /usr/lib64/libdl.so
bin/testSimpleMapper: deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/testSimpleMapper"
	cd /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/deadAndNoisyTools/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testSimpleMapper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/build: bin/testSimpleMapper
.PHONY : deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/build

deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/requires: deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/testSimpleMapper.cpp.o.requires
.PHONY : deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/requires

deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/clean:
	cd /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/deadAndNoisyTools/src && $(CMAKE_COMMAND) -P CMakeFiles/testSimpleMapper.dir/cmake_clean.cmake
.PHONY : deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/clean

deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/depend:
	cd /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/deadAndNoisyTools/src /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/deadAndNoisyTools/src /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : deadAndNoisyTools/src/CMakeFiles/testSimpleMapper.dir/depend
