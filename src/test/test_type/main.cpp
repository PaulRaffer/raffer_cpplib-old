#include "../../lib/type/type.hpp"
#include <iostream>

#include <string>

int main()
{
    using namespace raffer;

    std::wcout << to_basic_string<wchar_t>(123) << std::endl;
    std::cout << to_basic_string<char>(1.2) << std::endl;
    std::wcout << to_basic_string<wchar_t>('ä') << std::endl;
    std::cout << to_basic_string<char>("Hallo Welt!") << std::endl;
    std::cout << to_string(L"gahhe") << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << length(L"Hallo");
}
