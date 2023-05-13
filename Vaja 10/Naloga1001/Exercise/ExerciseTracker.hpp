#pragma once

#include <vector>
#include <Exercise.hpp>
#include <Person.hpp>
#include <PrintIfStrengthExercise.h>

class ExerciseTracker {
    public:
        explicit ExerciseTracker(Person* trainee);

        ~ExerciseTracker();

        void addExercise(const Exercise* exercise);

        [[nodiscard]] std::string toString() const;

        [[nodiscard]] std::vector<Exercise> getExercisesBetweenDurations(Time from, Time to) const;

        void sort(bool (*c)(Exercise*, Exercise*));

        Exercise* find(bool (*c)(Exercise*));

        void printExercises(PrintIfStrengthExercise i);
    private:
        ExerciseTracker();

        std::vector<Exercise*> exercises;
        Person* trainee;
};
