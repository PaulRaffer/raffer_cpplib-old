#include <iostream>
#include <functional>
#include <type_traits>
#include "../../lib/logic/logic.hpp"
#include "../../lib/overload_set/overload_set.hpp"


void func(int i) { std::cout << "int" << std::endl; }
//void func(double i) { std::cout << "double" << std::endl; }

int main ()
{
    using namespace raffer;

    std::cout << logical_and(1, 0, 1);
}
