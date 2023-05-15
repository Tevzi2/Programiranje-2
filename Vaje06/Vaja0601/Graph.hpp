#pragma once

#include <string>
#include <vector>
#include <ColorCode.hpp>

class Graph
{
    public:
        Graph(const std::string& title, const std::vector<int>& data);

        void setTitle(const std::string& title);

        void setData(const std::vector<int>& data);

        [[nodiscard]] std::string getTitle() const;

        [[nodiscard]] std::vector<int> getData() const;

        [[nodiscard]] int getMaxValue() const;

        [[nodiscard]] int getMinValue() const;

        virtual void show(ColorCode color) const = 0;

    protected:
        std::string title;
        std::vector<int> data;
};