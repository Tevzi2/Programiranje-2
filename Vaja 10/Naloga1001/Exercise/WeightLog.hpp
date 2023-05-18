#pragma once

#include <Date.hpp>

class WeightLog {
    public:
        WeightLog(Date date, float weight);

        [[nodiscard]] float getWeight() const;

        [[nodiscard]] const Date &getDate() const;

        void setDate(const Date &date);

        void setWeight(float weight);

        [[nodiscard]] std::string toString() const;

        friend std::ostream& operator<<(std::ostream &out, const WeightLog& log)
        {
            out << log.toString();
            return out;
        }

private:
        Date date;
        float weight;
};
