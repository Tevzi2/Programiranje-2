cmake_minimum_required(VERSION 3.24)
project(naloga0302)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(naloga0302
        naloga0302.cpp
        TextUtility.cpp
        TextUtility.hpp)
