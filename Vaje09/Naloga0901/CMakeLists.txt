cmake_minimum_required(VERSION 3.25)
project(Vaja0901)

set(CMAKE_CXX_STANDARD 14)

add_executable(Vaja0901
        main.cpp Date.cpp)

target_include_directories(
        "${CMAKE_PROJECT_NAME}"
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/
)