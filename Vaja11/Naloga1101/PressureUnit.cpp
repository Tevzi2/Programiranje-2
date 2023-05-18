#include <PressureUnit.hpp>

const char* pressureUnitStrings[] = {
    STRINGIFY_ENUM(PSI),
    STRINGIFY_ENUM(PA)
};

[[nodiscard]] std::string to_string(PressureUnit p)
{
    return std::string{pressureUnitStrings[p]};
}