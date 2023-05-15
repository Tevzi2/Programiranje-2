cmake_minimum_required(VERSION 3.25)
project(Vaja0702)

set(CMAKE_CXX_STANDARD 23)

add_executable(Vaja0702
        main.cpp
        Point.cpp Time/Date.cpp Time/Time.cpp Exercise/CompetativeExercise.cpp Exercise/Difficulty.cpp Exercise/Exercise.cpp Exercise/ExerciseTracker.cpp Exercise/MuscleGroup.cpp Exercise/Person.cpp Exercise/StrengthExercise.cpp)

target_include_directories(
        "${CMAKE_PROJECT_NAME}"
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Exercise
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Time
)