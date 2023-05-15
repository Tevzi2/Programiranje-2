#include <DotPictograph.hpp>

DotPictograph::DotPictograph(const std::string& title, const std::vector<int>& data, char symbol)
    : Graph(title, data), symbol(symbol)
{
    ;
}

void DotPictograph::setSymbol(char symbol)
{
    this->symbol = symbol;
}

[[nodiscard]] char DotPictograph::getSymbol() const
{
    return symbol;
}

void DotPictograph::show(ColorCode color) const
{
    std::cout << title << std::endl;
    int maxValue = getMaxValue();

    for(uint32_t i = maxValue; i > 0; i--)
    {
        std::string out;
        for(int j : data)
        {
            if(j == i)
            {
                out += symbol;
                out += " ";
            }
            else
                out += "  ";
        }
        out += "\n";
        PrintUtility::print(color, out);
    }

    PrintUtility::printSequence(ColorCode::Default, "- ", data.size());

    std::cout << std::endl;

    for(const auto& val : data)
        PrintUtility::print(ColorCode::Default, std::to_string(val) + " ");

    std::cout << std::endl;
}