#=============================================================================
#  C O P Y R I G H T
#-----------------------------------------------------------------------------
#  Copyright (c) 2024 by Hoka David-Stelian. All rights reserved.
#
#  This file is property of Hoka David-Stelian. Any unauthorized copy, use or
#  distribution is an offensive act against international law and may be 
#  prosecuted under federal law. Its content is personal confidential.
#=============================================================================
#  Author(s): Hoka David-Stelian (Maintainer)

cmake_minimum_required(VERSION ${CMAKE_VERSION})

# Project name
project(Main)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

# Setting path to headers
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${APP_DIR}/AppWindow/inc
        ${ENGINE_DIR}/Window/inc
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        AppWindow
)

copy_runtime_dependencies()