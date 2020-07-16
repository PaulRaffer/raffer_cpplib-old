
// Copyright (c) 2020 Paul Raffer.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#if __cplusplus >= 201402L

#ifndef RAFFER_MATH_FRACTION_FRACTION_HPP
#define RAFFER_MATH_FRACTION_FRACTION_HPP


#include <utility>
#include <iostream>

#include "../../operators/comparison_operators.hpp"


namespace raffer // interface
{

template <typename Num, typename Den = Num>
class fraction
{
	Num num;
	Den den;
	
public:
	using num_type = Num;
	using den_type = Den;
	
	constexpr fraction(Num num = 0, Den den = 1);
	
	[[nodiscard]] explicit constexpr operator double() const;
	
	
	[[nodiscard]] constexpr auto get_num() const -> Num;
	
	auto set_num(Num const & num) -> void;
	auto set_num(Num && num) noexcept -> void;
	
	
	[[nodiscard]] constexpr auto get_den() const -> Den;
	
	auto set_den(Den const & den) -> void;
	auto set_den(Den && den) noexcept -> void;
};


template <typename Num, typename Den>
[[nodiscard]] constexpr auto get_num(fraction<Num, Den> const & f) -> Num;


template <typename Num, typename Den>
auto set_num(fraction<Num, Den> & f, Num const & num) -> void;

template <typename Num, typename Den>
auto set_num(fraction<Num, Den> & f, Num && num) noexcept -> void;



template <typename Num, typename Den>
[[nodiscard]] constexpr auto get_den(fraction<Num, Den> const & f) -> Den;


template <typename Num, typename Den>
auto set_den(fraction<Num, Den> & f, Den const & den) -> void;

template <typename Num, typename Den>
auto set_den(fraction<Num, Den> & f, Den && den) noexcept -> void;




template <typename Lhs_num, typename Lhs_den, typename Rhs_num, typename Rhs_den>
[[nodiscard]] constexpr auto cmp(fraction<Lhs_num, Lhs_den> const & lhs, fraction<Rhs_num, Rhs_den> const & rhs);

template <typename Lhs_num, typename Lhs_den, typename Rhs>
[[nodiscard]] constexpr auto cmp(fraction<Lhs_num, Lhs_den> const & lhs, Rhs const & rhs);

template <typename Lhs, typename Rhs_num, typename Rhs_den>
[[nodiscard]] constexpr auto cmp(Lhs const & lhs, fraction<Rhs_num, Rhs_den> const & rhs);




template <typename Rhs_num, typename Rhs_den>
[[nodiscard]] constexpr auto operator+(fraction<Rhs_num, Rhs_den> const & rhs);

template <typename Lhs_num, typename Lhs_den, typename Rhs_num, typename Rhs_den>
[[nodiscard]] constexpr auto operator+(fraction<Lhs_num, Lhs_den> const & lhs, fraction<Rhs_num, Rhs_den> const & rhs);

template <typename Lhs_num, typename Lhs_den, typename Rhs_num, typename Rhs_den>
auto & operator+=(fraction<Lhs_num, Lhs_den> & lhs, fraction<Rhs_num, Rhs_den> const & rhs);

template <typename Lhs_num, typename Lhs_den>
auto & operator++(fraction<Lhs_num, Lhs_den> & lhs);

template <typename Lhs_num, typename Lhs_den>
auto operator++(fraction<Lhs_num, Lhs_den> & lhs, int);


template <typename Rhs_num, typename Rhs_den>
[[nodiscard]] constexpr auto operator-(fraction<Rhs_num, Rhs_den> const & rhs);

template <typename Lhs_num, typename Lhs_den, typename Rhs_num, typename Rhs_den>
[[nodiscard]] constexpr auto operator-(fraction<Lhs_num, Lhs_den> const & lhs, fraction<Rhs_num, Rhs_den> const & rhs);

template <typename Lhs_num, typename Lhs_den, typename Rhs_num, typename Rhs_den>
auto & operator-=(fraction<Lhs_num, Lhs_den> & lhs, fraction<Rhs_num, Rhs_den> const & rhs);

template <typename Lhs_num, typename Lhs_den>
auto & operator--(fraction<Lhs_num, Lhs_den> & lhs);

template <typename Lhs_num, typename Lhs_den>
auto operator--(fraction<Lhs_num, Lhs_den> & lhs, int);


template <typename Lhs_num, typename Lhs_den, typename Rhs_num, typename Rhs_den>
[[nodiscard]] constexpr auto operator*(fraction<Lhs_num, Lhs_den> const & lhs, fraction<Rhs_num, Rhs_den> const & rhs);

template <typename Lhs_num, typename Lhs_den, typename Rhs_num, typename Rhs_den>
auto & operator*=(fraction<Lhs_num, Lhs_den> & lhs, fraction<Rhs_num, Rhs_den> const & rhs);


template <typename Lhs_num, typename Lhs_den, typename Rhs_num, typename Rhs_den>
[[nodiscard]] constexpr auto operator/(fraction<Lhs_num, Lhs_den> const & lhs, fraction<Rhs_num, Rhs_den> const & rhs);

template <typename Lhs_num, typename Lhs_den, typename Rhs_num, typename Rhs_den>
auto & operator/=(fraction<Lhs_num, Lhs_den> & lhs, fraction<Rhs_num, Rhs_den> const & rhs);




template <typename Num, typename Den>
auto operator<<(std::ostream & os, fraction<Num, Den> const & rhs) -> std::ostream &;

} // namespace raffer





namespace raffer // implementation
{

template <typename Num, typename Den>
constexpr fraction<Num, Den>::fraction(Num num, Den den)
: num{std::move(num)}, den{std::move(den)} {}



template <typename Num, typename Den>
constexpr fraction<Num, Den>::operator double() const
{ return static_cast<double>(num) / static_cast<double>(den); }




template <typename Num, typename Den>
constexpr auto fraction<Num, Den>::get_num() const -> Num
{ return num; }


template <typename Num, typename Den>
auto fraction<Num, Den>::set_num(Num const & num) -> void
{ this->num = num; }

template <typename Num, typename Den>
auto fraction<Num, Den>::set_num(Num && num) noexcept -> void
{ this->num = std::move(num); }



template <typename Num, typename Den>
constexpr auto fraction<Num, Den>::get_den() const -> Den
{ return den; }


template <typename Num, typename Den>
auto fraction<Num, Den>::set_den(Den const & den) -> void
{ this->den = den; }

template <typename Num, typename Den>
auto fraction<Num, Den>::set_den(Den && den) noexcept -> void
{ this->den = std::move(den); }



template <typename Num, typename Den>
constexpr auto get_num(fraction<Num, Den> const & f) -> Num
{ return f.get_num(); }


template <typename Num, typename Den>
auto set_num(fraction<Num, Den> & f, Num const & num) -> void
{ f.set_num(num); }

template <typename Num, typename Den>
auto set_num(fraction<Num, Den> & f, Num && num) noexcept -> void
{ f.set_num(std::move(num)); }



template <typename Num, typename Den>
constexpr auto get_den(fraction<Num, Den> const & f) -> Den
{ return f.get_den(); }


template <typename Num, typename Den>
auto set_den(fraction<Num, Den> & f, Den const & den) -> void
{ f.set_den(den); }

template <typename Num, typename Den>
auto set_den(fraction<Num, Den> & f, Den && den) noexcept -> void
{ f.set_den(std::move(den)); }




template <typename Lhs_num, typename Lhs_den, typename Rhs_num, typename Rhs_den>
[[nodiscard]] constexpr auto cmp(fraction<Lhs_num, Lhs_den> const & lhs, fraction<Rhs_num, Rhs_den> const & rhs)
{
	auto const lhs_num = lhs.get_num() * rhs.get_den();
	auto const rhs_num = rhs.get_num() * lhs.get_den();
	return
		lhs_num < rhs_num ? -1 :
		lhs_num > rhs_num ? 1 :
		0;
}

template <typename Lhs_num, typename Lhs_den, typename Rhs>
[[nodiscard]] constexpr auto cmp(fraction<Lhs_num, Lhs_den> const & lhs, Rhs const & rhs)
{ return cmp(lhs, fraction<Rhs>{rhs}); }

template <typename Lhs, typename Rhs_num, typename Rhs_den>
[[nodiscard]] constexpr auto cmp(Lhs const & lhs, fraction<Rhs_num, Rhs_den> const & rhs)
{ return cmp(fraction<Lhs>{lhs}, rhs); }




template <typename Rhs_num, typename Rhs_den>
constexpr auto operator+(fraction<Rhs_num, Rhs_den> const & rhs)
{ return rhs; }

template <typename Lhs_num, typename Lhs_den, typename Rhs_num, typename Rhs_den>
constexpr auto operator+(fraction<Lhs_num, Lhs_den> const & lhs, fraction<Rhs_num, Rhs_den> const & rhs)
{
	auto num = lhs.get_num() * rhs.get_den() + rhs.get_num() * lhs.get_den();
	auto den = lhs.get_den() * rhs.get_den();
	return fraction<decltype(num), decltype(den)>{num, den};
}

template <typename Lhs_num, typename Lhs_den, typename Rhs_num, typename Rhs_den>
auto & operator+=(fraction<Lhs_num, Lhs_den> & lhs, fraction<Rhs_num, Rhs_den> const & rhs)
{ return lhs = lhs + rhs; }

template <typename Lhs_num, typename Lhs_den>
auto & operator++(fraction<Lhs_num, Lhs_den> & lhs)
{ return lhs += fraction<Lhs_num, Lhs_den>{1}; }

template <typename Lhs_num, typename Lhs_den>
auto operator++(fraction<Lhs_num, Lhs_den> & lhs, int)
{
	auto const old = lhs;
	++lhs;
	return old;
}


template <typename Rhs_num, typename Rhs_den>
constexpr auto operator-(fraction<Rhs_num, Rhs_den> const & rhs)
{
	auto num = -rhs.get_num();
	auto den = rhs.get_den();
	return fraction<decltype(num), decltype(den)>{num, den};
}

template <typename Lhs_num, typename Lhs_den, typename Rhs_num, typename Rhs_den>
constexpr auto operator-(fraction<Lhs_num, Lhs_den> const & lhs, fraction<Rhs_num, Rhs_den> const & rhs)
{ return lhs + -rhs; }

template <typename Lhs_num, typename Lhs_den, typename Rhs_num, typename Rhs_den>
auto & operator-=(fraction<Lhs_num, Lhs_den> & lhs, fraction<Rhs_num, Rhs_den> const & rhs)
{ return lhs = lhs - rhs; }

template <typename Lhs_num, typename Lhs_den>
auto & operator--(fraction<Lhs_num, Lhs_den> & lhs)
{ return lhs -= fraction<Lhs_num, Lhs_den>{1}; }

template <typename Lhs_num, typename Lhs_den>
auto operator--(fraction<Lhs_num, Lhs_den> & lhs, int)
{
	auto const old = lhs;
	--lhs;
	return old;
}


template <typename Lhs_num, typename Lhs_den, typename Rhs_num, typename Rhs_den>
constexpr auto operator*(fraction<Lhs_num, Lhs_den> const & lhs, fraction<Rhs_num, Rhs_den> const & rhs)
{
	auto num = lhs.get_num() * rhs.get_num();
	auto den = lhs.get_den() * rhs.get_den();
	return fraction<decltype(num), decltype(den)>{num, den};
}

template <typename Lhs_num, typename Lhs_den, typename Rhs_num, typename Rhs_den>
auto & operator*=(fraction<Lhs_num, Lhs_den> & lhs, fraction<Rhs_num, Rhs_den> const & rhs)
{ return lhs = lhs * rhs; }


template <typename Num, typename Den>
constexpr auto reciprocal(fraction<Num, Den> f)
{
	auto const num = f.get_num();
	f.set_num(f.get_den());
	f.set_den(num);
	return f;
}

template <typename Lhs_num, typename Lhs_den, typename Rhs_num, typename Rhs_den>
constexpr auto operator/(fraction<Lhs_num, Lhs_den> const & lhs, fraction<Rhs_num, Rhs_den> const & rhs)
{ return lhs * reciprocal(rhs); }

template <typename Lhs_num, typename Lhs_den, typename Rhs_num, typename Rhs_den>
auto & operator/=(fraction<Lhs_num, Lhs_den> & lhs, fraction<Rhs_num, Rhs_den> const & rhs)
{ return lhs = lhs / rhs; }




template <typename Num, typename Den>
auto operator<<(std::ostream & os, fraction<Num, Den> const & rhs) -> std::ostream &
{ return os << "(" << rhs.get_num() << "/" << rhs.get_den() << ")"; }

} // namespace raffer


#endif // RAFFER_MATH_FRACTION_FRACTION_HPP

#endif // __cplusplus >= 201402L
