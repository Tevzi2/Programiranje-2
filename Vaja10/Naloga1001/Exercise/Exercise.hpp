#pragma once

#include <string>
#include <utility>
#include <iostream>
#include <Time.hpp>
#include <Difficulty.hpp>
#include <Date.hpp>

class Exercise
{
    public:
        Exercise(Difficulty difficulty, std::string name, Time duration, int32_t calloriesBurned, int32_t avgHeartRate, Date date);

        Exercise();

        virtual ~Exercise() { };

        [[nodiscard]] std::string getName() const;

        [[nodiscard]] Time getDuration() const;

        [[nodiscard]] int32_t getCalloriesBurned() const;

        [[nodiscard]] int32_t getAvgHeartRate() const;

        [[nodiscard]] Difficulty getDifficulty() const;

        [[nodiscard]] Date getDate() const;

        void setDuration(Time duration);

        void setDate(Date date);

        void setDifficulty(Difficulty difficulty);

        [[nodiscard]] virtual std::string toString() const;

        [[nodiscard]] const Exercise* isMoreIntense(const Exercise* compare) const;

        virtual void print() const;

    protected:
        int32_t avgHeartRate;
        std::string name;

    private:
        Difficulty difficulty;
        Date date;
        Time duration;
        int32_t calloriesBurned;
};