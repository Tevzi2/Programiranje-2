#pragma once

#include <string>
#include <utility>
#include <iostream>
#include "Time.hpp"
#include "Difficulty.hpp"
#include "Date.hpp"

class Exercise
{
    public:
        Exercise(Difficulty difficulty, std::string name, Time duration, int32_t calloriesBurned, int32_t avgHeartRate, Date date);

        Exercise();

        [[nodiscard]] std::string getName() const;

        [[nodiscard]] Time getDuration() const;

        [[nodiscard]] int32_t getCalloriesBurned() const;

        [[nodiscard]] int32_t getAvgHeartRate() const;

        [[nodiscard]] Difficulty getDifficulty() const;

        [[nodiscard]] Date getDate() const;

        void setDuration(Time duration);

        void setDate(Date date);

        void setDifficulty(Difficulty difficulty);

        [[nodiscard]] std::string toString() const;

        [[nodiscard]] const Exercise* isMoreIntense(const Exercise* compare) const;

        void print() const;

    private:
        Difficulty difficulty;
        Date date;
        std::string name;
        Time duration;
        int32_t calloriesBurned;
        int32_t avgHeartRate;
};