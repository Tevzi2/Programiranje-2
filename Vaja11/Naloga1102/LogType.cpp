#include <LogType.hpp>

const char* string_log_type[] = {
    STRINGIFY_ENUM(DEBUG),
    STRINGIFY_ENUM(INFO),
    STRINGIFY_ENUM(WARN),
    STRINGIFY_ENUM(ERROR)
};

[[nodiscard]] std::string to_string(LogType t)
{
    return string_log_type[t];
}