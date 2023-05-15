#include "Exercise.hpp"

Exercise::Exercise(Difficulty difficulty, std::string name, Time duration, int32_t caloriesBurned, int32_t avgHeartRate, Date date)
    :difficulty(difficulty), name(std::move(name)), duration(duration), calloriesBurned(caloriesBurned), avgHeartRate(avgHeartRate), date(date)
{
    ;
}

Exercise::Exercise()
    :difficulty(Easy), duration(), avgHeartRate(0), calloriesBurned(0), date(0, 0, 0)
{
    ;
}

[[nodiscard]] std::string Exercise::getName() const
{
    return name;
}

[[nodiscard]] Time Exercise::getDuration() const
{
    return duration;
}

void Exercise::setDuration(Time newDuration)
{
    duration = newDuration;
}

[[nodiscard]] int32_t Exercise::getCalloriesBurned() const
{
    return calloriesBurned;
}

[[nodiscard]] int32_t Exercise::getAvgHeartRate() const
{
    return avgHeartRate;
}

[[nodiscard]] Difficulty Exercise::getDifficulty() const
{
    return difficulty;
}

void Exercise::setDifficulty(Difficulty difficulty)
{
    this->difficulty = difficulty;
}

[[nodiscard]] std::string Exercise::toString() const
{
    std::string out =
        "Activity: " +
        name +
        " | difficulty: " +
        enumToString(difficulty) +
        " | duration: " +
        duration.toString() +
        " | callories burned: " +
        std::to_string(calloriesBurned) +
        " | average heart rate: " +
        std::to_string(avgHeartRate);

    return out;
}

[[nodiscard]] const Exercise* Exercise::isMoreIntense(const Exercise* compare) const
{
    if(compare->calloriesBurned > this->calloriesBurned)
        return compare;
    else
        return this;
}

void Exercise::print() const
{
    std::cout << toString() << std::endl;
}

Date Exercise::getDate() const
{
    return date;
}

void Exercise::setDate(Date date)
{
    this->date = date;
}
