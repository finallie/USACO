cmake_minimum_required(VERSION 3.21)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test 4.3/race3.cpp)

configure_file(4.3/race3.in . COPYONLY)
