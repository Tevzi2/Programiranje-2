cmake_minimum_required(VERSION 3.25)
project(Vaja0701)

set(CMAKE_CXX_STANDARD 14)

add_executable(Vaja0701
        main.cpp Point.cpp)

target_include_directories(
        "${CMAKE_PROJECT_NAME}"
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)