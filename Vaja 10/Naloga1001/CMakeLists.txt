cmake_minimum_required(VERSION 3.25)
project(Naloga10_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(Naloga10_1
        Exercise/StrengthExercise.cpp Exercise/Person.cpp Exercise/MuscleGroup.cpp Exercise/ExerciseTracker.cpp Exercise/Exercise.cpp Exercise/Difficulty.cpp Exercise/CompetativeExercise.cpp Time/Date.cpp Time/Time.cpp naloga1001.cpp Exercise/PrintIfStrengthExercise.cpp)

target_include_directories(
        "${CMAKE_PROJECT_NAME}"
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Time
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Exercise
)