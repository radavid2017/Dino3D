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

set(CMAKE_VERSION 3.15)
cmake_minimum_required(VERSION ${CMAKE_VERSION})

project(Dino3D)

# Define source directories
set(APP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/App)
set(ENGINE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine)
set(LIBS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine/libs)

# Collect source files
file(GLOB_RECURSE APP_SOURCES ${APP_DIR}/*.cpp)
file(GLOB_RECURSE ENGINE_SOURCES ${ENGINE_DIR}/*.cpp)

# Use the folder structure in solution view
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Enable exporting all symbols to generate .lib files
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Enable generating XML documentation files
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /doc")

# Optionally enable optimizations and debug info based on the build type
function(apply_compile_options_except excluded_target)
    if (CMAKE_BUILD_TYPE MATCHES Debug)
        message(STATUS "Debug build")
        foreach(target ${ALL_TARGETS})
            if (NOT target STREQUAL ${excluded_target})
                target_compile_options(${target} PUBLIC -g)
            endif()
        endforeach()
    elseif (CMAKE_BUILD_TYPE MATCHES Release)
        message(STATUS "Release build")
        foreach(target ${ALL_TARGETS})
            if (NOT target STREQUAL ${excluded_target})
                target_compile_options(${target} PUBLIC -O3)
            endif()
        endforeach()
    endif()
endfunction()

set(ALL_TARGETS) # Initialize an empty list to collect all targets

# Function to add all subdirectories
function(add_all_subdirectories)
    file(GLOB SUBDIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *)
    foreach(SUBDIR ${SUBDIRS})
        if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR} AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/CMakeLists.txt)
            message(STATUS "Adding subdirectory: ${SUBDIR}")
            add_subdirectory(${SUBDIR})
            # Apply documentation flag to each target created in the subdirectory
            if(MSVC AND TARGET ${SUBDIR})
                target_compile_options(${SUBDIR} PRIVATE "/doc")
            endif()
        endif()
    endforeach()
endfunction()

# Collect all targets
get_property(ALL_TARGETS DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY BUILDSYSTEM_TARGETS)

# Apply compile options to all except Dino3D
apply_compile_options_except("Dino3D")

function(copy_runtime_dependencies)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # Use CMake's command to copy files if they are different
    $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}>         # This expands to the list of runtime DLLs for the target
    $<TARGET_FILE_DIR:${PROJECT_NAME}>             # This expands to the directory of the target executable
    COMMAND_EXPAND_LISTS                           # Ensure that the list of DLLs is properly expanded
)
endfunction()


# Search for new projects in subfolders
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/App")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/GameEngine")
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Main)