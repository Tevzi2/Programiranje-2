#include <SmartPointer.hpp>
#include <iostream>
#include <Date.hpp>
#include <memory>

int main()
{
    SmartPointer<int> num(0);
    SmartPointer<Date> someDate(31, 5, 2007);

    std::cout << "Value of number at setting" << *num << std::endl;

    (*num)++;

    std::cout << "Value of number after setting" << *num << std::endl;

    std::cout << "Some date: " << *someDate << std::endl;

    std::cout << "Some date after postfixed increment: " << (*someDate)++ << std::endl;

    std::cout << "Value after prefix op: " << (*someDate) << std::endl;

    std::cout << "Some date after prefixed increment: " << ++(*someDate) << std::endl;

    std::cout << "Is the same date the same: " << (*someDate == *someDate) << std::endl;

    std::shared_ptr<Date> date = std::make_shared<Date>(12, 5, 200);

    std::shared_ptr<Date> date2 = date;

    std::cout << "Number of copies of date in shared pointer: " << date2.use_count() << std::endl;

    SmartPointer<Date> d1(1, 2, 2021);
    SmartPointer<Date> d2(1, 1, 2022);
    std::cout << "Is " << (*d1) << " earlier than " << (*d2) << "? " << ((*d1 < *d2) ? "Yes." : "No.") << std::endl;

    return 0;
}