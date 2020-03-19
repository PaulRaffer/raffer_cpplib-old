#ifndef TYPE_HPP
#define TYPE_HPP

#include <string>
#include <sstream>

#include <locale>
#include <codecvt>

#include <cstring>

namespace raffer
{

template <typename Char> [[nodiscard]] constexpr auto to_basic_string(auto value, int precision = 6);

[[nodiscard]] auto to_string(std::wstring const & wstr) -> std::string;
[[nodiscard]] auto to_wstring(std::string const & str) -> std::wstring;

[[nodiscard]] auto to_char_array(wchar_t const * wchar_array) -> char const *;



[[nodiscard]] auto length(std::string const & str) -> size_t;
[[nodiscard]] auto length(std::wstring const & str) -> size_t;


}


namespace raffer
{

template <typename Char, typename T>
constexpr auto to_basic_string(T value, int precision)
{
    auto oss = std::basic_ostringstream<Char>{};
    oss.precision(precision);
    oss << value;
    return oss.str();
}



}

#endif // TYPE_HPP
