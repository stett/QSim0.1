project(QSim)

cmake_minimum_required (VERSION 3.0.1)

add_definitions(-std=c++0x
                -pthread
                -Wall
                -Wextra)


include_directories(${QSim1D_SOURCE_DIR}/include,
                    ${QSim1D_SOURCE_DIR})

add_subdirectory(source)
