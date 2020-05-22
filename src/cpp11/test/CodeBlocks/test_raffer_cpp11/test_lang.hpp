#if __cplusplus >= 201103L

#ifndef RAFFER_TEST_LANG_HPP
#define RAFFER_TEST_LANG_HPP

#include "../../../../include/raffer/lang/cpp/cpp.hpp"


#include <iostream>

namespace raffer // test
{
namespace test__
{
namespace lang
{
namespace cpp
{


void all()
{
    clear_screen();
    enable_unicode();
    is_down();
    std::cout << __cplusplus;
    std::cin.ignore();

}


} // namespace cpp
} // namespace lang
} // namespace test__
} // namespace raffer


#endif // RAFFER_TEST_LANG_HPP

#endif //
