#ifndef TYPE_HPP
#define TYPE_HPP

#include <string>
#include <sstream>

#include <locale>
#include <codecvt>

namespace raffer
{

template <typename Out = char, typename In>
[[nodiscard]]
constexpr auto to_string(In const value, int const precision = 6) -> std::basic_string<Out>;


template <typename Out, typename In>
constexpr auto to_string(In const value, int const precision) -> std::basic_string<Out>
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

};

#endif // TYPE_HPP
