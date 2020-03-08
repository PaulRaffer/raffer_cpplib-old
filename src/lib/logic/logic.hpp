#ifndef LOGIC_HPP
#define LOGIC_HPP

namespace raffer
{

auto logical_not(auto x);
auto logical_and(auto... x);
auto logical_or(auto... x);
auto logical_nand(auto... x);
auto logical_nor(auto... x);
auto logical_xor(auto... x);
auto logical_xnor(auto... x);

auto bit_not(auto x);
auto bit_and(auto... x);
auto bit_or(auto... x);
auto bit_nand(auto... x);
auto bit_nor(auto... x);
auto bit_xor(auto... x);
auto bit_xnor(auto... x);

};



namespace raffer
{

auto logical_not(auto x) { return !x; }
auto logical_and(auto... x) { return (... && x); }
auto logical_or(auto... x) { return (... || x); }
auto logical_nand(auto... x) { return !logical_and(x...); }
auto logical_nor(auto... x) { return !logical_or(x...); }

auto bit_not(auto x) { return ~x; }
auto bit_and(auto... x) { return (... & x); }
auto bit_or(auto... x) { return (... | x); }
auto bit_nand(auto... x) { return ~bit_and(x...); }
auto bit_nor(auto... x) { return ~bit_or(x...); }

};


#endif // LOGIC_HPP
