#include <iostream>
#include <functional>
#include <type_traits>
#include "../../lib/logic/logic.hpp"
#include "../../lib/overloaded/overloaded.hpp"


void func(int i) { std::cout << "int" << std::endl; }
//void func(double i) { std::cout << "double" << std::endl; }

int main ()
{
    using namespace raffer;

    auto lamdas = overloaded
    {
        //[](int i) { std::cout << "int" << std::endl; },
        [](auto... a) { std::cout << "auto" << std::endl; },
        [](double i) { std::cout << "double" << std::endl; },
        std::function{func},
        []<typename T>(T t) { std::cout << "T" << std::endl; },
    };
    lamdas('ä');
    //lamdas(5.7);

    //logical_and(1, 0, 1);
}
