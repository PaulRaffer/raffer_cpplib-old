#ifndef RAFFER_MATH_CPP14_MATH_HPP
#define RAFFER_MATH_CPP14_MATH_HPP


#if __cplusplus >= 201402L

namespace raffer // interface
{

template <typename T> [[nodiscard]] constexpr auto is_odd(T x) -> bool;
template <typename T> [[nodiscard]] constexpr auto is_even(T x) -> bool;

template <typename T> [[nodiscard]] constexpr auto is_prime(T x) -> bool;
template <typename T> [[nodiscard]] constexpr auto prime(T x) -> int;

} // namespace raffer

#endif



#if __cplusplus >= 201402L

#include <cmath>

namespace raffer // implementation
{

template <typename T> constexpr auto is_odd(T x) -> bool { return x & 1u; }
template <typename T> constexpr auto is_even(T x) -> bool { return !is_odd(x); }

template <typename T> constexpr auto is_prime(T x) -> bool
{
    if (!(x % 2)) return false;
    for (auto i = 3; i <= sqrt(x); i += 2)
        if (!(x % i)) return false;
    return true;
}

template <typename T> constexpr auto prime(T x) -> int
{
    constexpr auto offset = 0;
    if (x == offset) return 2;
    auto p = 3;
    for (decltype(x) count = offset + 1; count < x; )
        if (is_prime(p += 2)) ++count;
    return p;
}

} // namespace raffer

#endif


#endif // RAFFER_MATH_CPP14_MATH_HPP
