cmake_minimum_required(VERSION 3.21)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test 1.3/dualpal.cpp)

configure_file(1.3/dualpal.in . COPYONLY)
