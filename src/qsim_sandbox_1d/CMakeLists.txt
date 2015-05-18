
# Project Name
project(QSimSandbox1D)

# Find SFML
find_package(SFML 2 REQUIRED system window graphics)

# Find SFGUI, without examples
#set(SFGUI_BUILD_EXAMPLES false)
#add_subdirectory(sfgui-0.2.3)

# Includes
include_directories(${SFML_INCLUDE_DIR})
include_directories(${SFGUI_SOURCE_DIR}/include)
include_directories(${QSimSandbox1D_SOURCE_DIR})
include_directories(${QSim_SOURCE_DIR}/include)

# Define the executable
add_executable(QSimSandbox1D main.cpp app.cpp)

# Make links
#target_link_libraries(QSimSandbox1D QSim ${SFML_LIBRARIES} sfgui)
target_link_libraries(QSimSandbox1D QSim ${SFML_LIBRARIES})
