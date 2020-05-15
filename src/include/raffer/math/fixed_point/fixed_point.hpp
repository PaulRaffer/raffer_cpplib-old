#ifndef RAFFER_MATH_FIXED_POINT_FIXED_POINT_HPP
#define RAFFER_MATH_FIXED_POINT_FIXED_POINT_HPP

#include <ratio>
#include <cstdint>
#include <type_traits>
#include <utility>
#include <iostream>


namespace raffer // interface
{

template <typename Rep = std::intmax_t, typename Factor = std::ratio<1>>
class fixed_point
{
    static_assert(std::is_integral<Rep>::value, "Rep has to be an integral type!");

    Rep r;

public:
	using rep = Rep;
	using factor = Factor;

	constexpr fixed_point(Rep r = Rep{});
    constexpr fixed_point(double value);
    template <typename Rhs_rep, typename Rhs_factor, typename f = std::ratio_divide<Rhs_factor, Factor>>
    constexpr fixed_point(fixed_point<Rhs_rep, Rhs_factor> const & rhs);

    constexpr operator double() const;

    [[nodiscard]] constexpr auto get_r() const -> Rep;
};

//auto operator<<(std::ostream & os, fixed_point const & rhs) -> std::ostream &;

} // namespace raffer



namespace raffer // impementation
{

template <typename Rep, typename Factor>
constexpr fixed_point<Rep, Factor>::fixed_point(Rep r)
: r { std::move(r) } {}

template <typename Rep, typename Factor>
constexpr fixed_point<Rep, Factor>::fixed_point(double value)
: r ( value * factor::den / factor::num ) {}

template <typename Lhs_rep, typename Lhs_factor>
template <typename Rhs_rep, typename Rhs_factor, typename f>
constexpr fixed_point<Lhs_rep, Lhs_factor>::fixed_point(fixed_point<Rhs_rep, Rhs_factor> const & rhs)
: r ( rhs.get_r() * f::num / f::den ) {}




template <typename Rep, typename Factor>
constexpr fixed_point<Rep, Factor>::operator double() const
{ return r * static_cast<double>(factor::num) / factor::den; }
/*
template <typename Rep, typename Factor>
auto operator<<(std::ostream & os, fixed_point<Rep, Factor> const & rhs) -> std::ostream &
{ return os << rhs.value * rhs.factor::num / rhs.factor::den; }
*/

template <typename Rep, typename Factor>
[[nodiscard]] constexpr auto fixed_point<Rep, Factor>::get_r() const -> Rep
{ return r; }

} // namespace raffer

#endif // RAFFER_MATH_FIXED_POINT_FIXED_POINT_HPP
