#include "Time.hpp"

Time::Time()
    :hours(0), minutes(0), seconds(0)
{

}

Time::Time(uint32_t hours, uint32_t minutes, uint32_t seconds)
    :hours(hours), minutes(minutes), seconds(seconds)
{
    if(!isTimeValid(this->hours, this->minutes, this->seconds))
    {
        this->hours = 0;
        this->minutes = 0;
        this->seconds = 0;
    }
}

[[nodiscard]] std::string Time::toString() const
{
    std::string out = formalize(hours) +
        ":" + formalize(minutes) +
        ":" + formalize(seconds);

    return out;
}

[[nodiscard]] bool Time::isTimeValid(uint32_t hours, uint32_t minutes, uint32_t seconds)
{
    return hours < MaxHours && minutes < MaxMinutes && seconds < MaxSeconds;
}

[[nodiscard]] Time Time::parse(const std::string& time)
{
    if(time.size() != 8) return {0, 0, 0};

    if(!(time[2] == ':' && time[5] == ':')) return {0, 0, 0};

    const uint32_t hours = unformalize(time.substr(0, 2));
    const uint32_t minutes = unformalize(time.substr(3, 2));
    const uint32_t seconds = unformalize(time.substr(6, 2));

    if(hours == BAD_TIME_VALUE || minutes == BAD_TIME_VALUE || seconds == BAD_TIME_VALUE) return {0, 0, 0};

    return {hours, minutes, seconds};
}

[[nodiscard]] std::vector<Time> Time::timeFromSeconds(const std::vector<uint32_t>& time)
{
    std::vector<Time> output;
    uint32_t hours, minutes, seconds;

    for(const auto& i : time)
    {
        output.push_back(secondsToTime(i));
    }

    return output;
}

[[nodiscard]] std::string Time::formalize(const uint32_t timeUnit)
{
    std::string out;
    if(timeUnit < 10)
        out += "0" + std::to_string(timeUnit);
    else
        out += std::to_string(timeUnit);

    return out;
}

[[nodiscard]] uint32_t Time::unformalize(const std::string& timeUnit)
{
    size_t size = timeUnit.size();

    if(size > 2) return BAD_TIME_VALUE;

    if(timeUnit[0] < '0' || timeUnit[0] > '9' || timeUnit[1] < '0' || timeUnit[1] > '9') return BAD_TIME_VALUE;

    uint32_t convertedTimeUnit = std::stoi(timeUnit, &size, 10);

    if(convertedTimeUnit >= BAD_TIME_VALUE) return BAD_TIME_VALUE;

    return convertedTimeUnit;
}

[[nodiscard]] Time Time::secondsToTime(uint32_t time) {
    uint32_t hours = time / HOURS_SECONDS;
    uint32_t minutes = (time % HOURS_SECONDS) / MINUTE_SECONDS;
    uint32_t seconds = ((time % HOURS_SECONDS) % MINUTE_SECONDS);

    return {hours, minutes, seconds};
}

[[nodiscard]] uint32_t Time::toSeconds() const
{
    return hours * 3600 + minutes * 60 + seconds;
}

[[nodiscard]] bool Time::operator<(Time r) const
{
    return this->toSeconds() < r.toSeconds();
}