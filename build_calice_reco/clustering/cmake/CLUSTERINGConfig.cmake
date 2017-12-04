# CLUSTERINGConfig.cmake.in
#
# cmake config file for CLUSTERING
#  CLUSTERING_INCLUDE_DIRS  - the CLUSTERING include directory
#  CLUSTERING_LIBRARIES     - The libraries needed to use CLUSTERING
#  CLUSTERING_DEFINITIONS   - the compile time definitions


#fixme: not true if INCLUDE_INSTALL_DIR is absolute path
SET( CLUSTERING_INCLUDE_DIRS "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/include" )
SET( CLUSTERING_LIBRARIES    "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib/libclustering.so" )

SET( CLUSTERING_DEFINITIONS  )

SET( CLUSTERING_ROOT_DIR "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall" )

SET( CLUSTERING_MAJOR_VERSION "1" )
SET( CLUSTERING_MINOR_VERSION "0" )
SET( CLUSTERING_PATH_LEVEL    "3"    )


SET( CLUSTERING_FOUND TRUE )

