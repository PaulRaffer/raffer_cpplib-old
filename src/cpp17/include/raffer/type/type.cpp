#if __cplusplus >= 201703L

#include "type.hpp"


namespace raffer // implementation
{

template <>
auto to_basic_string<char>(std::wstring wstr) -> std::string
{ return std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(wstr); }

auto to_string(std::wstring const & wstr) -> std::string { return std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(wstr); }
auto to_wstring(std::string const & str) -> std::wstring { return std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(str); }


auto to_char_array(char const * char_array) -> char const *
{ return char_array; }

auto to_char_array(wchar_t const * wchar_array) -> char const *
{
    auto len = wcslen(wchar_array);
    auto char_array = new char[len + 1];
    memset(char_array, 0, len + 1);
    wcstombs(char_array, wchar_array, len);
    return char_array;
}


auto length(std::string const & str) -> size_t { return str.length(); }
auto length(std::wstring const & str) -> size_t { return str.length(); }

} // namespace raffer


#endif // __cplusplus >= 201703L
