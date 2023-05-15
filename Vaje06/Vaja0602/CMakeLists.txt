cmake_minimum_required(VERSION 3.25)
project(Vaja0602)

set(CMAKE_CXX_STANDARD 14)

add_executable(Vaja0602
        vaja0602.cpp Position.cpp Size.cpp XML/Layout.cpp XML/View.cpp XML/Button.cpp XML/ImageView.cpp XML/EditText.cpp XML/InputType.cpp)

target_include_directories(
        "${CMAKE_PROJECT_NAME}"
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/XML
)