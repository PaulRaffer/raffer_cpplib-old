#ifndef POINT_HPP
#define POINT_HPP

#include <cstddef>
#include <array>

namespace raffer
{

template <typename T, std::size_t D>
class point
{
public:
    using value_type = T;
    constexpr static auto dimensions = D;

    constexpr point();
    constexpr point(std::array<T, D> const & rhs);


    [[nodiscard]] auto operator[](int dimension) const;
    [[nodiscard]] auto& operator[](int dimension);

private:
    std::array<value_type, dimensions> values;
};

template <std::size_t dimensions>
auto operator+(point<auto, dimensions> const & lhs, point<auto, dimensions> const & rhs);

}

namespace raffer
{

template <typename T, std::size_t D> constexpr point<T, D>::point() : values{} {}
template <typename T, std::size_t D> constexpr point<T, D>::point(std::array<T, D> const & rhs) : values{rhs} {}

template <typename T, std::size_t dimensions> auto point<T, dimensions>::operator[](int dimension) const { return values[dimension]; }
template <typename T, std::size_t dimensions> auto& point<T, dimensions>::operator[](int dimension) { return values[dimension]; }

}



namespace raffer
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

}

namespace raffer
{

template <typename T> constexpr point_2d<T>::point_2d(T x, T y) : point<T, 2>{{x, y}} {}

template <typename T> [[nodiscard]] auto point_2d<T>::get_x() const { return (*this)[0]; }
template <typename T> auto point_2d<T>::set_x(T x) { (*this)[0] = x; }

template <typename T> [[nodiscard]] auto point_2d<T>::get_y() const { return (*this)[1]; }
template <typename T> auto point_2d<T>::set_y(T y) { (*this)[1] = y; }

}


namespace raffer
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

}

namespace raffer
{

template <typename T> constexpr point_3d<T>::point_3d(T x, T y, T z) : point<T, 3>{{x, y, z}} {}

template <typename T> [[nodiscard]] auto point_3d<T>::get_x() const { return (*this)[0]; }
template <typename T> auto point_3d<T>::set_x(T x) { (*this)[0] = x; }

template <typename T> [[nodiscard]] auto point_3d<T>::get_y() const { return (*this)[1]; }
template <typename T> auto point_3d<T>::set_y(T y) { (*this)[1] = y; }

template <typename T> [[nodiscard]] auto point_3d<T>::get_z() const { return (*this)[2]; }
template <typename T> auto point_3d<T>::set_z(T y) { (*this)[2] = y; }

}

#endif // POINT_HPP
