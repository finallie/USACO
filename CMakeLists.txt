cmake_minimum_required(VERSION 3.21)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test 4.4/frameup.cpp)

configure_file(4.4/frameup.in . COPYONLY)
