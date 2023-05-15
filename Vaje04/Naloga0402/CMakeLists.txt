cmake_minimum_required(VERSION 3.24)
project(Naloga0402)

set(CMAKE_CXX_STANDARD 14)

add_executable(Naloga0402
        naloga0402.cpp Date/Date.cpp Date/DateTime.cpp Date/Time.cpp Mail/User.cpp Mail/Message.cpp Mail/Mailbox.cpp Mail/Folder.cpp Mail/Priority.cpp)

target_include_directories(
        "${CMAKE_PROJECT_NAME}"
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Date
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Mail
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)