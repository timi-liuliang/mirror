# CMake Add ExternalProject
SET(MODULE_NAME opencv-4.9)

# LibTorch
INCLUDE(ExternalProject)
ExternalProject_Add(
    ${MODULE_NAME}
    URL https://github.com/opencv/opencv/releases/download/4.9.0/opencv-4.9.0-windows.exe
    PREFIX ${CMAKE_CURRENT_SOURCE_DIR}
    BUILD_IN_SOURCE true
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

SET_TARGET_PROPERTIES(${MODULE_NAME} PROPERTIES FOLDER "/library/thirdparty")