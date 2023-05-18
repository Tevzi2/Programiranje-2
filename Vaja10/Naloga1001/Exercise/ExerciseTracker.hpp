#pragma once

#include <vector>
#include <Exercise.hpp>
#include <Person.hpp>
#include <PrintIfStrengthExercise.h>
#include <WeightLog.hpp>

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

        void add(Date date, float weight);

        WeightLog* find(bool (*c)(WeightLog*)) const;

    private:
        ExerciseTracker();

        std::vector<Exercise*> exercises;
        std::vector<WeightLog*> weights;
        Person* trainee;
};
