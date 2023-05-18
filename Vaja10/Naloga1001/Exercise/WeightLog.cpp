//
// Created by Tevz on 18/05/2023.
//

#include <WeightLog.hpp>

WeightLog::WeightLog(Date date, float weight)
    : date(date), weight(weight)
{
    ;
}

float WeightLog::getWeight() const {
    return weight;
}

const Date &WeightLog::getDate() const {
    return date;
}

void WeightLog::setDate(const Date &date) {
    WeightLog::date = date;
}

void WeightLog::setWeight(float weight) {
    WeightLog::weight = weight;
}

[[nodiscard]] std::string WeightLog::toString() const
{
    std::string out;
    out += "Weight log: Weight: " +
        std::to_string(weight) +
        " Date: " +
        date.toString();

    return out;
}
