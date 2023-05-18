cmake_minimum_required(VERSION 3.25)
project(Naloga1102)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(Naloga1102
        DuplicateSensorException.cpp
        naloga1102.cpp
        PressureSensor.cpp
        PressureSensorP12.cpp
        PressureUnit.cpp
        Sensor.cpp
        SensorHub.cpp Log.cpp LogType.cpp)

target_include_directories(
        "${CMAKE_PROJECT_NAME}"
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/
)
