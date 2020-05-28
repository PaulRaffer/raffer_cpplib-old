#if __cplusplus >= 201703L

#ifndef RAFFER_LOGIC_LOGIC_HPP
#define RAFFER_LOGIC_LOGIC_HPP


#include <utility>

namespace raffer // interface
{

template <typename T> auto logical_not(T && x);
template <typename... T> auto logical_and(T && ...x);
template <typename... T> auto logical_or(T && ...x);
template <typename... T> auto logical_nand(T && ...x);
template <typename... T> auto logical_nor(T && ...x);
template <typename... T> auto logical_xor(T && ...x);
template <typename... T> auto logical_xnor(T && ...x);

template <typename T> auto bit_not(T && x);
template <typename... T> auto bit_and(T && ...x);
template <typename... T> auto bit_or(T && ...x);
template <typename... T> auto bit_nand(T && ...x);
template <typename... T> auto bit_nor(T && ...x);
template <typename... T> auto bit_xor(T && ...x);
template <typename... T> auto bit_xnor(T && ...x);

} // namespace raffer




namespace raffer // implementation
{

template <typename T> auto logical_not(T && x) { return !std::forward<T>(x); }
template <typename... T> auto logical_and(T && ...x) { return (... && std::forward<T>(x)); }
template <typename... T> auto logical_or(T && ...x) { return (... || std::forward<T>(x)); }
template <typename... T> auto logical_nand(T && ...x) { return logical_not(logical_and(std::forward<T>(x)...)); }
template <typename... T> auto logical_nor(T && ...x) { return logical_not(logical_or(std::forward<T>(x)...)); }

template <typename T> auto bit_not(T && x) { return ~std::forward<T>(x); }
template <typename... T> auto bit_and(T && ...x) { return (... & std::forward<T>(x)); }
template <typename... T> auto bit_or(T && ...x) { return (... | std::forward<T>(x)); }
template <typename... T> auto bit_nand(T && ...x) { return bit_not(bit_and(std::forward<T>(x)...)); }
template <typename... T> auto bit_nor(T && ...x) { return bit_not(bit_or(std::forward<T>(x)...)); }

} // namespace raffer


#endif // RAFFER_LOGIC_LOGIC_HPP

#endif // __cplusplus >= 201703L
