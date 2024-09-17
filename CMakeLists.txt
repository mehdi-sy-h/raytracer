# CMake version requirement
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(raytracer LANGUAGES CXX)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the src directory for header file includes
include_directories(${CMAKE_SOURCE_DIR}/src)

# Add the executable target, compiling raytracer.cpp
add_executable(raytracer src/raytracer.cpp)
