cmake_minimum_required(VERSION 3.21)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test 1.5/milk3.cpp)

configure_file(1.5/milk3.in . COPYONLY)
