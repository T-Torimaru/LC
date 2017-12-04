###############################################
# cmake configuration file for RootTreeWriter
# @author Jan Engels, DESY
###############################################


# do not store find results in cache
SET( RootTreeWriter_INCLUDE_DIRS RootTreeWriter_INCLUDE_DIRS-NOTFOUND )

FIND_PATH( RootTreeWriter_INCLUDE_DIRS
	NAMES RootTreeWriter.hh
	PATHS /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall
	PATH_SUFFIXES include/RootTreeWriter
	NO_DEFAULT_PATH
)
IF( NOT RootTreeWriter_INCLUDE_DIRS )
    MESSAGE( STATUS "Check for RootTreeWriter: ${RootTreeWriter_HOME}"
					" -- failed to find RootTreeWriter include directory!!" )
ELSE( NOT RootTreeWriter_INCLUDE_DIRS )
    MARK_AS_ADVANCED( RootTreeWriter_INCLUDE_DIRS )
ENDIF( NOT RootTreeWriter_INCLUDE_DIRS )


# do not store find results in cache
SET( RootTreeWriter_LIB RootTreeWriter_LIB-NOTFOUND )

FIND_LIBRARY( RootTreeWriter_LIB
	NAMES RootTreeWriter
	PATHS /afs/desy.de/user/t/torimart/work/CosmiTestLCIO/myInstall
	PATH_SUFFIXES lib
	NO_DEFAULT_PATH
)
IF( NOT RootTreeWriter_LIB )
    MESSAGE( STATUS "Check for RootTreeWriter: ${RootTreeWriter_HOME}"
					" -- failed to find RootTreeWriter library!!" )
ELSE( NOT RootTreeWriter_LIB )
    MARK_AS_ADVANCED( RootTreeWriter_LIB )
ENDIF( NOT RootTreeWriter_LIB )


# set variables and display results
IF( RootTreeWriter_INCLUDE_DIRS AND RootTreeWriter_LIB )
	SET( RootTreeWriter_LIBRARIES ${RootTreeWriter_LIB} )
	MARK_AS_ADVANCED( RootTreeWriter_LIBRARIES )
	MESSAGE( STATUS "Check for RootTreeWriter: ${RootTreeWriter_HOME} -- works" )
ELSE( RootTreeWriter_INCLUDE_DIRS AND RootTreeWriter_LIB )
	IF( RootTreeWriter_FIND_REQUIRED )
		MESSAGE( FATAL_ERROR "Check for RootTreeWriter: ${RootTreeWriter_HOME} -- failed!!" )
    ELSE( RootTreeWriter_FIND_REQUIRED )
        MESSAGE( STATUS "Check for RootTreeWriter: ${RootTreeWriter_HOME}"
						" -- failed!! will skip this package..." )
    ENDIF( RootTreeWriter_FIND_REQUIRED )
ENDIF( RootTreeWriter_INCLUDE_DIRS AND RootTreeWriter_LIB )
