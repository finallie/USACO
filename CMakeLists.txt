cmake_minimum_required(VERSION 3.21)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test 2.3/prefix.cpp)

configure_file(2.3/prefix.in . COPYONLY)
