#ifndef RAFFER_MATH_HPP

namespace raffer
{
    [[nodiscard]] constexpr auto is_odd(/*std::integral*/ auto x) -> bool;
    [[nodiscard]] constexpr auto is_even(/*std::integral*/ auto x) -> bool;

    [[nodiscard]] constexpr auto is_prime(/*std::integral*/ auto x) -> bool;
    [[nodiscard]] constexpr auto prime(/*std::integral*/ auto x) -> int;
}

#endif // RAFFER_MATH_HPP
