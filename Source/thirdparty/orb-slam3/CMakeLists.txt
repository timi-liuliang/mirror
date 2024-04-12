# Set Module Name
SET(MODULE_NAME orb-slam3)

# message
MESSAGE( STATUS "Configuring module: ${MODULE_NAME} ...")

# Disable warnings
IF(${ECHO_PLATFORM_WINDOWS})
	ADD_COMPILE_OPTIONS(/wd4819)
ENDIF()

# Include Directories
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES( ${ECHO_ROOT_PATH}/thirdparty/eigen-3.3.3)
INCLUDE_DIRECTORIES( ${ECHO_GAME_ROOT_PATH})
INCLUDE_DIRECTORIES( ${ECHO_GAME_ROOT_PATH}/thirdparty/)
INCLUDE_DIRECTORIES( ${ECHO_GAME_ROOT_PATH}/thirdparty/boost_1.83.0/src/build/include/boost-1_83)
INCLUDE_DIRECTORIES( ${ECHO_GAME_ROOT_PATH}/thirdparty/opencv-4.8/src/opencv-4.8/build/include)
INCLUDE_DIRECTORIES( ${ECHO_GAME_ROOT_PATH}/thirdparty/openssl-1.1.1v/src/openssl-1.1.1v/x64/include)
INCLUDE_DIRECTORIES( ${ECHO_GAME_ROOT_PATH}/thirdparty/Sophus)

IF(${ECHO_PLATFORM_WINDOWS})
	INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include/windows)
ENDIF()

# G2oTypes.cc compile failed
if (MSVC)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
endif(MSVC)

# Link Directories
LINK_DIRECTORIES(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# Recursive get all files
FILE( GLOB_RECURSE ALL_FILES *.h *.inl *.c *.cc *.cpp *.mm)

# Group
GROUP_FILES(ALL_FILES ${CMAKE_CURRENT_SOURCE_DIR})

# Add library
ADD_LIBRARY(${MODULE_NAME} ${ALL_FILES} CMakeLists.txt)

# Set Folder
SET_TARGET_PROPERTIES(${MODULE_NAME} PROPERTIES FOLDER "game/thirdparty/slam")

# Message
MESSAGE(STATUS "Configure success!")
