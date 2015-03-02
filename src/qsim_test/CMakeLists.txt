
# Project name
project(QSimTest)

# GTest
add_subdirectory(gtest-1.7.0)

# Include everything
include_directories(${QSimTest_SOURCE_DIR})
include_directories(${QSim_SOURCE_DIR}/include)
include_directories(${gtest_SOURCE_DIR}/include
                    ${gtest_SOURCE_DIR})

# Define the executable test program
add_executable(QSimTest main.cpp)

# Link everything to the FrameTest executable
target_link_libraries(QSimTest QSim gtest gtest_main)
