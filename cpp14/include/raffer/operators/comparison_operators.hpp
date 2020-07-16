
// Copyright (c) 2020 Paul Raffer.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#if __cplusplus >= 201402L

#ifndef RAFFER_OPERATORS_COMPARISON_OPERATORS_HPP
#define RAFFER_OPERATORS_COMPARISON_OPERATORS_HPP


#include <utility>


namespace raffer // interface
{

template <typename Lhs, typename Rhs>
[[nodiscard]] constexpr auto cmp(Lhs const & lhs, Rhs const & rhs);

template <typename Lhs, typename Rhs>
[[nodiscard]] constexpr auto operator==(Lhs && lhs, Rhs && rhs);

template <typename Lhs, typename Rhs>
[[nodiscard]] constexpr auto operator!=(Lhs && lhs, Rhs && rhs);

template <typename Lhs, typename Rhs>
[[nodiscard]] constexpr auto operator<(Lhs && lhs, Rhs && rhs);

template <typename Lhs, typename Rhs>
[[nodiscard]] constexpr auto operator>(Lhs && lhs, Rhs && rhs);

template <typename Lhs, typename Rhs>
[[nodiscard]] constexpr auto operator<=(Lhs && lhs, Rhs && rhs);

template <typename Lhs, typename Rhs>
[[nodiscard]] constexpr auto operator>=(Lhs && lhs, Rhs && rhs);

} // namespace raffer





namespace raffer // implementation
{

template <typename Lhs, typename Rhs>
constexpr auto cmp(Lhs const & lhs, Rhs const & rhs)
{
	return
		lhs < rhs ? -1 :
		rhs < lhs ? 1 :
		0;
}

template <typename Lhs, typename Rhs>
constexpr auto operator==(Lhs && lhs, Rhs && rhs)
{ return cmp(std::forward<Lhs>(lhs), std::forward<Rhs>(rhs)) == 0; }

template <typename Lhs, typename Rhs>
constexpr auto operator!=(Lhs && lhs, Rhs && rhs)
{ return !(std::forward<Lhs>(lhs) == std::forward<Rhs>(rhs)); }

template <typename Lhs, typename Rhs>
constexpr auto operator<(Lhs && lhs, Rhs && rhs)
{ return cmp(std::forward<Lhs>(lhs), std::forward<Rhs>(rhs)) < 0; }

template <typename Lhs, typename Rhs>
constexpr auto operator>(Lhs && lhs, Rhs && rhs)
{ return std::forward<Rhs>(rhs) < std::forward<Lhs>(lhs); }

template <typename Lhs, typename Rhs>
constexpr auto operator<=(Lhs && lhs, Rhs && rhs)
{ return !(std::forward<Lhs>(lhs) > std::forward<Rhs>(rhs)); }

template <typename Lhs, typename Rhs>
constexpr auto operator>=(Lhs && lhs, Rhs && rhs)
{ return !(std::forward<Lhs>(lhs) < std::forward<Rhs>(rhs)); }

} // namespace raffer


#endif // RAFFER_OPERATORS_COMPARISON_OPERATORS_HPP

#endif // __cplusplus >= 201402L
