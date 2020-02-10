#ifndef TYPE_HPP
#define TYPE_HPP

#include <string>
#include <sstream>

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

#endif // TYPE_HPP
