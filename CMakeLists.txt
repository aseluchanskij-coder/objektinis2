cmake_minimum_required(VERSION 3.28)
project(v2.0_all)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

add_executable(v2.0_vector Vector/ivedimas_isvedimas.cpp Vector/pagalbines.cpp Vector/studentas.cpp Vector/testavimas.cpp Vector/vektoriai2.0.cpp)
#target_include_directories(v2.0_vector PRIVATE include)

add_executable(v2.0_list List/ivedimas_isvedimas.cpp List/pagalbines.cpp List/studentas.cpp List/testavimas.cpp List/list2.0.cpp)
#target_include_directories(v2.0_list PRIVATE include)

add_executable(v2.0_deque Deque/ivedimas_isvedimas.cpp Deque/pagalbines.cpp Deque/studentas.cpp Deque/testavimas.cpp Deque/deque2.0.cpp)
#target_include_directories(v2.0_deque PRIVATE include)