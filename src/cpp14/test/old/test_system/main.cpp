#include "../../lib/experimental/system/system.hpp"
#include <iostream>

int main()
{
    using namespace raffer;

    std::cout << "Hallo";
    clear_screen();
    std::cout << " Welt!\n";
    enable_unicode();
    std::wcout << "ä";
}
