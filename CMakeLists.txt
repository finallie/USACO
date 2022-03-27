cmake_minimum_required(VERSION 3.21)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test 2.1/hamming.cpp)

configure_file(2.1/hamming.in . COPYONLY)
