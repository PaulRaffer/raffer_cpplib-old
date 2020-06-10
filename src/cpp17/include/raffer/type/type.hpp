#if __cplusplus >= 201703L

#ifndef RAFFER_TYPE_TYPE_HPP
#define RAFFER_TYPE_TYPE_HPP


#include <string>
#include <sstream>

#include <locale>
#include <codecvt>

#include <cstring>

namespace raffer // interface
{

template <typename Char, int precision = 6, typename T>
[[nodiscard]] auto to_basic_string(T value) -> std::basic_string<Char>;

template <>
[[nodiscard]] auto to_basic_string<char>(std::wstring wstr) -> std::string;

//template <>
//[[nodiscard]] auto to_basic_string<char>(std::wstring wstr);

[[nodiscard]] auto to_string(std::wstring const & wstr) -> std::string;
[[nodiscard]] auto to_wstring(std::string const & str) -> std::wstring;

[[nodiscard]] auto to_char_array(char const * char_array) -> char const *;
[[nodiscard]] auto to_char_array(wchar_t const * wchar_array) -> char const *;



[[nodiscard]] auto length(std::string const & str) -> size_t;
[[nodiscard]] auto length(std::wstring const & str) -> size_t;

} // namespace raffer




namespace raffer // implementation
{

template <typename Char, int precision, typename T>
auto to_basic_string(T value) -> std::basic_string<Char>
{
    auto oss = std::basic_ostringstream<Char>{};
    oss.precision(precision);
    oss << value;
    return oss.str();
}



} // namespace raffer


#endif // RAFFER_TYPE_TYPE_HPP

#endif // __cplusplus >= 201703L
