#=============================================================================
#  C O P Y R I G H T
#-----------------------------------------------------------------------------
#  Copyright (c) 2025 by Hoka David-Stelian. All rights reserved.
#
#  This file is property of Hoka David-Stelian. Any unauthorized copy, use or
#  distribution is an offensive act against international law and may be 
#  prosecuted under federal law. Its content is personal confidential.
#=============================================================================
#  Author(s): Hoka David-Stelian (Maintainer)

cmake_minimum_required(VERSION ${CMAKE_VERSION})

# Project name
project(PixelShader)

# Output of the project will be a SHARED library (dll)
add_library(${PROJECT_NAME} SHARED
    "inc/PixelShader.hpp"
    "src/PixelShader.cpp"
)

# Setting path to headers
target_include_directories(${PROJECT_NAME}
    PUBLIC
        inc
        ../inc
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        d3d11.lib
)

# Set the runtime to /MT or /Mtd in order to build properly
set_property(TARGET ${PROJECT_NAME} PROPERTY
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
)

# Set the solution folder
set_target_properties(${PROJECT_NAME} PROPERTIES
    FOLDER ${SOLUTION_DIR}
    LINK_FLAGS_DEBUG ${GEN_DEBUG}
)