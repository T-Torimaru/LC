# CALICE_USERLIBConfig.cmake.in
#
# cmake config file for CALICE_USERLIB
#  CALICE_USERLIB_INCLUDE_DIRS  - the CALICE_USERLIB include directory
#  CALICE_USERLIB_LIBRARIES     - The libraries needed to use CALICE_USERLIB
#  CALICE_USERLIB_DEFINITIONS   - the compile time definitions


#fixme: not true if INCLUDE_INSTALL_DIR is absolute path
SET( CALICE_USERLIB_INCLUDE_DIRS "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/include" )
SET( CALICE_USERLIB_INCLUDE_DIRS "${CALICE_USERLIB_INCLUDE_DIRS}"
                                  "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/include/Mapping"
                                  "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/include/CellDescription" 
                                  "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/include/Neighbours")

SET( CALICE_USERLIB_LIBRARIES "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib/libuserlib.so" )

SET( CALICE_USERLIB_DEFINITIONS -DTRIGGER_HANDLER_IS_SINGLETON )

SET( CALICE_USERLIB_ROOT_DIR "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall" )

SET( CALICE_USERLIB_MAJOR_VERSION "6" )
SET( CALICE_USERLIB_MINOR_VERSION "6" )
SET( CALICE_USERLIB_PATH_LEVEL    "1"    )


SET( CALICE_USERLIB_FOUND TRUE )

