//
// Created by tevzb on 13. 05. 2023.
//

#include "PrintIfStrengthExercise.h"

void PrintIfStrengthExercise::operator()(Exercise* ex) const
{
    if(StrengthExercise* s = dynamic_cast<StrengthExercise*>(ex); s != nullptr)
        std::cout << ex->toString() << std::endl;
}