//
// Created by tevzb on 13. 05. 2023.
//

#include "Printer.h"

[[nodiscard]] std::string Printer::toString() const
{
    std::string accum;
    std::for_each(queue.begin(), queue.end(), [&accum](auto el) { accum += el; });

    return accum;
}

void Printer::print()
{
    std::for_each(queue.begin(), queue.end(), [](auto el) { std::cout << el << std::endl; });

    queue.clear();
}