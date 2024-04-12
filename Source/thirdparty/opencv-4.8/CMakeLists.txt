# CMake Add ExternalProject
SET(MODULE_NAME opencv-4.8)

# PREFIX
# TMP_DIR       = <prefix>/tmp
# DOWNLOAD_DIR  = <prefix>/src/<name>=stamp
# SOURCE_DIR    = <prefix>/src/<name>
# BINARY_DIR    = <prefix>/src/<name>-build
# INSTALL_DIR   = <prefix>
# LOG_DIR       = <STAMP_DIR>

# LibTorch
INCLUDE(ExternalProject)
ExternalProject_Add(
    ${MODULE_NAME}
    URL https://github.com/opencv/opencv/releases/download/4.8.0/opencv-4.8.0-windows.exe
    PREFIX ${CMAKE_CURRENT_SOURCE_DIR}
    BUILD_IN_SOURCE true
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

SET_TARGET_PROPERTIES(${MODULE_NAME} PROPERTIES FOLDER "game/thirdparty/external")