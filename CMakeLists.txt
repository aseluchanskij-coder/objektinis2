cmake_minimum_required(VERSION 3.28)
project(v2.0_all)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

add_executable(v2_0_vector 
    Vector/ivedimas_isvedimas.cpp 
    Vector/pagalbines.cpp 
    Vector/studentas.cpp 
    Vector/testavimas.cpp 
    Vector/vektoriai2.0.cpp
)
target_include_directories(v2_0_vector PUBLIC Vector)

add_executable(run_tests 
    unit_test.cpp 
    Vector/studentas.cpp 
    Vector/pagalbines.cpp 
    Vector/ivedimas_isvedimas.cpp
)
target_include_directories(run_tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/Vector)

add_executable(spartos_analize Vector/spartos_analize.cpp)
target_include_directories(spartos_analize PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Vector)