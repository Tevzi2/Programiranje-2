#include "ExerciseTracker.hpp"

int main()
{
    Person person("John", "Doe", 41, 73.5f, 185);

    ExerciseTracker trackerOne(&person);
    ExerciseTracker trackerTwo(&person);

    // ExerciseTracker trackerThree; // <- throws error becouse it has a private default constructor

    trackerOne.addExercise({Difficulty::Easy, "Walking", Time::parse("00:12:13"), 120, 93, {12, 2, 2023}});
    trackerOne.addExercise({Difficulty::Normal, "Running", Time::parse("00:32:14"), 153, 92, {12, 2, 2023}});
    trackerOne.addExercise({Difficulty::Hard, "Gym workoug", Time::parse("01:20:53"), 430, 72, {12, 2, 2023}});
    trackerOne.addExercise({Difficulty::Normal, "Tennis", Time::parse("01:03:49"), 60, 85, {12, 2, 2023}});

    trackerTwo.addExercise({Difficulty::Easy, "Jogging", Time::parse("00:18:35"), 53, 72, {12, 2, 2023}});
    trackerTwo.addExercise({Difficulty::Normal, "Swimming", Time::parse("00:16:03"), 153, 92, {12, 2, 2023}});
    trackerTwo.addExercise({Difficulty::Hard, "Golf", Time::parse("02:20:53"), 12, 65, {12, 2, 2023}});
    trackerTwo.addExercise({Difficulty::Normal, "Running", Time::parse("01:02:21"), 243, 95, {12, 2, 2023}});
    trackerTwo.addExercise({Difficulty::Normal, "Tennis", Time::parse("01:03:49"), 60, 85, {12, 2, 2023}});

    std::cout << "Exercise tracker one exercises: " << std::endl;
    std::cout << trackerOne.toString();

    std::cout << std::endl;

    std::cout << "Exercise tracker two exercises: " << std::endl;
    std::cout << trackerTwo.toString();

    std::vector<Exercise> foundExercises = trackerTwo.getExercisesBetweenDurations(Time::parse("00:30:00"), Time::parse("01:20:00"));

    std::cout << "exercises between 30min and 80min: " << std::endl;
    for(const auto& exercise : foundExercises)
    {
        std::cout << exercise.toString() << std::endl;
    }
}
