# Install script for directory: /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/RootTreeWriter

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./include/RootTreeWriter" TYPE FILE FILES
    "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/RootTreeWriter/include/EngineLoaderProxy.hh"
    "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/RootTreeWriter/include/EngineRegistrar.hh"
    "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/RootTreeWriter/include/EventPropertiesWriteEngine.hh"
    "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/RootTreeWriter/include/RootTreeWriter.hh"
    "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/RootTreeWriter/include/RootWriteEngine.hh"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  EXEC_PROGRAM(/usr/bin/gmake /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_RootTreeWriter ARGS doc)
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc/RootTreeWriter" TYPE DIRECTORY FILES
    "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/RootTreeWriter/doc/html"
    "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/RootTreeWriter/doc/latex"
    REGEX "/[^/]*CVS[^/]*$" EXCLUDE)
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libRootTreeWriter.so.2.5.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libRootTreeWriter.so.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libRootTreeWriter.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHECK
           FILE "${file}"
           RPATH "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/Marlin/v01-08/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/lcio/v02-07/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/gear/v01-05/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/CLHEP/2.1.4.1/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/ilcutil/v01-02-01/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/lccd/v01-03/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/CondDBMySQL/CondDBMySQL_ILC-0-9-6/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/MarlinUtil/v01-11/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/CED/v01-09-02/lib")
    ENDIF()
  ENDFOREACH()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES
    "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_RootTreeWriter/lib/libRootTreeWriter.so.2.5.2"
    "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_RootTreeWriter/lib/libRootTreeWriter.so.2"
    "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_RootTreeWriter/lib/libRootTreeWriter.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libRootTreeWriter.so.2.5.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libRootTreeWriter.so.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libRootTreeWriter.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/Marlin/v01-08/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/lcio/v02-07/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/gear/v01-05/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/CLHEP/2.1.4.1/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/ilcutil/v01-02-01/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/lccd/v01-03/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/CondDBMySQL/CondDBMySQL_ILC-0-9-6/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib:/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/MarlinUtil/v01-11/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/CED/v01-09-02/lib:"
           NEW_RPATH "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/Marlin/v01-08/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/lcio/v02-07/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/gear/v01-05/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/CLHEP/2.1.4.1/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/ilcutil/v01-02-01/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/lccd/v01-03/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/CondDBMySQL/CondDBMySQL_ILC-0-9-6/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/root/5.34.30/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/v01-17-09/MarlinUtil/v01-11/lib:/afs/desy.de/project/ilcsoft/sw/x86_64_gcc44_sl6/CED/v01-09-02/lib")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_RootTreeWriter/RootTreeWriterConfig.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_RootTreeWriter/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/build_RootTreeWriter/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
