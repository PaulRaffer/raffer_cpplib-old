#include <iostream>
#include <complex>
#include "../../lib/color/color.hpp"

int main()
{
    using namespace std::literals;
    using namespace raffer;

    auto color1 = Color{255};
    auto color2 = Color{7};
    constexpr auto color3 = Color{11};

    //auto color4 = (++color1)++;
color1 += color2;

//(0.6 * color1).set_green(4);

    //(color1 += 2) = color3;
    std::cout << color1 << std::endl;




    auto i1 = 255;
    constexpr auto i2 = 7;
    constexpr auto i3 = 11;
//i1++ = 6;
    auto i4 = (++i1)++;
    //(i1 += 2) = i3;
    std::cout << i1 << std::endl;

    /*A a{3};
    A b{4};
    A c = a + b;
    A d = 8 + b;

    std::cout << c.i << ", " << d.i << std::endl;*/
}
