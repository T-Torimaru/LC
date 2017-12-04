# RECOSIPMConfig.cmake.in
#
# cmake config file for RECOSIPM
#  RECOSIPM_INCLUDE_DIRS  - the RECOSIPM include directory
#  RECOSIPM_LIBRARIES     - The libraries needed to use RECOSIPM
#  RECOSIPM_DEFINITIONS   - the compile time definitions


#fixme: not true if INCLUDE_INSTALL_DIR is absolute path
SET( RECOSIPM_INCLUDE_DIRS "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/include" )
SET( RECOSIPM_LIBRARIES    "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall/lib/librecoSiPM.so" )

SET( RECOSIPM_DEFINITIONS  )

SET( RECOSIPM_ROOT_DIR "/afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall" )

SET( RECOSIPM_MAJOR_VERSION "6" )
SET( RECOSIPM_MINOR_VERSION "8" )
SET( RECOSIPM_PATH_LEVEL    "1"    )


SET( RECOSIPM_FOUND TRUE )

