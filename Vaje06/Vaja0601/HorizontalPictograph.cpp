//
// Created by Tevz on 09/04/2023.
//

#include <HorizontalPictograph.hpp>
#include <cmath>

HorizontalPictograph::HorizontalPictograph(const std::string& title, const std::vector<int>& data, char symbol)
    : Graph(title, data), symbol(symbol)
{
    ;
}

void HorizontalPictograph::setSymbol(char symbol)
{
    this->symbol = symbol;
}

[[nodiscard]] char HorizontalPictograph::getSymbol() const
{
    return symbol;
}

void HorizontalPictograph::show(ColorCode color) const
{
    std::cout << title << std::endl;
    for(const auto& val : data)
    {
        std::cout << val << " | ";
        PrintUtility::printSequence(color, std::string{symbol}, val);
        std::cout << std::endl;
    }
}
