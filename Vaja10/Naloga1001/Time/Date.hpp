#ifndef TASK0401_DATE_H
#define TASK0401_DATE_H

#include <string>

class Date {
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
public:
    Date(unsigned int day, unsigned int month, unsigned int year);

    unsigned int getDay() const;
    void setDay(unsigned int day);

    unsigned int getMonth() const;
    void setMonth(unsigned int month);

    unsigned int getYear() const;
    void setYear(unsigned int year);

    std::string toString() const;
};


#endif //TASK0401_DATE_H
