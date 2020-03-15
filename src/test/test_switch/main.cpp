#include "../../lib/switch/switch.hpp"

#include <iostream>

int main()
{
    raffer::switch_(3, {
    {1, []{
        //return 6;
    }},
    {2, []{
        std::cout << "0" << std::endl;
        //return 3;
    }},
    {3, []{ std::cout << "3" << std::endl;
        //return 4;
    }},
    {4, []{
        std::cout << "2" << std::endl;
        //return 2;
    }},
    });
}
