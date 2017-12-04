# Install script for directory: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_reco/recoSiPM/src

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/calice_reco/recoSiPM/include/" REGEX "/[^/]*\\~$" EXCLUDE REGEX "/[^/]*CVS[^/]*$" EXCLUDE)
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/librecoSiPM.so.6.8.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/librecoSiPM.so.6"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/librecoSiPM.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHECK
           FILE "${file}"
           RPATH "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/lcio/v02-07/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/lccd/v01-03/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/Marlin/v01-08/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/gear/v01-05/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/CLHEP/2.1.4.1/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/ilcutil/v01-02-01/lib")
    ENDIF()
  ENDFOREACH()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES
    "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_reco/lib/librecoSiPM.so.6.8.1"
    "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_reco/lib/librecoSiPM.so.6"
    "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_reco/lib/librecoSiPM.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/librecoSiPM.so.6.8.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/librecoSiPM.so.6"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/librecoSiPM.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/lcio/v02-07/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/lccd/v01-03/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/Marlin/v01-08/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/gear/v01-05/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/CLHEP/2.1.4.1/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/ilcutil/v01-02-01/lib:/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib:/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_calice_reco/lib:"
           NEW_RPATH "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/lcio/v02-07/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/lccd/v01-03/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/Marlin/v01-08/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/gear/v01-05/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/CLHEP/2.1.4.1/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/ilcutil/v01-02-01/lib")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

