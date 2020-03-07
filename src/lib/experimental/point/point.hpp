#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

namespace raffer
{

template <typename T, std::size_t N>
class Point;




template <typename T>
class Point<T, 1>
{
    T x;

public:
    constexpr Point(T x = 0);

    constexpr auto get_x() const;
    void set_x(T x);
};

template <typename T> constexpr Point<T, 1>::Point(T x) : x{x} {}

template <typename T> constexpr auto Point<T, 1>::get_x() const { return x; }
template <typename T> void Point<T, 1>::set_x(T x) { this->x = x; }




template <typename T>
class Point<T, 2> : public Point<T, 1>
{
    T y;

public:
    constexpr Point(T x = 0, T y = 0);

    constexpr auto get_y() const;
    void set_y(T y);
};

template <typename T> constexpr Point<T, 2>::Point(T x, T y) : Point<T, 1>{x}, y{y} {}

template <typename T> constexpr auto Point<T, 2>::get_y() const { return y; }
template <typename T> void Point<T, 2>::set_y(T y) { this->y = y; }

};


namespace raffer
{
template <typename T> using Point_2D = Point<T, 2>;
template <typename T> using Point_3D = Point<T, 3>;
};

#endif // POINT_HPP
