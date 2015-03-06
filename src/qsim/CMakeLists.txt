project(QSim)

cmake_minimum_required (VERSION 3.0.1)

add_definitions(-std=c++0x
                -pthread
                -Wall
                -Wextra)

find_package(GSL REQUIRED)

include_directories(${GSL_INCLUDE_DIR})
include_directories(${QSim1D_SOURCE_DIR}/include,
                    ${QSim1D_SOURCE_DIR})

add_subdirectory(source)
