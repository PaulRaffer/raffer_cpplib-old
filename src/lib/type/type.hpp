#ifndef TYPE_HPP
#define TYPE_HPP

#include <string>
#include <sstream>

#include <locale>
#include <codecvt>

#include <cstring>

namespace raffer
{

template <typename Out, typename In>
[[nodiscard]]
constexpr auto to_basic_string(In const value, int const precision = 6) -> std::basic_string<Out>;

auto string_to_wstring(std::string const & str);
auto wstring_to_string(std::wstring const & wstr);

auto to_char_array(wchar_t const * wchar_array) -> char const *;

}


namespace raffer
{

template <typename Out, typename In>
constexpr auto to_basic_string(In const value, int const precision) -> std::basic_string<Out>
{
    auto oss = std::basic_ostringstream<Out>{};
    oss.precision(precision);
    oss << value;
    return oss.str();
}


auto string_to_wstring(std::string const & str)
{
    return std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(str);
}
auto wstring_to_string(std::wstring const & wstr)
{
    return std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(wstr);
}


auto to_char_array(wchar_t const * wchar_array) -> char const *
{
    auto len = wcslen(wchar_array);
    auto char_array = new char[len + 1];
    memset(char_array, 0, len + 1);
    wcstombs(char_array, wchar_array, len);
    return char_array;
}

}

#endif // TYPE_HPP
