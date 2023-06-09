#include <iostream>
#include <ExerciseTracker.hpp>
#include <StrengthExercise.hpp>
#include <CompetativeExercise.hpp>
#include <Exercise.hpp>

int main()
{
    Person person("John", "Doe", 41, 73.5f, 185);
    Person competitor("Jane", "Doe", 45, 76.5f, 165);

    ExerciseTracker trackerOne(&person);

    // ExerciseTracker trackerThree; // <- throws error becouse it has a private default constructor
    trackerOne.addExercise(new StrengthExercise("Curls", 120, Time::parse("00:12:13"), Difficulty::Easy, 40, person.getWeight(), 10, 10, MuscleGroup::Arms,Date(10, 7, 2003)));
    trackerOne.addExercise(new Exercise(Difficulty::Easy, "Walking", Time::parse("00:12:13"), 120, 93, {12, 2, 2023}));
    trackerOne.addExercise(new Exercise(Difficulty::Normal, "Running", Time::parse("00:32:14"), 153, 92, {12, 2, 2023}));
    trackerOne.addExercise(new Exercise(Difficulty::Normal, "Running", Time::parse("00:32:14"), 153, 92, {12, 2, 2023}));
    trackerOne.addExercise(new StrengthExercise("Leg press", 140, Time::parse("00:14:15"), Difficulty::Hard, 50,  person.getWeight(), 10, 10, MuscleGroup::Legs, Date(20, 12, 2013)));
    trackerOne.addExercise(new CompetativeExercise(Difficulty::Hard, "Paul waulting", Time::parse("00:14:15"), 160, 92, Date(20, 12, 2013), &competitor, 123.53));

    std::cout << "Exercise tracker one exercises: " << std::endl;
    std::cout << trackerOne.toString();

    std::cout << std::endl;

    std::vector<Exercise> foundExercises = trackerOne.getExercisesBetweenDurations(Time::parse("00:30:00"), Time::parse("01:20:00"));

    std::cout << "exercises between 30min and 80min: " << std::endl;
    for(const auto& exercise : foundExercises)
    {
        std::cout << exercise.toString() << std::endl;
    }
}