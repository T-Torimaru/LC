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

# Utility rule file for doc_FITMIP.

# Include the progress variables for this target.
include fitmip/CMakeFiles/doc_FITMIP.dir/progress.make

fitmip/CMakeFiles/doc_FITMIP: doc/FITMIP/html/index.html

doc/FITMIP/html/index.html: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/fitmip/doc/Doxyfile.in
doc/FITMIP/html/index.html: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/fitmip/include/Bezier.hh
doc/FITMIP/html/index.html: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/fitmip/include/Fitlikelihood.hh
doc/FITMIP/html/index.html: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/fitmip/include/Langaus.hh
doc/FITMIP/html/index.html: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/fitmip/src/Bezier.cc
doc/FITMIP/html/index.html: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/fitmip/src/Fitlikelihood.cc
doc/FITMIP/html/index.html: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/fitmip/src/Langaus.cc
doc/FITMIP/html/index.html: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/fitmip/src/fitMIP.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Building API Documentation for FITMIP..."
	cd /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/doc/FITMIP && /usr/bin/doxygen

doc_FITMIP: fitmip/CMakeFiles/doc_FITMIP
doc_FITMIP: doc/FITMIP/html/index.html
doc_FITMIP: fitmip/CMakeFiles/doc_FITMIP.dir/build.make
.PHONY : doc_FITMIP

# Rule to build all files generated by this target.
fitmip/CMakeFiles/doc_FITMIP.dir/build: doc_FITMIP
.PHONY : fitmip/CMakeFiles/doc_FITMIP.dir/build

fitmip/CMakeFiles/doc_FITMIP.dir/clean:
	cd /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/fitmip && $(CMAKE_COMMAND) -P CMakeFiles/doc_FITMIP.dir/cmake_clean.cmake
.PHONY : fitmip/CMakeFiles/doc_FITMIP.dir/clean

fitmip/CMakeFiles/doc_FITMIP.dir/depend:
	cd /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/fitmip /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/fitmip /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/fitmip/CMakeFiles/doc_FITMIP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : fitmip/CMakeFiles/doc_FITMIP.dir/depend
