include(CPack)
cmake_minimum_required(VERSION 3.0.0)
project(V2.0 VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}\\headers)

add_executable(obj_vector1 final.v2.0.vector.cpp)

#add_executable(obj_tests tests.cpp)