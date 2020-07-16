
// Copyright (c) 2020 Paul Raffer.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#if __cplusplus >= 201703L

#ifndef RAFFER_CONTAINER_IS_STL_CONTAINER_HPP
#define RAFFER_CONTAINER_IS_STL_CONTAINER_HPP


#include <type_traits>

#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>

#include <stack>
#include <queue>

#include <set>
#include <map>

#include <unordered_set>
#include <unordered_map>


namespace raffer // interface
{

template <typename C> struct is_stl_container : std::false_type {};


template <typename T, std::size_t N> struct is_stl_container<std::array<T, N>> : std::true_type {};
template <typename... Args> struct is_stl_container<std::vector<Args...>> : std::true_type {};
template <typename... Args> struct is_stl_container<std::deque<Args...>> : std::true_type {};
template <typename... Args> struct is_stl_container<std::forward_list<Args...>> : std::true_type {};
template <typename... Args> struct is_stl_container<std::list<Args...>> : std::true_type {};

template <typename... Args> struct is_stl_container<std::stack<Args...>> : std::true_type {};
template <typename... Args> struct is_stl_container<std::queue<Args...>> : std::true_type {};
template <typename... Args> struct is_stl_container<std::priority_queue<Args...>> : std::true_type {};

template <typename... Args> struct is_stl_container<std::set<Args...>> : std::true_type {};
template <typename... Args> struct is_stl_container<std::multiset<Args...>> : std::true_type {};
template <typename... Args> struct is_stl_container<std::map<Args...>> : std::true_type {};
template <typename... Args> struct is_stl_container<std::multimap<Args...>> : std::true_type {};

template <typename... Args> struct is_stl_container<std::unordered_set<Args...>> : std::true_type {};
template <typename... Args> struct is_stl_container<std::unordered_multiset<Args...>> : std::true_type {};
template <typename... Args> struct is_stl_container<std::unordered_map<Args...>> : std::true_type {};
template <typename... Args> struct is_stl_container<std::unordered_multimap<Args...>> : std::true_type {};


template <typename C> constexpr auto is_stl_container_v = is_stl_container<C>::value;

} // namespace raffer


#endif // RAFFER_CONTAINER_IS_STL_CONTAINER_HPP

#endif // __cplusplus >= 201703L
