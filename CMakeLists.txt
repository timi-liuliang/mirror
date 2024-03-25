# CMake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.28)

# Project name
PROJECT(gs-slam)

# Set c++ standard
SET(CMAKE_CXX_STANDARD 17)

# Set output directory
IF(WIN32)
	SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/windows)
	SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib/windows)
ELSEIF(APPLE)
	SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/mac)
	SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib/mac)
ELSE()
	SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/linux)
	SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib/linux)
ENDIF()

# Tutorial - CMake Functions and Macros
# https://asitdhal.medium.com/cmake-functions-and-macros-22293041519f
# Macrod Define for GROUP_FILES
MACRO(GROUP_FILES src_files root_path)
        SET(cur_dir ${root_path})
        FOREACH(group_files ${${src_files}})
            STRING(REGEX REPLACE ${cur_dir}/\(.*\) \\1 sgbd_fpath ${group_files})
            STRING(REGEX REPLACE "\(.*\)/.*" \\1 sgbd_group_name ${sgbd_fpath})
            STRING(COMPARE EQUAL ${sgbd_fpath} ${sgbd_group_name} sgbd_nogroup)
            STRING(REPLACE "/" "\\" sgbd_group_name ${sgbd_group_name})
            IF(sgbd_nogroup)
				SOURCE_GROUP("" FILES ${group_files})
			ELSE()
				SOURCE_GROUP(${sgbd_group_name} FILES ${group_files})
            ENDIF(sgbd_nogroup)
        ENDFOREACH(group_files)
ENDMACRO(GROUP_FILES)

MACRO(EXCLUDE_FILES src_files rescure exclude_dir)
	FILE(${rescure} excludefiles  ${exclude_dir})
	FOREACH(excludefile ${excludefiles})
		LIST(REMOVE_ITEM ${src_files} ${excludefile})
	ENDFOREACH(excludefile)
ENDMACRO(EXCLUDE_FILES)

MACRO(APPEND_FILES src_files rescure append_dir)
	FILE(${rescure} excludefiles  ${append_dir})

	MESSAGE(STATUS ${append_dir})
	MESSAGE(STATUS ${excludefiles})

	SET(${${src_files}} ${${src_files}} ${excludefiles})
	MESSAGE(STATUS ${${src_files}})
ENDMACRO(APPEND_FILES)

# Add sub directories
ADD_SUBDIRECTORY(source)
ADD_SUBDIRECTORY(thirdparty)