#pragma once

#include <Exercise.hpp>
#include <StrengthExercise.hpp>
#include <iostream>

class PrintIfStrengthExercise
{
    public:
        void operator()(Exercise*) const;
};