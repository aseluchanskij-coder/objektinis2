cmake_minimum_required(VERSION 3.28)
project(v2.0_all)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

add_executable(v2.0_vector Vector/ivedimas_isvedimas.cpp Vector/pagalbines.cpp Vector/studentas.cpp Vector/testavimas.cpp Vector/vektoriai2.0.cpp)
#target_include_directories(v2.0_vector PRIVATE include)

#target_include_directories(v2.0_list PRIVATE include)

#target_include_directories(v2.0_deque PRIVATE include)
# Sukuriamas atskiras executable failas testams
add_executable(run_tests 
    unit_test.cpp 
    Vector/studentas.cpp 
    Vector/ivedimas_isvedimas.cpp
    Vector/pagalbines.cpp       
  #  Vector/testavimas.cpp      
)
target_include_directories(run_tests PUBLIC Vector)