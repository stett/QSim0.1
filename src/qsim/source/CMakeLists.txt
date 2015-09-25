include_directories(${QSim_SOURCE_DIR}/include
                    ${QSim_SOURCE_DIR})

add_library(QSim SHARED qsim1d.cpp distributions.cpp)

target_link_libraries(QSim ${GSL_LIBRARIES})
