#if __cplusplus >= 202002L

#ifndef RAFFER_POINT_POINT_3D_HPP
#define RAFFER_POINT_POINT_3D_HPP


#include "point.hpp"


namespace raffer // interface
{

template <typename T>
class point_3d : public point<T, 3>
{
    using point<T, 3>::point;

public:
    constexpr point_3d(T x, T y, T z);

    [[nodiscard]] auto get_x() const;
    auto set_x(T x);

    [[nodiscard]] auto get_y() const;
    auto set_y(T y);

    [[nodiscard]] auto get_z() const;
    auto set_z(T x);
};

} // namespace raffer





namespace raffer // implementation
{

template <typename T> constexpr point_3d<T>::point_3d(T x, T y, T z) : point<T, 3>{{x, y, z}} {}

template <typename T> auto point_3d<T>::get_x() const { return (*this)[0]; }
template <typename T> auto point_3d<T>::set_x(T x) { (*this)[0] = x; }

template <typename T> auto point_3d<T>::get_y() const { return (*this)[1]; }
template <typename T> auto point_3d<T>::set_y(T y) { (*this)[1] = y; }

template <typename T> auto point_3d<T>::get_z() const { return (*this)[2]; }
template <typename T> auto point_3d<T>::set_z(T y) { (*this)[2] = y; }

} // namespace raffer


#endif // RAFFER_POINT_POINT_3D_HPP

#endif // __cplusplus >= 202002L
