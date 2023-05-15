#pragma once

#include <string>

#ifndef STRINGIFY_ENUM
#define STRINGIFY_ENUM(enum) #enum
#endif

enum Difficulty {
    Easy,
    Normal,
    Hard
};

[[nodiscard]] std::string enumToString(Difficulty difficulty);