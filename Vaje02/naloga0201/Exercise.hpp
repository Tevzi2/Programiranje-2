#pragma once

#include <string>
#include <utility>
#include <iostream>

class Exercise
{
    public:
        Exercise(std::string name, float duration, int32_t calloriesBurned, int32_t avgHeartRate);

        Exercise();

        [[nodiscard]] std::string getName() const;

        [[nodiscard]] float getDuration() const;

        [[nodiscard]] int32_t getCalloriesBurned() const;

        [[nodiscard]] int32_t getAvgHeartRate() const;

        void setDuration(float duration);

        [[nodiscard]] std::string toString() const;

        [[nodiscard]] const Exercise* isMoreIntense(const Exercise* compare) const;

        void print() const;

    private:
        std::string name;
        float duration;
        int32_t calloriesBurned;
        int32_t avgHeartRate;
};