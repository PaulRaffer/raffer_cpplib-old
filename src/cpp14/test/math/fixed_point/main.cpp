#include <iostream>

#include "../../../include/raffer/math/fixed_point/fixed_point.hpp"

auto main() -> int
{
    auto fp1 = raffer::fixed_point<int, std::ratio<1, 100000>>{ 10 };
    auto fp2 = raffer::fixed_point<int, std::ratio<1, 1000000>>{ fp1 };
    

    std::cout << fp1 << " | " << fp1.get_r() << std::endl;
    std::cout << fp2 << " | " << fp2.get_r() << std::endl;

    
}
