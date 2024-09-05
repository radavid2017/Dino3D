#!/bin/bash

# Exit script on any error
set -e

# Define variables
PROJECT_NAME="Dino3D"
BUILD_DIR="build"
VSWHERE_PATH="C:/Program Files (x86)/Microsoft Visual Studio/Installer/vswhere.exe"

# Function to print an error message and exit
function handle_error {
    echo "Error on line $1"
    exit 1
}

# Trap any error and call the handle_error function
trap 'handle_error $LINENO' ERR

# Function to find the latest version of Visual Studio installed
function find_latest_vs {
    if [ -f "$VSWHERE_PATH" ]; then
        # Use vswhere to find the installation path
        VS_YEAR=$("$VSWHERE_PATH" -property catalog.productLineVersion)
        
        if [ -z "$VS_YEAR" ]; then
            echo "No Visual Studio installation found."
            exit 1
        fi
        
        echo "Using Visual Studio: $VS_YEAR"
        
        # Determine the appropriate CMake generator based on the version
        if [[ "$VS_YEAR" == "2019" ]]; then
            GENERATOR="Visual Studio 16 2019"
        elif [[ "$VS_YEAR" == "2022" ]]; then
            GENERATOR="Visual Studio 17 2022"
        else
            echo "Unsupported Visual Studio version: $VS_YEAR"
            exit 1
        fi
    else
        echo "vswhere not found at $VSWHERE_PATH. Please check the path or install vswhere."
        exit 1
    fi
}

# Call the function to find the latest VS version
find_latest_vs

# Create build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    mkdir $BUILD_DIR
fi

# Navigate to the build directory
cd $BUILD_DIR

# Run CMake to generate the Visual Studio solution
cmake -G "$GENERATOR" ..

echo "CMake generation complete with generator: $GENERATOR"