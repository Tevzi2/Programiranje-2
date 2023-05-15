#include "Exercise.hpp"

Exercise::Exercise(std::string name, float duration, int32_t caloriesBurned, int32_t avgHeartRate)
    :name(std::move(name)), duration(duration), calloriesBurned(caloriesBurned), avgHeartRate(avgHeartRate)
{
    ;
}

Exercise::Exercise()
    :duration(0), avgHeartRate(0), calloriesBurned(0)
{
    ;
}

[[nodiscard]] std::string Exercise::getName() const
{
    return name;
}

[[nodiscard]] float Exercise::getDuration() const
{
    return duration;
}

void Exercise::setDuration(float newDuration)
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

[[nodiscard]] std::string Exercise::toString() const
{
    std::string out =
        "Activity: " +
        name +
        ", duration: " +
        std::to_string(duration) +
        ", callories burned: " +
        std::to_string(calloriesBurned) +
        ", average heart rate: " +
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