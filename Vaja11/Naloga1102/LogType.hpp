#pragma once

#include <string>

#ifndef STRINGIFY_ENUM
#define STRINGIFY_ENUM(e) #e
#endif

enum LogType
{
    DEBUG,
    INFO,
    WARN,
    ERROR
};

[[nodiscard]] std::string to_string(LogType);