
// Copyright (c) 2020 Paul Raffer.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#if __cplusplus >= 201703L

#ifndef RAFFER_LOGIC_LOGIC_HPP
#define RAFFER_LOGIC_LOGIC_HPP


#include <utility>


namespace raffer // interface
{

template <typename T> [[nodiscard]] constexpr auto logical_not(T && x);
template <typename... T> [[nodiscard]] constexpr auto logical_and(T && ...x);
template <typename... T> [[nodiscard]] constexpr auto logical_or(T && ...x);
template <typename... T> [[nodiscard]] constexpr auto logical_nand(T && ...x);
template <typename... T> [[nodiscard]] constexpr auto logical_nor(T && ...x);
template <typename... T> [[nodiscard]] constexpr auto logical_xor(T && ...x);
template <typename... T> [[nodiscard]] constexpr auto logical_xnor(T && ...x);

template <typename T> [[nodiscard]] constexpr auto bit_not(T && x);
template <typename... T> [[nodiscard]] constexpr auto bit_and(T && ...x);
template <typename... T> [[nodiscard]] constexpr auto bit_or(T && ...x);
template <typename... T> [[nodiscard]] constexpr auto bit_nand(T && ...x);
template <typename... T> [[nodiscard]] constexpr auto bit_nor(T && ...x);
template <typename... T> [[nodiscard]] constexpr auto bit_xor(T && ...x);
template <typename... T> [[nodiscard]] constexpr auto bit_xnor(T && ...x);

} // namespace raffer





namespace raffer // implementation
{

template <typename T> constexpr auto logical_not(T && x) { return !std::forward<T>(x); }
template <typename... T> constexpr auto logical_and(T && ...x) { return (... && std::forward<T>(x)); }
template <typename... T> constexpr auto logical_or(T && ...x) { return (... || std::forward<T>(x)); }
template <typename... T> constexpr auto logical_nand(T && ...x) { return logical_not(logical_and(std::forward<T>(x)...)); }
template <typename... T> constexpr auto logical_nor(T && ...x) { return logical_not(logical_or(std::forward<T>(x)...)); }

template <typename T> constexpr auto bit_not(T && x) { return ~std::forward<T>(x); }
template <typename... T> constexpr auto bit_and(T && ...x) { return (... & std::forward<T>(x)); }
template <typename... T> constexpr auto bit_or(T && ...x) { return (... | std::forward<T>(x)); }
template <typename... T> constexpr auto bit_nand(T && ...x) { return bit_not(bit_and(std::forward<T>(x)...)); }
template <typename... T> constexpr auto bit_nor(T && ...x) { return bit_not(bit_or(std::forward<T>(x)...)); }

} // namespace raffer


#endif // RAFFER_LOGIC_LOGIC_HPP

#endif // __cplusplus >= 201703L
