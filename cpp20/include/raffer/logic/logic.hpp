
// Copyright (c) 2020 Paul Raffer.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#if __cplusplus >= 202002L

#ifndef RAFFER_LOGIC_LOGIC_HPP
#define RAFFER_LOGIC_LOGIC_HPP


#include <utility>


namespace raffer // interface
{

[[nodiscard]] constexpr auto logical_not(auto x);
[[nodiscard]] constexpr auto logical_and(auto && ...x);
[[nodiscard]] constexpr auto logical_or(auto && ...x);
[[nodiscard]] constexpr auto logical_nand(auto && ...x);
[[nodiscard]] constexpr auto logical_nor(auto && ...x);
[[nodiscard]] constexpr auto logical_xor(auto && ...x);
[[nodiscard]] constexpr auto logical_xnor(auto && ...x);

[[nodiscard]] constexpr auto bit_not(auto x);
[[nodiscard]] constexpr auto bit_and(auto && ...x);
[[nodiscard]] constexpr auto bit_or(auto && ...x);
[[nodiscard]] constexpr auto bit_nand(auto && ...x);
[[nodiscard]] constexpr auto bit_nor(auto && ...x);
[[nodiscard]] constexpr auto bit_xor(auto && ...x);
[[nodiscard]] constexpr auto bit_xnor(auto && ...x);

} // namespace raffer




namespace raffer // implementation
{

constexpr auto logical_not(auto && x) { return !std::forward<decltype(x)>(x); }
constexpr auto logical_and(auto && ...x) { return (... && std::forward<decltype(x)>(x)); }
constexpr auto logical_or(auto && ...x) { return (... || std::forward<decltype(x)>(x)); }
constexpr auto logical_nand(auto && ...x) { return logical_not(logical_and(std::forward<decltype(x)>(x)...)); }
constexpr auto logical_nor(auto && ...x) { return logical_not(logical_or(std::forward<decltype(x)>(x)...)); }

constexpr auto bit_not(auto && x) { return ~std::forward<decltype(x)>(x; }
constexpr auto bit_and(auto && ...x) { return (... & std::forward<decltype(x)>(x)); }
constexpr auto bit_or(auto && ...x) { return (... | std::forward<decltype(x)>(x)); }
constexpr auto bit_nand(auto && ...x) { return bit_not(bit_and(std::forward<decltype(x)>(x)...)); }
constexpr auto bit_nor(auto && ...x) { return bit_not(bit_or(std::forward<decltype(x)>(x)...)); }

} // namespace raffer


#endif // RAFFER_LOGIC_LOGIC_HPP

#endif // __cplusplus >= 202002L
