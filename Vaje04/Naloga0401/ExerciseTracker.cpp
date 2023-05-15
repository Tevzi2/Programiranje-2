#include "ExerciseTracker.hpp"

ExerciseTracker::ExerciseTracker()
    :trainee(nullptr)
{
    ;
}

ExerciseTracker::ExerciseTracker(Person* trainee)
    :trainee(trainee)
{
    ;
}

void ExerciseTracker::addExercise(const Exercise& exercise)
{
    exercises.push_back(exercise);
}

[[nodiscard]] std::string ExerciseTracker::toString() const
{
    std::string out =
    "Exercises for: " +
    trainee->toString() +
    "\n";

    for(const auto& exercise: exercises)
    {
        out += exercise.toString() + "\n";
    }

    return out;
}

[[nodiscard]] std::vector<Exercise> ExerciseTracker::getExercisesBetweenDurations(Time from, Time to) const
{
    std::vector<Exercise> foundExercises;

    for(const auto& exercise : exercises)
    {
        if(exercise.getDuration().toSeconds() > from.toSeconds() && exercise.getDuration().toSeconds() < to.toSeconds())
            foundExercises.push_back(exercise);

    }

    return foundExercises;
}