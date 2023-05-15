#include <VectorUtil.hpp>
#include <Exercise.hpp>
#include <StrengthExercise.hpp>
#include <CompetativeExercise.hpp>

int main()
{
    std::vector<Point> list;
    std::cout << "Default generator of 3 objects" << std::endl;
    fillDefault(list, 3);
    print(list);

    std::vector<float> list2 = {1.1f, 1.2f, 1.3f};
    std::vector<float> list3 = reverse(list2);
    std::cout << "Reverse:" << std::endl;
    print(list3);

    std::vector<std::vector<float>> listOfLists = {list2, list3};
    std::cout << "Merge vectors:" << std::endl;
    print(mergeVectors(listOfLists));

    std::vector<int> listInt;
    std::cout << "Default generator of 3 objects" << std::endl;
    fillDefault(listInt, 3);
    print(listInt);

    std::cout << "Print vector in color: " << std::endl;
    printColor(listInt);

    std::cout << "Print vector in color red: " << std::endl;
    printColor<Red>(listInt);

    std::vector<float> floats = {0.1, 0.2, 0.3, 0.4, 0.5};
    std::cout << "Split floats into vectors of 2:" << std::endl;
    std::vector<std::vector<float>> splitFloats = slice(floats, 2);
    for(const auto& vec : splitFloats)
    {
        std::cout << "split: " << std::endl;
        print(vec);
    }

    std::vector<int> duplicated = { 1, 1, 1, 1, 1, 2, 2, 3, 3, 5};
    std::cout << "Removing duplicates:" << std::endl;
    std::vector<int> noDuplicated = removeDuplicates(duplicated);
    print(noDuplicated);

    std::vector<char> toDouble = {'H', 'e', 'l', 'o'};
    std::cout << "Doubling vector:" << std::endl;
    std::vector<char> doubled = doubleVector(toDouble);
    print(doubled);

    std::cout << "Removing duplicates:" << std::endl;
    std::vector<float> sliced = cut(floats, 3, 5);
    print(sliced);

    Person person("John", "Doe", 41, 73.5f, 185);
    Person competitor("Jane", "Doe", 45, 76.5f, 165);

    std::vector<Exercise*> exercises;
    exercises.push_back(new StrengthExercise("Curls", 120, Time::parse("00:12:13"), Difficulty::Easy, 40, person.getWeight(), 10, 10, MuscleGroup::Arms,Date(10, 7, 2003)));
    exercises.push_back(new CompetativeExercise(Difficulty::Hard, "Paul waulting", Time::parse("00:14:15"), 160, 92, Date(20, 12, 2013), &competitor, 123.53));
    exercises.push_back(new StrengthExercise("Leg press", 140, Time::parse("00:14:15"), Difficulty::Hard, 50,  person.getWeight(), 10, 10, MuscleGroup::Legs, Date(20, 12, 2013)));
    exercises.push_back(new StrengthExercise("Leg press", 140, Time::parse("00:14:15"), Difficulty::Hard, 50,  person.getWeight(), 10, 10, MuscleGroup::Legs, Date(20, 12, 2013)));
    exercises.push_back(new StrengthExercise("Leg press", 140, Time::parse("00:14:15"), Difficulty::Hard, 50,  person.getWeight(), 10, 10, MuscleGroup::Legs, Date(20, 12, 2013)));
    exercises.push_back(new CompetativeExercise(Difficulty::Hard, "Paul waulting", Time::parse("00:14:15"), 160, 92, Date(20, 12, 2013), &competitor, 123.53));

    uint32_t counted = count_type<CompetativeExercise>(exercises);

    std::cout << "Exercises of type Exercise: " << counted << std::endl;

    for(const auto& el : exercises)
        delete el;

    return 0;
}
