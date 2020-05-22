#if __cplusplus >= 201103L

#ifndef RAFFER_TEST_SYSTEM_HPP
#define RAFFER_TEST_SYSTEM_HPP


#include "../../../../include/raffer/system/system.hpp"

#include <iostream>

namespace raffer // test
{
namespace test__
{
namespace system
{

void clear_screen()
{
    std::cout <<
        "+------------------------------+\n"
        "| clear_screen():              |\n"
        "+------------------------------+\n";

    std::cout << "Hello ";
    raffer::clear_screen();
    std::cout << "World!";

    std::cout << std::endl << std::endl;
}

void enable_unicode()
{
    std::cout <<
        "+------------------------------+\n"
        "| enable_unicode():            |\n"
        "+------------------------------+\n";

    {
        std::wstring str;
        std::cout << "\nPlease enter a unicode string: ";
        std::wcin >> str;
        std::wcout << str;
        std::wcin.sync();
    }
    {
        std::wstring str;
        std::cout << "\nPlease enter a unicode string: ";
        raffer::enable_unicode_stdio();
        std::wcin >> str;
        std::wcout << str;
        std::wcin.sync();
        raffer::disable_unicode_stdio();
    }

    std::cout << std::endl << std::endl;
}


void is_down()
{
    std::cout <<
        "+------------------------------+\n"
        "| is_down():                   |\n"
        "+------------------------------+\n";

    std::cout << "\nIs key 'A' pressed? ";
    for (int i = 0; i < 100000; ++i)
        std::cout << raffer::is_down(key('A')) << '\b';

    std::cout << std::endl << std::endl;
}

void all()
{
    clear_screen();
    enable_unicode();
    is_down();
    std::cout << __cplusplus;
    std::cin.ignore();

}

} // namespace system
} // namespace test__
} // namespace raffer


#endif // RAFFER_TEST_SYSTEM_HPP

#endif // __cplusplus >= 201103L
