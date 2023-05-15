#include <iostream>
#include <VerticalPictograph.hpp>
#include <DotPictograph.hpp>
#include <HorizontalPictograph.hpp>
#include <CubePictograph.hpp>

int main()
{
    using namespace std::string_literals;

    VerticalPictograph vp("Pictograph", std::vector<int>{5, 1, 3, 4}, '*');
    vp.show(ColorCode::Blue);

    std::cout << std::endl;

    DotPictograph vp2("Neka preglednca a ne", std::vector<int>{7, 1, 8, 9, 6, 3, 2, 2}, '#');
    vp2.show(ColorCode::Green);

    std::cout << std::endl;

    HorizontalPictograph hz("Nakljucni podatki", std::vector<int>{1, 1, 2, 3, 5, 8, 5, 3, 3, 2 ,1}, '%');
    hz.show(ColorCode::Red);

    std::cout << std::endl;

    CubePictograph cb("Podatki", std::vector<int>{5, 6, 1});
    cb.show(ColorCode::Green);

    return 0;
}