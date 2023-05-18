//
// Created by Tevz on 21/03/2023.
//

#include <MuscleGroup.hpp>

std::string muscleGroupToString(MuscleGroup group)
{
    const char* muscleGroupStringiy[] = {
        STRINGIFY_ENUM(Legs),
        STRINGIFY_ENUM(Back),
        STRINGIFY_ENUM(Arms)
    };

    return { muscleGroupStringiy[group] };
}
