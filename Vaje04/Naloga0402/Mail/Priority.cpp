#include <Priority.hpp>

std::string priorityToString(Priority priority)
{
    const char* priorityStringify[] = {
        ENUM_TO_STRING(Low),
        ENUM_TO_STRING(Normal),
        ENUM_TO_STRING(Critical)
    };

    return std::string(priorityStringify[priority]);
}