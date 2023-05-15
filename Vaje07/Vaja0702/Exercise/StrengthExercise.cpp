#include <StrengthExercise.hpp>

StrengthExercise::StrengthExercise(const std::string& name, int32_t avgHeartRate, const Time& duration, Difficulty difficulty, int32_t calloriesBurned, float weight, uint32_t reps, uint32_t sets, MuscleGroup muscleGroup, Date date)
    :Exercise(difficulty, name, duration, calloriesBurned, avgHeartRate, date), weight(weight), reps(reps), sets(sets), muscleGroup(muscleGroup)
{
    ;
}

void StrengthExercise::setWeight(float weight)
{
    this->weight = weight;
}

void StrengthExercise::setReps(uint32_t reps)
{
    this->reps = reps;
}

void StrengthExercise::setSets(uint32_t sets)
{
    this->sets = sets;
}

void StrengthExercise::setMuscleGroup(MuscleGroup muscleGroup)
{
    this->muscleGroup = muscleGroup;
}

[[nodiscard]] float StrengthExercise::getWeight() const
{
    return weight;
}

[[nodiscard]] uint32_t StrengthExercise::getSets() const
{
    return sets;
}

[[nodiscard]] uint32_t StrengthExercise::getReps() const
{
    return reps;
}

[[nodiscard]] MuscleGroup StrengthExercise::getMuscleGroup() const
{
    return muscleGroup;
}

[[nodiscard]] std::string StrengthExercise::toString() const
{
    std::cout << "Derived";
    std::string out =
        Exercise::toString() +
        " | Weight: " +
        std::to_string(weight) +
        " | Sets: " +
        std::to_string(sets) +
        " | Reps: " +
        std::to_string(reps) +
        " | Muscle group: " +
        muscleGroupToString(muscleGroup);

    return out;
}

void StrengthExercise::print() const
{
    std::cout << toString() << std::endl;
}