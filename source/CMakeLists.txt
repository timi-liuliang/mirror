
# Debug message
MESSAGE(STATUS "Add subdirectory [${CMAKE_CURRENT_SOURCE_DIR}]")

# Set this directory as ECHO_GAME_ROOT_PATH
SET(ECHO_GAME_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

# Add game library
ADD_SUBDIRECTORY("${ECHO_GAME_NAME}Lib")

# Add thirdparty libraries
ADD_SUBDIRECTORY("thirdparty/g2o")
ADD_SUBDIRECTORY("thirdparty/DBoW2")
ADD_SUBDIRECTORY("thirdparty/orb-slam3")
ADD_SUBDIRECTORY("thirdparty/mini-slam")
ADD_SUBDIRECTORY("thirdparty/boost_1.83.0")
ADD_SUBDIRECTORY("thirdparty/libtorch")
ADD_SUBDIRECTORY("thirdparty/opencv-4.8")
ADD_SUBDIRECTORY("thirdparty/openssl-1.1.1v")

# Add custom editor


