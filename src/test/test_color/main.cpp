#include <iostream>
#include <complex>
#include "../../lib/color/color.hpp"



int main()
{
    using namespace std::literals;
    using namespace raffer;

    constexpr auto color1 = Color{255, 4, 6};
    constexpr auto color2 = Color{7};

    std::cout << color1 + color2 << std::endl;
}
