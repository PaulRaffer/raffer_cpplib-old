
// Copyright (c) 2020 Paul Raffer.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#if __cplusplus >= 201703L

#ifndef RAFFER_SWITCH_SWITCH_HPP
#define RAFFER_SWITCH_SWITCH_HPP


#include <initializer_list>
#include <utility>


namespace raffer // interface
{

template <typename T1, typename T2>
[[nodiscard]] constexpr auto equ(T1 && a, T2 && b);

} // namespace raffer





namespace raffer // implementation
{

template <typename T1, typename T2>
constexpr auto equ(T1 && a, T2 && b){ return std::forward<T1>(a) == std::forward<T2>(b); }

} // namespace raffer





namespace raffer // interface
{

template <typename F_true, typename F_false = void (*)(), typename... Args>
constexpr auto if_(bool condition, F_true true_case, F_false false_case = []{}, Args&&... args);

template <typename T, typename F = void (*)(), bool (*equ)(T const &, T const &) = equ>
constexpr auto switch_(T const & condition, std::initializer_list<std::pair<T const, F>> const & cases);

} // namespace raffer





namespace raffer // implementation
{

template <typename F_true, typename F_false, typename... Args>
constexpr auto if_(bool condition, F_true true_case, F_false false_case, Args&&... args)
{ return condition ? true_case(args...) : false_case(args...); }


template <typename T, typename F, bool (*equ)(T const &, T const &)>
constexpr auto switch_(T const & condition, std::initializer_list<std::pair<T const, F>> const & cases)
{
	for (auto [value, action] : cases)
		if (equ(condition, value))
			return action();
	return typename std::invoke_result_t<F>();
}

} // namespace raffer


#endif // RAFFER_SWITCH_SWITCH_HPP

#endif // __cplusplus >= 201703L
