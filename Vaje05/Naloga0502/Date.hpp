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

    //returns the current date
    static Date getCurrentDate();
    //returns the number of days since unix epoch which is 1. 1. 1970 (date - Date(1, 1, 1970))
    static unsigned int daysSinceEpoch(const Date& date);
    //returns difference between provided dates in days
    static int getDifferenceDays(const Date& date1, const Date& date2);
};


#endif //TASK0401_DATE_H
