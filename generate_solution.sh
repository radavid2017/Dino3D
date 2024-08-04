#!/bin/bash

# Exit script on any error
set -e

# Define variables
PROJECT_NAME="Dino3D"
BUILD_DIR="build"
GENERATOR="Visual Studio 16 2019"

# Function to print an error message and exit
function handle_error {
    echo "Error on line $1"
    exit 1
}

# Trap any error and call the handle_error function
trap 'handle_error $LINENO' ERR

# Create build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    mkdir $BUILD_DIR
fi

# Navigate to the build directory
cd $BUILD_DIR

# Run CMake to generate the Visual Studio solution
cmake -G "$GENERATOR" ..