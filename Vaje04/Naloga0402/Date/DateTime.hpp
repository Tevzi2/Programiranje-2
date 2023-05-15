#ifndef TASK0401_DATETIME_H
#define TASK0401_DATETIME_H

#include <Date.hpp>
#include <Time.hpp>

class DateTime {
private:
    Date date;
    Time time;
public:
    DateTime(const Date &date, const Time &time);

    const Date &getDate() const;
    void setDate(const Date &date);

    const Time &getTime() const;
    void setTime(const Time &time);

    std::string toString() const;
};


#endif //TASK0401_DATETIME_H
