cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(snake VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Gather all .cpp files in the src directory
file(GLOB SOURCES "src/*.cpp")


# Add the executable
add_executable(snake ${SOURCES})