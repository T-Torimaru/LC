# Install script for directory: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_calib/deadAndNoisyTools/src

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "0")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libDeadAndNoisyTools.so.1.1.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libDeadAndNoisyTools.so.1.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libDeadAndNoisyTools.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHECK
           FILE "${file}"
           RPATH "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib")
    ENDIF()
  ENDFOREACH()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES
    "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/lib/libDeadAndNoisyTools.so.1.1.0"
    "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/lib/libDeadAndNoisyTools.so.1.1"
    "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/lib/libDeadAndNoisyTools.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libDeadAndNoisyTools.so.1.1.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libDeadAndNoisyTools.so.1.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libDeadAndNoisyTools.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
           NEW_RPATH "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/createBadChannelsList" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/createBadChannelsList")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/createBadChannelsList"
         RPATH "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib")
  ENDIF()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/bin/createBadChannelsList")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/createBadChannelsList" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/createBadChannelsList")
    FILE(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/createBadChannelsList"
         OLD_RPATH "/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib:/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/lib:"
         NEW_RPATH "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/createBadChannelsList")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/createSpriTree" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/createSpriTree")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/createSpriTree"
         RPATH "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib")
  ENDIF()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/bin/createSpriTree")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/createSpriTree" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/createSpriTree")
    FILE(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/createSpriTree"
         OLD_RPATH "/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib:/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/lib:"
         NEW_RPATH "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/createSpriTree")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/testRunComparator" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/testRunComparator")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/testRunComparator"
         RPATH "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib")
  ENDIF()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/bin/testRunComparator")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/testRunComparator" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/testRunComparator")
    FILE(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/testRunComparator"
         OLD_RPATH "/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib:/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/lib:"
         NEW_RPATH "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/testRunComparator")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/testSimpleMapper" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/testSimpleMapper")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/testSimpleMapper"
         RPATH "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib")
  ENDIF()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/bin/testSimpleMapper")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/testSimpleMapper" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/testSimpleMapper")
    FILE(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/testSimpleMapper"
         OLD_RPATH "/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib:/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_calib/lib:"
         NEW_RPATH "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/testSimpleMapper")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

