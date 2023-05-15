cmake_minimum_required(VERSION 3.24)
project(Vaja0601)

set(CMAKE_CXX_STANDARD 14)

add_executable(Vaja0601
        vaja0601.cpp PrintUtility.cpp Graph.cpp VerticalPictograph.cpp DotPictograph.cpp HorizontalPictograph.cpp CubePictograph.cpp)

target_include_directories(
        "${CMAKE_PROJECT_NAME}"
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)