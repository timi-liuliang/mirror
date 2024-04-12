# Set Module Name
SET(MODULE_NAME g2o)

# message
MESSAGE( STATUS "Configuring module: ${MODULE_NAME} ...")

# g2o
SET(g2o_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
CONFIGURE_FILE(config.h.in ${g2o_SOURCE_DIR}/config.h)

# Include Directories
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES( ${ECHO_ROOT_PATH}/thirdparty/eigen-3.3.3)
INCLUDE_DIRECTORIES( ${ECHO_GAME_ROOT_PATH}/thirdparty/)

# Link Directories
LINK_DIRECTORIES(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# Recursive get all files
FILE( GLOB_RECURSE ALL_FILES *.h *.hpp *.inl *.c *.cc *.cpp *.mm)

# Group
GROUP_FILES(ALL_FILES ${CMAKE_CURRENT_SOURCE_DIR})

IF(ECHO_PLATFORM_WINDOWS)
	ADD_DEFINITIONS(-D_WINDOWS)
ENDIF()

# Add library
ADD_LIBRARY(${MODULE_NAME} ${ALL_FILES} CMakeLists.txt)

# Set Folder
SET_TARGET_PROPERTIES(${MODULE_NAME} PROPERTIES FOLDER "game/thirdparty/external")

# Message
MESSAGE(STATUS "Configure success!")
