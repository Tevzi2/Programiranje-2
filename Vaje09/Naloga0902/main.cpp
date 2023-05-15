#include <SmartPointer.hpp>
#include <iostream>
#include <Date.hpp>

int main()
{
    SmartPointer<int> num(0);
    SmartPointer<Date> someDate(31, 5, 2007);

    std::cout << "Value of number at setting: " << *num << std::endl;

    (*num)++;

    std::cout << "Value of number after setting: " << *num << std::endl;

    std::cout << "Some date: " << *someDate << std::endl;

    (*someDate)++;

    std::cout << "Some date after postfixed increment: " << *someDate << std::endl;

    ++(*someDate);

    std::cout << "Some date after prefixed increment: " << *someDate << std::endl;

    std::cout << "Is the same date the same: " << (*someDate == *someDate) << std::endl;

    std::shared_ptr<Date> date = std::make_shared<Date>(12, 5, 200);

    std::shared_ptr<Date> dateTwo = date;

    std::cout << "Number of copies of date in shared pointer: " << dateTwo.use_count() << std::endl;

    {

        SmartPointer<Date> date1(1, 1, 2020);
        SmartPointer<Date> date2(1, 1, 2019);

        date2 = date1 = date1 = date1 = date1 = date1;

        date2 = date2;

        date2 = date2;

        std::cout << "Reference count in custom smart pointer: " << date2.useCount() << std::endl;
    }

    SmartPointer<Date> smtn;

    std::cout << "Is uninitialized smart pointer equal to nullptr: " << (smtn == nullptr) << std::endl;

    std::cout << "Is uninitialized smart pointer not equal to nullptr: " << (smtn != nullptr) << std::endl;

    std::cout << "Is initialized smart pointer equal to nullptr: " << (dateTwo == nullptr) << std::endl;

    std::cout << "Is initialized smart pointer not equal to nullptr: " << (dateTwo != nullptr) << std::endl;

    std::cout << "Is initialized smart pointer not equal to itself: " << (dateTwo != dateTwo) << std::endl;

    std::cout << "Is initialized smart pointer equal to itself: " << (dateTwo == dateTwo) << std::endl;

    return 0;
}