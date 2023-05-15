//
// Created by Tevz on 09/04/2023.
//

#include <CubePictograph.hpp>

CubePictograph::CubePictograph(const std::string& title, const std::vector<int>& data)
    : Graph(title, data)
{
    ;
}

void CubePictograph::show(ColorCode color) const
{
    int total = 0;

    std::vector<int> perc;

    for(const auto& val : data)
        total += val;

    for(const auto& val : data)
        perc.push_back(ceil((float)(val * 100) / (float)total));

    std::cout << title << std::endl;
    uint32_t c = 0;
    uint32_t n = 0;
    char v = 'a';
    for(uint32_t i = 0; i < 100; i++)
    {
        if(n < data.size() && c < perc[n])
        {
            if(i % 10 == 0 && i != 0) std::cout << std::endl;
            PrintUtility::printSequence(color, std::string{(char)(v+n)}, 2);
            c++;
        }

        if(c >= perc[n]){
            n++;
            c = 0;
        }
    }
}