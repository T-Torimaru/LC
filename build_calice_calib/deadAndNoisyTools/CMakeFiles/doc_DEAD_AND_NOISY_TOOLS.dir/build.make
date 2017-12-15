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

# Utility rule file for doc_DEAD_AND_NOISY_TOOLS.

# Include the progress variables for this target.
include deadAndNoisyTools/CMakeFiles/doc_DEAD_AND_NOISY_TOOLS.dir/progress.make

deadAndNoisyTools/CMakeFiles/doc_DEAD_AND_NOISY_TOOLS: doc/DEAD_AND_NOISY_TOOLS/html/index.html

doc/DEAD_AND_NOISY_TOOLS/html/index.html: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/deadAndNoisyTools/doc/Doxyfile.in
doc/DEAD_AND_NOISY_TOOLS/html/index.html: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/deadAndNoisyTools/include/ChannelExpertQuality.h
doc/DEAD_AND_NOISY_TOOLS/html/index.html: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/deadAndNoisyTools/include/LinkDef.h
doc/DEAD_AND_NOISY_TOOLS/html/index.html: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/deadAndNoisyTools/include/ModuleType.h
doc/DEAD_AND_NOISY_TOOLS/html/index.html: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/deadAndNoisyTools/include/RunComparator.h
doc/DEAD_AND_NOISY_TOOLS/html/index.html: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/deadAndNoisyTools/include/SimpleMapper.h
doc/DEAD_AND_NOISY_TOOLS/html/index.html: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/deadAndNoisyTools/include/SpectrumPropertiesRunInfo.h
doc/DEAD_AND_NOISY_TOOLS/html/index.html: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/deadAndNoisyTools/include/TChannelSpectrumProperties.h
doc/DEAD_AND_NOISY_TOOLS/html/index.html: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/deadAndNoisyTools/macros/plotLEDResponse.C
	$(CMAKE_COMMAND) -E cmake_progress_report /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Building API Documentation for DEAD_AND_NOISY_TOOLS..."
	cd /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/doc/DEAD_AND_NOISY_TOOLS && /usr/bin/doxygen

doc_DEAD_AND_NOISY_TOOLS: deadAndNoisyTools/CMakeFiles/doc_DEAD_AND_NOISY_TOOLS
doc_DEAD_AND_NOISY_TOOLS: doc/DEAD_AND_NOISY_TOOLS/html/index.html
doc_DEAD_AND_NOISY_TOOLS: deadAndNoisyTools/CMakeFiles/doc_DEAD_AND_NOISY_TOOLS.dir/build.make
.PHONY : doc_DEAD_AND_NOISY_TOOLS

# Rule to build all files generated by this target.
deadAndNoisyTools/CMakeFiles/doc_DEAD_AND_NOISY_TOOLS.dir/build: doc_DEAD_AND_NOISY_TOOLS
.PHONY : deadAndNoisyTools/CMakeFiles/doc_DEAD_AND_NOISY_TOOLS.dir/build

deadAndNoisyTools/CMakeFiles/doc_DEAD_AND_NOISY_TOOLS.dir/clean:
	cd /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/deadAndNoisyTools && $(CMAKE_COMMAND) -P CMakeFiles/doc_DEAD_AND_NOISY_TOOLS.dir/cmake_clean.cmake
.PHONY : deadAndNoisyTools/CMakeFiles/doc_DEAD_AND_NOISY_TOOLS.dir/clean

deadAndNoisyTools/CMakeFiles/doc_DEAD_AND_NOISY_TOOLS.dir/depend:
	cd /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/deadAndNoisyTools /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/deadAndNoisyTools /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/deadAndNoisyTools/CMakeFiles/doc_DEAD_AND_NOISY_TOOLS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : deadAndNoisyTools/CMakeFiles/doc_DEAD_AND_NOISY_TOOLS.dir/depend
