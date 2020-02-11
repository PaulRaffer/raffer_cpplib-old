#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>

template <typename T>
class Color
{
    T red{0}, green{0}, blue{0};

public:
    constexpr Color(T red, T green, T blue);
    constexpr Color(T brightness);

    constexpr auto get_red() const -> T;
    constexpr auto get_green() const -> T;
    constexpr auto get_blue() const -> T;

    friend auto operator+(Color<auto> const & color0, Color<auto> const & color1);

    friend auto operator<<(std::ostream & os, Color<auto> const & color) -> std::ostream &;
};






template <typename T>
constexpr Color<T>::Color(T red, T green, T blue) : red{red}, green{green}, blue{blue} {}

template <typename T>
constexpr Color<T>::Color(T brightness) : red{brightness}, green{brightness}, blue{brightness} {}

template <typename T>
constexpr auto Color<T>::get_red() const -> T { return red; }
template <typename T>
constexpr auto Color<T>::get_green() const -> T { return green; }
template <typename T>
constexpr auto Color<T>::get_blue() const -> T { return blue; }


auto operator+(Color<auto> const & color0, Color<auto> const & color1)
{
    return Color{color0.red + color1.red, color0.green + color1.green, color0.blue + color1.blue};
}

auto operator<<(std::ostream & os, Color<auto> const & color) -> std::ostream &
{
    return os << "(" << color.red << "," << color.green << "," << color.blue << ")";
}


constexpr auto black = Color{0, 0, 0};
//...
constexpr auto white = Color{255, 255, 255};

#endif // COLOR_HPP
