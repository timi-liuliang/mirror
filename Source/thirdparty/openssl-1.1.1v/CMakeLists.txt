# CMake Add ExternalProject
SET(MODULE_NAME openssl-1.1.1v)

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
    URL https://download.firedaemon.com/FireDaemon-OpenSSL/openssl-1.1.1v.zip
    PREFIX ${CMAKE_CURRENT_SOURCE_DIR}
    BUILD_IN_SOURCE true
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

SET_TARGET_PROPERTIES(${MODULE_NAME} PROPERTIES FOLDER "game/thirdparty/external")