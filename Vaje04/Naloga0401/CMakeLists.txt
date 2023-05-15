cmake_minimum_required(VERSION 3.24)
project(Naloga0401)

set(CMAKE_CXX_STANDARD 14)

add_executable(Naloga0401
        naloga0401.cpp Person.hpp Person.cpp Time.hpp Time.cpp Exercise.hpp Exercise.cpp Difficulty.cpp Difficulty.hpp ExerciseTracker.hpp ExerciseTracker.cpp Date.hpp Date.cpp)
