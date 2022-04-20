cmake_minimum_required(VERSION 3.21)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test 4.1/nuggets.cpp)

configure_file(4.1/nuggets.in . COPYONLY)
