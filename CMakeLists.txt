cmake_minimum_required(VERSION 3.12)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(algorithms
        choir.cc
        stringring.cc)
