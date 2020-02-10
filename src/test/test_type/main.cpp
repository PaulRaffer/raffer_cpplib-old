#include "../../lib/type/type.hpp"
#include <iostream>
#include <iomanip>
#include <complex>

int main()
{
    std::cout << to_string(123) << std::endl;
    std::cout << to_string(1.2) << std::endl;
    std::cout << to_string('a') << std::endl;
    std::cout << to_string("Hallo Welt!") << std::endl;
}
