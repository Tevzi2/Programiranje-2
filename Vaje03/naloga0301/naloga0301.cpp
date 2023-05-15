#include "Time.hpp"
#include <iostream>

int main()
{
    Time t1 = Time(23, 59, 59);
    Time t2 = Time(15, 5, 3);
    Time t3 = Time(24, 34, 43);
    Time* t4 = new Time(12, 50, 34);
    Time t5 = Time::parse("13:15:59");
    Time t6 = Time::parse("14:5:60:");
    Time t7 = Time::parse("0123");
    Time t8 = Time::parse("1234567890");
    Time t9 = Time::parse("24:59:59");

    std::vector<uint32_t> seconds;
    seconds.push_back(49522);
    seconds.push_back(20);
    seconds.push_back(61);

    std::vector<Time> t10 = Time::timeFromSeconds(seconds);

    std::cout << "A valid timestamp (14, 13, 24): " << Time::isTimeValid(14, 13, 24) << std::endl;
    std::cout << "A valid timestamp (0, 0, 0): " << Time::isTimeValid(0, 0, 0) << std::endl;
    std::cout << "A invalid timestamp (24, 5, 5): " << Time::isTimeValid(24, 5, 5) << std::endl;
    std::cout << "A invalid timestamp (5, 60, 5): " << Time::isTimeValid(5, 60, 5) << std::endl;
    std::cout << "A invalid timestamp (5, 5, 60): " << Time::isTimeValid(5, 5, 60) << std::endl;
    std::cout << "A invalid timestamp (100, 54, 23): " << Time::isTimeValid(100, 54, 23) << std::endl;

    std::cout << "Time t1 toString: " << t1.toString() << std::endl;
    std::cout << "Time t2 toString: " << t2.toString() << std::endl;
    std::cout << "Time t3 toString: " << t3.toString() << std::endl;

    std::cout << "Time t6 incoract value given to parser (14:5:60:): " << t6.toString() << std::endl;
    std::cout << "Time t7 incoract value given to parser (0123): " << t7.toString() << std::endl;
    std::cout << "Time t8 incoract value given to parser (1234567890): " << t8.toString() << std::endl;
    std::cout << "Time t9 incoract value given to parser (24:59:59): " << t9.toString() << std::endl;

    std::cout << "Time of t4 that was dynamicaly allocated: " << t4->toString() << std::endl;
    std::cout << "Time of t5 that was parsed: " << t5.toString() << std::endl;

    for(const auto& time : t10)
    {
        std::cout << "Times in t10: " << time.toString() << std::endl;
    }

    delete t4;

    return 0;
}