#include <iostream>
#include <complex>
#include "../../lib/experimental/color/color.hpp"
#include "../../lib/type/type.hpp"



int main()
{
    using namespace std::literals;
    using namespace raffer;

    constexpr auto color1 = Color{255, 4, 6};
    constexpr auto color2 = Color{7};

    std::complex c = 6i + std::complex{7.};

    std::cin >> c;
    std::cout << c << std::endl;
}
