cmake_minimum_required(VERSION 3.24)
project(Naloga0502)

set(CMAKE_CXX_STANDARD 14)

add_executable(Naloga0502
        Naloga0502.cpp Bank.cpp Account.cpp Person.cpp SavingAccount.cpp Date.cpp Transaction.cpp)

include_directories(
        "${CMAKE_PROJECT_NAME}"
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)