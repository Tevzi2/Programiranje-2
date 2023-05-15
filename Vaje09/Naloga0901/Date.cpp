#include "Date.hpp"

Date::Date(unsigned int day, unsigned int month, unsigned int year) : day(day), month(month), year(year) {}

unsigned int Date::getDay() const {
    return day;
}

void Date::setDay(unsigned int day) {
    Date::day = day;
}

unsigned int Date::getMonth() const {
    return month;
}

void Date::setMonth(unsigned int month) {
    Date::month = month;
}

unsigned int Date::getYear() const {
    return year;
}

void Date::setYear(unsigned int year) {
    Date::year = year;
}

std::string Date::toString() const {
    return std::to_string(day) + ". " + std::to_string(month) + ". " + std::to_string(year);
}

bool Date::operator==(const Date& other) const
{
    return (day == other.day) && (month == other.month) && (year == other.year);
}

Date Date::operator++()
{
     day++;

     if(day > months[month-1])
     {
         day = 1;
         month++;
     }

     if(month > 12)
     {
         month = 1;
         year++;
     }

     return *this;
}

Date Date::operator++(int dummy)
{
    Date temp = *this;

    day++;

    if(day > months[month-1])
    {
        day = 1;
        month++;
    }

    if(month > 12)
    {
        month = 1;
        year++;
    }

    return temp;
}

bool Date::operator<(Date& other)
{
    return (year < other.year) ||
            ((year <= other.year) && (month < other.month)) ||
            ((year <= other.year) && (month <= other.month) && (day < other.day));
}
