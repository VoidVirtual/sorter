cmake_minimum_required(VERSION 3.20)
project("Sorter")

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(sorter main.cpp)

