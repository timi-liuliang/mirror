# Set Module Name
SET(MODULE_NAME DBoW2)

# message
MESSAGE( STATUS "Configuring module: ${MODULE_NAME} ...")

# Include Directories
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES( ${ECHO_GAME_ROOT_PATH}/thirdparty)
INCLUDE_DIRECTORIES( ${ECHO_GAME_ROOT_PATH}/thirdparty/boost_1.83.0/src/build/include/boost-1_83)
INCLUDE_DIRECTORIES( ${ECHO_GAME_ROOT_PATH}/thirdparty/opencv-4.8/src/opencv-4.8/build/include)

# Link Directories
LINK_DIRECTORIES(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# Recursive get all files
FILE( GLOB_RECURSE ALL_FILES *.h *.inl *.c *.cc *.cpp *.mm)

# Group
GROUP_FILES(ALL_FILES ${CMAKE_CURRENT_SOURCE_DIR})

# Add library
ADD_LIBRARY(${MODULE_NAME} ${ALL_FILES} CMakeLists.txt)

# Set Folder
SET_TARGET_PROPERTIES(${MODULE_NAME} PROPERTIES FOLDER "game/thirdparty/external")

# Message
MESSAGE(STATUS "Configure success!")
