#include <iostream>
#include <complex>
#include "../../lib/color/color.hpp"


int main()
{
    using namespace std::literals;
    using namespace raffer;

    auto a = Color<short>{5, 7, 2};
    auto b = Color<short>{5, 7, 2};
    auto c = a + b;


    std::cout << a;
}
