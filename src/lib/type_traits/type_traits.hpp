#ifndef TYPE_TRAITS_HPP
#define TYPE TRAITS_HPP

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

template <
    typename T>
struct is_stl_container
: std::false_type {};


template <typename... Args> struct is_stl_container<std::array<Args...>> : std::true_type {};
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


template <
    typename T>
constexpr auto is_stl_container_v = is_stl_container<T>::value;

#endif // TYPE_TRAITS_HPP
