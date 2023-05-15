#include "Exercise.hpp"

int main()
{
    Exercise ex1 = Exercise();
    Exercise ex2 = Exercise("Boxing", 352.74f, 1234, 123);
    Exercise ex3 = Exercise("Keyboard typing", 62353.29f, 9000, 68);
    Exercise* ex4 = new Exercise("Jogging", 1237.43f, 326, 154);
    Exercise* ex5 = new Exercise("Bench press", 53.65f, 8323, 103);
    Exercise ex6 = Exercise(ex1);

    std::cout << "The exercise name for ex2 is: " << ex2.getName() << std::endl;
    std::cout << "The duration of exercise ex3 was: " << ex3.getDuration() << std::endl;
    std::cout << "The amount of callories used on ex3 was: " << ex3.getCalloriesBurned() << std::endl;
    std::cout << "The average heartRate of ex4 was: " << ex4->getAvgHeartRate() << std::endl;

    ex2.setDuration(543.12);

    std::cout << "The excercies that is more intense from Jogging and Bench press is: " << ex4->isMoreIntense(ex5)->getName() << std::endl;

    std::cout << "The new duration for ex2 is: " << ex2.getDuration() << std::endl;
    std::cout << "The entire exercise description for ex5 is: " << ex5->toString() << std::endl;
    std::cout << "Ex4 print: " << std::endl;

    ex4->print();

    delete ex4;
    delete ex5;

    return 0;
}