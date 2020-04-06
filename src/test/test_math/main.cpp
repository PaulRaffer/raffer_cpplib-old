#include <iostream>
#include "../../lib/math/math.hpp"
#include <cmath>

auto main() -> int
{
    for (auto i = 0; i < 1000; ++i)
        std::cout << raffer::prime(i) << std::endl;
}
