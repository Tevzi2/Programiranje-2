#pragma once

#include <string>

#ifndef STRINGIFY_ENUM
#define STRINGIFY_ENUM(enum) #enum
#endif

enum MuscleGroup{Legs, Back, Arms};

std::string muscleGroupToString(MuscleGroup group);
