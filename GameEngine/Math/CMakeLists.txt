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

set(GEN_DEBUG "-DEBUG")
if(MSVC)
    set(GEN_DEBUG "/DEBUG")
endif()

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)

set(PARENT_PROJECT_NAME "${PROJECT_NAME}")
project(Math)

set(SOLUTION_DIR "${PARENT_PROJECT_NAME}/${PROJECT_NAME}")

set(BUILD_WITH_STATIC_CRT ON)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(VOLT_IMPORT_TARGETS_POSTFIX_EXPLICIT "windows-amd64-msvc-1900-mt-x64")
endif()

add_all_subdirectories()