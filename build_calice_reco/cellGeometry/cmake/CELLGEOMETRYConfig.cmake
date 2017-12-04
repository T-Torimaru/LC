# CELLGEOMETRYConfig.cmake.in
#
# cmake config file for CELLGEOMETRY
#  CELLGEOMETRY_INCLUDE_DIRS  - the CELLGEOMETRY include directory
#  CELLGEOMETRY_LIBRARIES     - The libraries needed to use CELLGEOMETRY
#  CELLGEOMETRY_DEFINITIONS   - the compile time definitions


#fixme: not true if INCLUDE_INSTALL_DIR is absolute path
SET( CELLGEOMETRY_INCLUDE_DIRS "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/include" )
SET( CELLGEOMETRY_LIBRARIES    "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib/libcellGeometry.so" )

SET( CELLGEOMETRY_DEFINITIONS  )

SET( CELLGEOMETRY_ROOT_DIR "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall" )

SET( CELLGEOMETRY_MAJOR_VERSION "2" )
SET( CELLGEOMETRY_MINOR_VERSION "4" )
SET( CELLGEOMETRY_PATH_LEVEL    "1"    )


SET( CELLGEOMETRY_FOUND TRUE )

