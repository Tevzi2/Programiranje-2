#pragma once

#include <Graph.hpp>
#include <PrintUtility.hpp>
#include <cmath>

class CubePictograph : public Graph {
    public:
        CubePictograph(const std::string& title, const std::vector<int>& data);

        void show(ColorCode color) const override;
};
