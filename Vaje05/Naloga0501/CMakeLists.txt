cmake_minimum_required(VERSION 3.24)
project(Naloga0501)

set(CMAKE_CXX_STANDARD 23)

add_executable(Naloga0501
        naloga0501.cpp Time/Date.cpp Time/Time.cpp Exercise/ExerciseTracker.cpp Exercise/Person.cpp Exercise/Exercise.cpp Exercise/Difficulty.cpp Exercise/StrengthExercise.cpp Exercise/MuscleGroup.cpp Exercise/CompetativeExercise.cpp)

target_include_directories(
        "${CMAKE_PROJECT_NAME}"
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Time
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Exercise
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)