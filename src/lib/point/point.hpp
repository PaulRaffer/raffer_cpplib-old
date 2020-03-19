#ifndef POINT_HPP
#define POINT_HPP

#include <cstddef>

namespace raffer
{

template <typename T, std::size_t dimensions>
class point
{
    T mat[dimensions];

public:
    [[nodiscard]] auto operator[](int dimension) const;
    [[nodiscard]] auto& operator[](int dimension);
};

}

namespace raffer
{

template <std::size_t dimensions>
auto operator+(point<auto, dimensions> const & lhs, point<auto, dimensions> const & rhs);

template <typename T, std::size_t dimensions> auto point<T, dimensions>::operator[](int dimension) const { return mat[dimension]; }
template <typename T, std::size_t dimensions> auto& point<T, dimensions>::operator[](int dimension) { return mat[dimension]; }

}



namespace raffer
{

template <typename T>
class point_2d : point<T, 2>
{
public:
    [[nodiscard]] constexpr auto get_x() const;
    auto set_x(T x);

    [[nodiscard]] constexpr auto get_y() const;
    auto set_y(T y);
};

}

namespace raffer
{
template <typename T> [[nodiscard]] constexpr auto point_2d<T>::get_x() const { return (*this)[0]; }
template <typename T> auto point_2d<T>::set_x(T x) { (*this)[0] = x; }

template <typename T> [[nodiscard]] constexpr auto point_2d<T>::get_y() const { return (*this)[1]; }
template <typename T> auto point_2d<T>::set_y(T y) { (*this)[1] = y; }

}


namespace raffer
{

template <typename T>
class point_3d : public point<T, 3>
{
public:
    [[nodiscard]] constexpr auto get_x() const;
    auto set_x(T x);

    [[nodiscard]] constexpr auto get_y() const;
    auto set_y(T y);

    [[nodiscard]] constexpr auto get_z() const;
    auto set_z(T x);
};

}

namespace raffer
{

template <typename T> [[nodiscard]] constexpr auto point_3d<T>::get_x() const { return (*this)[0]; }
template <typename T> auto point_3d<T>::set_x(T x) { (*this)[0] = x; }

template <typename T> [[nodiscard]] constexpr auto point_3d<T>::get_y() const { return (*this)[1]; }
template <typename T> auto point_3d<T>::set_y(T y) { (*this)[1] = y; }

template <typename T> [[nodiscard]] constexpr auto point_3d<T>::get_z() const { return (*this)[2]; }
template <typename T> auto point_3d<T>::set_z(T y) { (*this)[2] = y; }

}

#endif // POINT_HPP
