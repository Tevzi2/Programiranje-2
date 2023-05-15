#pragma once

#include<vector>
#include<string>

#define BAD_TIME_VALUE 60

#define HOURS_SECONDS 3600
#define MINUTE_SECONDS 60

class Time
{
    public:
        Time();

        Time(uint32_t hours, uint32_t minutes, uint32_t seconds);

        [[nodiscard]] std::string toString() const;

        [[nodiscard]] static bool isTimeValid(uint32_t hours, uint32_t minutes, uint32_t seconds);

        [[nodiscard]] static Time parse(const std::string& time);

        [[nodiscard]] static std::vector<Time> timeFromSeconds(const std::vector<uint32_t>& time);

        [[nodiscard]] uint32_t toSeconds() const;

    private:
        [[nodiscard]] static std::string formalize(uint32_t timeUnit);

        [[nodiscard]] static uint32_t unformalize(const std::string& timeUnit);

        [[nodiscard]] static Time secondsToTime(uint32_t time);

        static const uint32_t MaxHours = 24;
        static const uint32_t MaxMinutes = 60;
        static const uint32_t MaxSeconds = 60;

        uint32_t hours;
        uint32_t minutes;
        uint32_t seconds;
};