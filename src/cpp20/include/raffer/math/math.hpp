#if __cplusplus >= 202002L

#ifndef RAFFER_MATH_MATH_HPP
#define RAFFER_MATH_MATH_HPP


#include <cmath>


namespace raffer // interface
{

[[nodiscard]] constexpr auto is_odd(std::integral auto x);
[[nodiscard]] constexpr auto is_even(std::integral auto x);

[[nodiscard]] constexpr auto is_prime(std::integral auto x);
[[nodiscard]] constexpr auto prime(std::integral auto x);

} // namespace raffer





namespace raffer // implementation
{

constexpr auto is_odd(std::integral auto x) { return x & 1; }
constexpr auto is_even(std::integral auto x) { return !is_odd(x); }

constexpr auto is_prime(std::integral auto x)
{
    if (!(x % 2))
        return false;
    for (auto i = 3; i <= sqrt(x); i += 2)
        if (!(x % i))
            return false;
    return true;
}

constexpr auto prime(std::integral auto x)
{
    constexpr auto offset = 0;
    if (x == offset)
        return 2;
    auto p = 3;
    for (decltype(x) count = offset + 1; count < x; )
        if (is_prime(p += 2))
            ++count;
    return p;
}

} // namespace raffer


#endif // RAFFER_MATH_MATH_HPP

#endif // __cplusplus >= 202002L
