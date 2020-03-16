#include "../../lib/switch/switch.hpp"

#include <iostream>
#include <functional>



int main()
{
    raffer::switch_(3, {
    {1, []{
        return 6;
    }},
    {2, []{
        std::cout << "0" << std::endl;
        return 3;
    }},
    {3, []{ std::cout << "3" << std::endl;
        return 4;
    }},
    {4, []{
        std::cout << "2" << std::endl;
        return 2;
    }},
    });

    /*std::cout << raffer::if_(false,
        [](int i){ std::cout << "Hallo" << std::endl; return i; },
        [](double i){ std::cout << "Welt!" << std::endl; return i*2; },
        5
    );*/
}
