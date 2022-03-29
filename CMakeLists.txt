cmake_minimum_required(VERSION 3.21)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test 2.2/preface.cpp)

configure_file(2.2/preface.in . COPYONLY)
