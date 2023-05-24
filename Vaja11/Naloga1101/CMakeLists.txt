cmake_minimum_required(VERSION 3.25)
project(Naloga1101)

set(CMAKE_CXX_STANDARD 23)

add_executable(Naloga1101
        naloga1101.cpp Sensor.cpp PressureSensor.cpp PressureUnit.cpp PressureSensorP12.cpp DuplicateSensorException.cpp SensorHub.cpp InvalidLocationException.cpp)

target_include_directories(
        "${CMAKE_PROJECT_NAME}"
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/
)