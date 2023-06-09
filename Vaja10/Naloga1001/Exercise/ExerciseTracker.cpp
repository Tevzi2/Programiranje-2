#include <ExerciseTracker.hpp>

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

ExerciseTracker::~ExerciseTracker()
{
    for(const auto& exercise : exercises)
    {
        delete exercise;
    }

    for(const auto& log : weights)
    {
        delete log;
    }
}

void ExerciseTracker::addExercise(const Exercise* exercise)
{
    exercises.push_back((Exercise*)exercise); // fucking kill me omg i was creating a new object here jesus
}

[[nodiscard]] std::string ExerciseTracker::toString() const
{
    std::string out =
    "Exercises for: " +
    trainee->toString() +
    "\n";

    for(const Exercise* exercise: exercises)
    {
        out += exercise->toString() + "\n";
    }

    return out;
}

[[nodiscard]] std::vector<Exercise> ExerciseTracker::getExercisesBetweenDurations(Time from, Time to) const
{
    std::vector<Exercise> foundExercises;

    for(const auto& exercise : exercises)
    {
        if(exercise->getDuration().toSeconds() > from.toSeconds() && exercise->getDuration().toSeconds() < to.toSeconds())
            foundExercises.push_back(*exercise);
    }

    return foundExercises;
}

void ExerciseTracker::sort(bool (*c)(Exercise*, Exercise*))
{
    std::sort(exercises.begin(), exercises.end(), c);
}

Exercise* ExerciseTracker::find(bool (*c)(Exercise*))
{
    auto val = std::find_if(exercises.begin(), exercises.end(), c);

    if(val == exercises.end()) return nullptr;

    return *val;
}

void ExerciseTracker::printExercises(PrintIfStrengthExercise i)
{
    std::for_each(exercises.begin(), exercises.end(), i);
}

void ExerciseTracker::add(Date date, float weight)
{
    weights.push_back(new WeightLog(date, weight));
}

WeightLog* ExerciseTracker::find(bool (*c)(WeightLog*)) const
{
    for(const auto& el : weights)
        if(c(el))
            return el;

    return nullptr;
}