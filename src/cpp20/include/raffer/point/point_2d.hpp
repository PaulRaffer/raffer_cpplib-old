#ifndef RAFFER_POINT_POINT_2D_HPP
#define RAFFER_POINT_POINT_2D_HPP


#if __cplusplus >= 202002L

#include "point.hpp"

namespace raffer // interface
{

template <typename T>
class point_2d : point<T, 2>
{
    using point<T, 2>::point;

public:
    constexpr point_2d(T x, T y);

    [[nodiscard]] auto get_x() const;
    auto set_x(T x);

    [[nodiscard]] auto get_y() const;
    auto set_y(T y);
};

} // namespace raffer

#endif // __cplusplus >= 202002L




#if __cplusplus >= 202002L

namespace raffer // implementation
{

template <typename T>
constexpr point_2d<T>::point_2d(T x, T y)
: point<T, 2>{{x, y}} {}

template <typename T> auto point_2d<T>::get_x() const { return (*this)[0]; }
template <typename T> auto point_2d<T>::set_x(T x) { (*this)[0] = x; }

template <typename T> auto point_2d<T>::get_y() const { return (*this)[1]; }
template <typename T> auto point_2d<T>::set_y(T y) { (*this)[1] = y; }

} // namespace raffer

#endif // __cplusplus >= 202002L


#endif // RAFFER_POINT_POINT_2D_HPP
