cmake_minimum_required(VERSION 3.25)
project(Vaja0801)

set(CMAKE_CXX_STANDARD 14)

add_executable(Vaja0801
        main.cpp Time.cpp)

target_include_directories(
        "${CMAKE_PROJECT_NAME}"
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)