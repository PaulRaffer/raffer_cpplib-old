#include "math.hpp"
#include <cmath>
#include <iostream>

namespace raffer
{

constexpr auto is_odd(/*std::integral*/ auto x) -> bool { return x & 1; }
constexpr auto is_even(/*std::integral*/ auto x) -> bool { return !is_odd(x); }

constexpr auto is_prime(/*std::integral*/ auto x) -> bool
{
    if (!(x % 2)) return false;
    for (auto i = 3; i <= sqrt(x); i += 2)
        if (!(x % i)) return false;
    return true;
}

constexpr auto prime(/*std::integral*/ auto x) -> int
{
    constexpr auto offset = 0;
    if (x == offset) return 2;
    auto p = 3;
    for (decltype(x) count = offset + 1; count < x; )
        if (is_prime(p += 2)) ++count;
    return p;
}

template auto is_odd(short int x) -> bool;
template auto is_odd(unsigned short int x) -> bool;
template auto is_odd(int x) -> bool;
template auto is_odd(unsigned int x) -> bool;
template auto is_odd(long int x) -> bool;
template auto is_odd(unsigned long int x) -> bool;
template auto is_odd(long long int x) -> bool;
template auto is_odd(unsigned long long int x) -> bool;

template auto is_even(short int x) -> bool;
template auto is_even(unsigned short int x) -> bool;
template auto is_even(int x) -> bool;
template auto is_even(unsigned int x) -> bool;
template auto is_even(long int x) -> bool;
template auto is_even(unsigned long int x) -> bool;
template auto is_even(long long int x) -> bool;
template auto is_even(unsigned long long int x) -> bool;


template auto is_prime(short int x) -> bool;
template auto is_prime(unsigned short int x) -> bool;
template auto is_prime(int x) -> bool;
template auto is_prime(unsigned int x) -> bool;
template auto is_prime(long int x) -> bool;
template auto is_prime(unsigned long int x) -> bool;
template auto is_prime(long long int x) -> bool;
template auto is_prime(unsigned long long int x) -> bool;

template auto prime(short int x) -> int;
template auto prime(unsigned short int x) -> int;
template auto prime(int x) -> int;
template auto prime(unsigned int x) -> int;
template auto prime(long int x) -> int;
template auto prime(unsigned long int x) -> int;
template auto prime(long long int x) -> int;
template auto prime(unsigned long long int x) -> int;
}
