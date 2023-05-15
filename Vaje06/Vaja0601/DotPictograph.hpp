#pragma once

#include <PrintUtility.hpp>
#include <Graph.hpp>

class DotPictograph : public Graph {
    public:
        DotPictograph(const std::string& title, const std::vector<int>& data, char symbol);

        void setSymbol(char symbol);

        [[nodiscard]] char getSymbol() const;

        void show(ColorCode color) const override;

    private:
        char symbol;
};
