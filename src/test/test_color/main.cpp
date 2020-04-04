#include <iostream>
#include <complex>
#include "../../lib/color/color.hpp"


int main()
{
    using namespace std::literals;
    using namespace raffer;

    constexpr auto a = color<short>{5, 7, 2};
    auto b = color<short>{5, 7, 2};
    auto c = a + b;
a.get_green();
    //a = white;

    std::cout << a;
}
