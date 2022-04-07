cmake_minimum_required(VERSION 3.21)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test 3.2/butter.cpp)

configure_file(3.2/butter.in . COPYONLY)
