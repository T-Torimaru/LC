# LABVIEW2LCIOConfig.cmake.in
#
# cmake config file for LABVIEW2LCIO
#  LABVIEW2LCIO_INCLUDE_DIRS  - the LABVIEW2LCIO include directory
#  LABVIEW2LCIO_LIBRARIES     - The libraries needed to use LABVIEW2LCIO
#  LABVIEW2LCIO_DEFINITIONS   - the compile time definitions


#fixme: not true if INCLUDE_INSTALL_DIR is absolute path
SET( LABVIEW2LCIO_INCLUDE_DIRS "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/include" )

SET( LABVIEW2LCIO_LIBRARIES "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib/liblabview2lcio.so" )

SET( LABVIEW2LCIO_DEFINITIONS  )

SET( LABVIEW2LCIO_ROOT_DIR "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall" )

SET( LABVIEW2LCIO_MAJOR_VERSION "1" )
SET( LABVIEW2LCIO_MINOR_VERSION "0" )
SET( LABVIEW2LCIO_PATH_LEVEL    "0"    )


SET( LABVIEW2LCIO_FOUND TRUE )

