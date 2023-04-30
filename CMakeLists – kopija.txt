cmake_minimum_required(VERSION 3.0)

project(v1.1_V)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}\\headers)

add_executable(obj_vector1 final.v.1.1.vector.cpp)