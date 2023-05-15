#pragma once

#include <string>
#include <Time.hpp>
#include <Difficulty.hpp>
#include <MuscleGroup.hpp>
#include <Exercise.hpp>
#include <Date.hpp>

class StrengthExercise : public Exercise {
    public:
        StrengthExercise(const std::string& name, int32_t avgHeartRate, const Time& duration, Difficulty difficulty, int32_t calloriesBurned, float weight, uint32_t reps, uint32_t sets, MuscleGroup muscleGroup, Date date);

        void setWeight(float weight);

        void setReps(uint32_t reps);

        void setSets(uint32_t sets);

        void setMuscleGroup(MuscleGroup muscleGroup);

        [[nodiscard]] float getWeight() const;

        [[nodiscard]] uint32_t getSets() const;

        [[nodiscard]] uint32_t getReps() const;

        [[nodiscard]] MuscleGroup getMuscleGroup() const;

        [[nodiscard]] std::string toString() const override;

        void print() const override;

    private:
        float weight;
        uint32_t sets;
        uint32_t reps;
        MuscleGroup muscleGroup;
};
