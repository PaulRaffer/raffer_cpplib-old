#if __cplusplus >= 201402L

#ifndef RAFFER_MATH_MATH_HPP
#define RAFFER_MATH_MATH_HPP

#define raffer_cpplib_math__          202006L
#define raffer_cpplib_math_odd_even__ 202005L
#define raffer_cpplib_math_prime__    202005L
#define raffer_cpplib_math_digit__    202006L


#include <cmath>


namespace raffer // interface
{

template <typename T> constexpr auto is_odd(T x) -> bool;
template <typename T> constexpr auto is_even(T x) -> bool;

template <typename T> constexpr auto is_prime(T x) -> bool;
template <typename T> constexpr auto prime(T x) -> int;


template <typename T> auto digit(T x, int d, int n = 1, int base = 10) -> int;

} // namespace raffer





namespace raffer // implementation
{

template <typename T> constexpr auto is_odd(T x) -> bool { return x & 1; }
template <typename T> constexpr auto is_even(T x) -> bool { return !is_odd(x); }

template <typename T> constexpr auto is_prime(T x) -> bool
{
	if (!(x % 2))
		return false;
	for (auto i = 3; i <= sqrt(x); i += 2)
		if (!(x % i))
			return false;
	return true;
}

template <typename T> constexpr auto prime(T x) -> int
{
	constexpr auto offset = 0;
	if (x == offset)
		return 2;
	auto p = 3;
	for (decltype(x) count = offset + 1; count < x; )
		if (is_prime(p += 2))
			++count;
	return p;
}



template <typename T>
auto digit(T x, int d, int n, int base) -> int
{
	return
		static_cast<int>(x / std::pow(base, d))
		% static_cast<int>(std::pow(base, n));
}

} // namespace raffer


#endif // RAFFER_MATH_MATH_HPP

#endif // __cplusplus >= 201402L