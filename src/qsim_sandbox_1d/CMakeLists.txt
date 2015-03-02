
# Project Name
project(QSimSandbox1D)

# Find packaes
find_package(SFML 2 REQUIRED system window graphics)

# Includes
include_directories(${SFML_INCLUDE_DIR})
include_directories(${QSimSandbox1D_SOURCE_DIR})
include_directories(${QSim_SOURCE_DIR}/include)

# Define the executable
add_executable(QSimSandbox1D main.cpp)

# Make links
target_link_libraries(QSimSandbox1D QSim ${SFML_LIBRARIES})

#message("$<TARGET_FILE_DIR:QSimSandbox1D>")

#add_custom_command(
#    TARGET QSim
#    PRE_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy_directory
#    "${CMAKE_CURRENT_SOURCE_DIR}/resources/textures"
#    $<TARGET_FILE_DIR:QSimSandbox1D>)
