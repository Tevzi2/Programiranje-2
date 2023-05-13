cmake_minimum_required(VERSION 3.25)
project(Naloga1002)

set(CMAKE_CXX_STANDARD 23)

add_executable(Naloga1002
        naloga1002.cpp Printer.cpp)

target_include_directories(
        "${CMAKE_PROJECT_NAME}"
        PUBLIC ${CMAKE_SOURCE_DIR}/
)