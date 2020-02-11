#include <iostream>
#include <complex>
#include "../../lib/experimental/color/color.hpp"
#include "../../lib/type/type.hpp"

using namespace std::literals;

int main()
{
    constexpr auto color = Color{255, 4, 6};
    constexpr auto color2 = Color{7};

    std::cout << color + color2 + white << std::endl;
}
