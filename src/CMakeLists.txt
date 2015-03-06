# CMake version
cmake_minimum_required (VERSION 3.0.1)

# CMake modules directory
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../cmake/modules/")

# Set up compiler definitions
add_definitions(-std=c++0x
                -pthread
                -Wall
                -Wextra)

# QSim
add_subdirectory(qsim)

# QSim Sandbox 1D
add_subdirectory(qsim_sandbox_1d)

# Test program code
add_subdirectory(qsim_test)
