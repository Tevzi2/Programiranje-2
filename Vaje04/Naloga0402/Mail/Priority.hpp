#pragma once

#include <string>

#ifndef ENUM_TO_STRING
#define ENUM_TO_STRING(e) #e

#endif
enum Priority {
    Low,
    Normal,
    Critical
};

std::string priorityToString(Priority priority);