#include <DateTime.hpp>

DateTime::DateTime(const Date &date, const Time &time) : date(date), time(time) {}

const Date &DateTime::getDate() const {
    return date;
}

void DateTime::setDate(const Date &date) {
    DateTime::date = date;
}

const Time &DateTime::getTime() const {
    return time;
}

void DateTime::setTime(const Time &time) {
    DateTime::time = time;
}

std::string DateTime::toString() const {
    return date.toString() + " " + time.toString();
}
