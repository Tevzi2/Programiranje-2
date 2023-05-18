#pragma once

#include <string>

#define STRINGIFY_ENUM(e) #e

enum PressureUnit {
    PSI,
    PA
};

[[nodiscard]] std::string to_string(PressureUnit p);