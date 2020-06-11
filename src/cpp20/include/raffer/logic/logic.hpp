#if __cplusplus >= 202002L

#ifndef RAFFER_LOGIC_LOGIC_HPP
#define RAFFER_LOGIC_LOGIC_HPP


#include <utility>


namespace raffer // interface
{

auto logical_not(auto x);
auto logical_and(auto && ...x);
auto logical_or(auto && ...x);
auto logical_nand(auto && ...x);
auto logical_nor(auto && ...x);
auto logical_xor(auto && ...x);
auto logical_xnor(auto && ...x);

auto bit_not(auto x);
auto bit_and(auto && ...x);
auto bit_or(auto && ...x);
auto bit_nand(auto && ...x);
auto bit_nor(auto && ...x);
auto bit_xor(auto && ...x);
auto bit_xnor(auto && ...x);

} // namespace raffer




namespace raffer // implementation
{

auto logical_not(auto && x) { return !std::forward<decltype(x)>(x); }
auto logical_and(auto && ...x) { return (... && std::forward<decltype(x)>(x)); }
auto logical_or(auto && ...x) { return (... || std::forward<decltype(x)>(x)); }
auto logical_nand(auto && ...x) { return logical_not(logical_and(std::forward<decltype(x)>(x)...)); }
auto logical_nor(auto && ...x) { return logical_not(logical_or(std::forward<decltype(x)>(x)...)); }

auto bit_not(auto && x) { return ~std::forward<decltype(x)>(x; }
auto bit_and(auto && ...x) { return (... & std::forward<decltype(x)>(x)); }
auto bit_or(auto && ...x) { return (... | std::forward<decltype(x)>(x)); }
auto bit_nand(auto && ...x) { return bit_not(bit_and(std::forward<decltype(x)>(x)...)); }
auto bit_nor(auto && ...x) { return bit_not(bit_or(std::forward<decltype(x)>(x)...)); }

} // namespace raffer


#endif // RAFFER_LOGIC_LOGIC_HPP

#endif // __cplusplus >= 202002L
