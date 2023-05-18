#include <Difficulty.hpp>

const char* difficultyStringify[] = {
    STRINGIFY_ENUM(Easy),
    STRINGIFY_ENUM(Normal),
    STRINGIFY_ENUM(Hard)
};

[[nodiscard]] std::string enumToString(Difficulty difficulty)
{
    return difficultyStringify[difficulty];
}