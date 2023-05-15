#pragma once

#include <Exercise.hpp>
#include <Person.hpp>
#include <string>

class CompetativeExercise : public Exercise {
    public:
        CompetativeExercise(Difficulty difficulty, std::string name, Time duration, int32_t calloriesBurned, int32_t avgHeartRate, Date date, Person* competitor, double points);

        void setCompetitor(Person* competitor);

        void setPoints(double points);

        [[nodiscard]] Person* getCompetitor() const;

        [[nodiscard]] double getPoints() const;

        [[nodiscard]] std::string toString() const override;

        void print() const override;

    private:
        Person* competitor;
        double points;
};