# CMake Add ExternalProject LibTorch

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
    libtorch-2.0.1-release
    URL https://download.pytorch.org/libtorch/cu118/libtorch-win-shared-with-deps-2.0.1%2Bcu118.zip
    PREFIX ${CMAKE_CURRENT_SOURCE_DIR}
    BUILD_IN_SOURCE true
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

SET_TARGET_PROPERTIES(libtorch-2.0.1-release PROPERTIES FOLDER "game/thirdparty/external/libtorch")

ExternalProject_Add(
    libtorch-2.0.1-debug
    URL https://download.pytorch.org/libtorch/cu118/libtorch-win-shared-with-deps-debug-2.0.1%2Bcu118.zip
    PREFIX ${CMAKE_CURRENT_SOURCE_DIR}
    BUILD_IN_SOURCE true
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

SET_TARGET_PROPERTIES(libtorch-2.0.1-debug PROPERTIES FOLDER "game/thirdparty/external/libtorch")