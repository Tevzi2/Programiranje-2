#pragma once

#include <Graph.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <PrintUtility.hpp>

class VerticalPictograph : public Graph
{
    public:
        VerticalPictograph(const std::string& title, const std::vector<int>& data, char symbol);

        void setSymbol(char symbol);

        [[nodiscard]] char getSymbol() const;

        void show(ColorCode color) const override;

    private:
        char symbol;
};