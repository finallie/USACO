cmake_minimum_required(VERSION 3.21)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test 1.4/barn1.cpp)

configure_file(1.4/barn1.in . COPYONLY)
