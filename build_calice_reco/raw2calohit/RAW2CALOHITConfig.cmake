# RAW2CALOHITConfig.cmake.in
#
# cmake config file for RAW2CALOHIT
#  RAW2CALOHIT_INCLUDE_DIRS  - the RAW2CALOHIT include directory
#  RAW2CALOHIT_LIBRARIES     - The libraries needed to use RAW2CALOHIT
#  RAW2CALOHIT_DEFINITIONS   - the compile time definitions

SET( RAW2CALOHIT_INCLUDE_DIRS "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/include" )
SET( RAW2CALOHIT_INCLUDE_DIRS "${RAW2CALOHIT_INCLUDE_DIRS}" "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/include/TBTrack" )
SET( RAW2CALOHIT_INCLUDE_DIRS "${RAW2CALOHIT_INCLUDE_DIRS}" "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/include/TBTrackUtil" )
SET( RAW2CALOHIT_INCLUDE_DIRS "${RAW2CALOHIT_INCLUDE_DIRS}" "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/include/gui" )
SET( RAW2CALOHIT_INCLUDE_DIRS "${RAW2CALOHIT_INCLUDE_DIRS}" "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/include/histmgr" )
SET( RAW2CALOHIT_INCLUDE_DIRS "${RAW2CALOHIT_INCLUDE_DIRS}" "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/include/utilities" )

SET( RAW2CALOHIT_LIBRARIES    "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib/libraw2calohit.so" )

SET( RAW2CALOHIT_DEFINITIONS  )

SET( RAW2CALOHIT_ROOT_DIR "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall" )

SET( RAW2CALOHIT_MAJOR_VERSION "6" )
SET( RAW2CALOHIT_MINOR_VERSION "8" )
SET( RAW2CALOHIT_PATH_LEVEL    "1"    )


SET( RAW2CALOHIT_FOUND TRUE )

