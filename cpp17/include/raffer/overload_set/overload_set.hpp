
// Copyright (c) 2020 Paul Raffer.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#if __cplusplus >= 201702L

#ifndef RAFFER_OVERLOAD_SET_OVERLOAD_SET_HPP
#define RAFFER_OVERLOAD_SET_OVERLOAD_SET_HPP


namespace raffer // interface
{

template <typename... F> struct overload_set : public F... { using F::operator()...; };
template <typename... F> overload_set(F&&...) -> overload_set<F...>;

} // namespace  raffer


#endif // RAFFER_OVERLOAD_SET_OVERLOAD_SET_HPP

#endif // __cplusplus >= 201702L
