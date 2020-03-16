#include <iostream>
#include <functional>
#include "../../lib/overload_set/overload_set.hpp"


void func(int i) { std::cout << "int" << std::endl; }
//void func(double i) { std::cout << "double" << std::endl; }

int main ()
{
    using namespace raffer;

    auto lamdas = overload_set
    {
        //[](int i) { std::cout << "int" << std::endl; },
        [](auto... a) { std::cout << "auto" << std::endl; },
        [](double i) { std::cout << "double" << std::endl; },
        [](char c) { std::cout << c << std::endl; },
        std::function{func},
        []<typename T>(T t) { std::cout << "T" << std::endl; },
    };
    lamdas('ä');
    //lamdas(5.7);

    //logical_and(1, 0, 1);
}
