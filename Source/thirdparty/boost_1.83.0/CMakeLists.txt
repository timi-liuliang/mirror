# CMake Add ExternalProject Boost
SET(MODULE_NAME boost-1.83.0)

# PREFIX
# TMP_DIR       = <prefix>/tmp
# DOWNLOAD_DIR  = <prefix>/src/<name>=stamp
# SOURCE_DIR    = <prefix>/src/<name>
# BINARY_DIR    = <prefix>/src/<name>-build
# INSTALL_DIR   = <prefix>
# LOG_DIR       = <STAMP_DIR>

# Configure
SET(BOOST_CONFIGURE <SOURCE_DIR>/bootstrap.bat --prefix=<SOURCE_DIR>)
SET(BOOST_INSTALL   <SOURCE_DIR>/b2.exe install --prefix=<BINARY_DIR>/../build)

# Boost
INCLUDE(ExternalProject)
ExternalProject_Add(
    ${MODULE_NAME}
    URL https://boostorg.jfrog.io/artifactory/main/release/1.83.0/source/boost_1_83_0.zip
    PREFIX ${CMAKE_CURRENT_SOURCE_DIR}
    BUILD_IN_SOURCE true
    CONFIGURE_COMMAND ${BOOST_CONFIGURE}
    BUILD_COMMAND ""
    INSTALL_COMMAND ${BOOST_INSTALL}
)

SET_TARGET_PROPERTIES(${MODULE_NAME} PROPERTIES FOLDER "game/thirdparty/external")