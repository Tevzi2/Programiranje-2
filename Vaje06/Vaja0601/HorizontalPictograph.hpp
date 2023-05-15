#pragma once

#include <Graph.hpp>
#include <PrintUtility.hpp>

class HorizontalPictograph : public Graph {
    public:
        HorizontalPictograph(const std::string& title, const std::vector<int>& data, char symbol);

        void setSymbol(char symbol);

        [[nodiscard]] char getSymbol() const;

        void show(ColorCode color) const override;

    private:
        char symbol;

};
