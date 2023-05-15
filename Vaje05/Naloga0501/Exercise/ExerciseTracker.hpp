#pragma once

#include <vector>
#include <Exercise.hpp>
#include <Person.hpp>

class ExerciseTracker {
    public:
        explicit ExerciseTracker(Person* trainee);

        ~ExerciseTracker();

        void addExercise(const Exercise* exercise);

        [[nodiscard]] std::string toString() const;

        [[nodiscard]] std::vector<Exercise> getExercisesBetweenDurations(Time from, Time to) const;

    private:
        ExerciseTracker();

        std::vector<Exercise*> exercises;
        Person* trainee;
};
