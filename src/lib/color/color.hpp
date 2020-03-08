#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>

namespace raffer
{

template <typename T>
class Color
{
    T red, green, blue;

public:
    constexpr Color(T red, T green, T blue);
    constexpr Color(T brightness = 0);
    template <typename T1> constexpr Color(Color<T1> const & color);


    [[nodiscard]] constexpr auto get_red() const;
    void set_red(T red);

    [[nodiscard]] constexpr auto get_green() const;
    void set_green(T green);

    [[nodiscard]] constexpr auto get_blue() const;
    void set_blue(T blue);
};

[[nodiscard]] constexpr auto operator+(Color<auto> const & lhs, Color<auto> const & rhs) -> auto const;
[[nodiscard]] constexpr auto operator+(Color<auto> const & lhs, auto rhs) -> auto const;
[[nodiscard]] constexpr auto operator+(auto lhs, Color<auto> const & rhs) -> auto const;
auto operator+=(Color<auto> & lhs, auto rhs) -> auto &;
auto operator++(Color<auto> & lhs) -> auto &;
auto operator++(Color<auto> & lhs, int) -> auto const;

[[nodiscard]] constexpr auto operator-(Color<auto> const & lhs, Color<auto> const & rhs) -> auto const;
[[nodiscard]] constexpr auto operator-(Color<auto> const & lhs, auto rhs) -> auto const;
[[nodiscard]] constexpr auto operator-(auto lhs, Color<auto> const & rhs) -> auto const;
auto operator-=(Color<auto> & lhs, auto rhs) -> auto &;
auto operator--(Color<auto> & lhs) -> auto &;
auto operator--(Color<auto> & lhs, int) -> auto const;

[[nodiscard]] constexpr auto operator*(Color<auto> const & lhs, Color<auto> const & rhs) -> auto const;
[[nodiscard]] constexpr auto operator*(Color<auto> const & lhs, auto rhs) -> auto const;
[[nodiscard]] constexpr auto operator*(auto lhs, Color<auto> const & rhs) -> auto const;
auto operator*=(Color<auto> & lhs, auto rhs) -> auto &;

[[nodiscard]] constexpr auto operator/(Color<auto> const & lhs, Color<auto> const & rhs) -> auto const;
[[nodiscard]] constexpr auto operator/(Color<auto> const & lhs, auto rhs) -> auto const;
[[nodiscard]] constexpr auto operator/(auto lhs, Color<auto> const & rhs) -> auto const;
auto operator/=(Color<auto> & lhs, auto rhs) -> auto &;


[[nodiscard]] constexpr auto operator==(Color<auto> const & lhs, Color<auto> const & rhs);
[[nodiscard]] constexpr auto operator==(Color<auto> const & lhs, auto rhs);
[[nodiscard]] constexpr auto operator==(auto lhs, Color<auto> const & rhs);

[[nodiscard]] constexpr auto operator!=(Color<auto> const & lhs, Color<auto> const & rhs);
[[nodiscard]] constexpr auto operator!=(Color<auto> const & lhs, auto rhs);
[[nodiscard]] constexpr auto operator!=(auto lhs, Color<auto> const & rhs);


auto operator>>(std::istream& is, Color<auto> & color) -> auto &;
auto operator<<(std::ostream & os, Color<auto> const & color) -> auto &;

};

namespace raffer
{

template <typename T> constexpr Color<T>::Color(T red, T green, T blue) : red{red}, green{green}, blue{blue} {}
template <typename T> constexpr Color<T>::Color(T brightness) : red{brightness}, green{brightness}, blue{brightness} {}
template <typename T> template <typename T1> constexpr Color<T>::Color(Color<T1> const & color) : red(color.get_red()), green(color.get_green()), blue(color.get_blue()) {}


template <typename T> constexpr auto Color<T>::get_red() const { return red; }
template <typename T> void Color<T>::set_red(T red) { this->red = red; }

template <typename T> constexpr auto Color<T>::get_green() const { return green; }
template <typename T> void Color<T>::set_green(T green) { this->green = green; }

template <typename T> constexpr auto Color<T>::get_blue() const { return blue; }
template <typename T> void Color<T>::set_blue(T blue) { this->blue = blue; }


constexpr auto operator+(Color<auto> const & lhs, Color<auto> const & rhs) -> auto const { return Color{lhs.get_red() + rhs.get_red(), lhs.get_green() + rhs.get_green(), lhs.get_blue() + rhs.get_blue()}; }
constexpr auto operator+(Color<auto> const & lhs, auto rhs) -> auto const { return lhs + Color{rhs}; }
constexpr auto operator+(auto lhs, Color<auto> const & rhs) -> auto const { return Color{lhs} + rhs; }
auto operator+=(Color<auto> & lhs, auto rhs) -> auto & { return lhs = lhs + Color{rhs}; }
auto operator++(Color<auto> & lhs) -> auto & { return lhs += 1; }
auto operator++(Color<auto> & lhs, int) -> auto const { auto temp = lhs; lhs += 1; return temp; }

constexpr auto operator-(Color<auto> const & lhs, Color<auto> const & rhs) -> auto const { return Color{lhs.get_red() - rhs.get_red(), lhs.get_green() - rhs.get_green(), lhs.get_blue() - rhs.get_blue()}; }
constexpr auto operator-(Color<auto> const & lhs, auto rhs) -> auto const { return lhs - Color{rhs}; }
constexpr auto operator-(auto lhs, Color<auto> const & rhs) -> auto const { return Color{lhs} - rhs; }
auto operator-=(Color<auto> & lhs, auto rhs) -> auto & { return lhs = lhs - Color{rhs}; }
auto operator--(Color<auto> & lhs) -> auto & { return lhs -= 1; }
auto operator--(Color<auto> & lhs, int) -> auto const { auto temp = lhs; lhs -= 1; return temp; }

constexpr auto operator*(Color<auto> const & lhs, Color<auto> const & rhs) -> auto const { return Color{lhs.get_red() * rhs.get_red(), lhs.get_green() * rhs.get_green(), lhs.get_blue() * rhs.get_blue()}; }
constexpr auto operator*(Color<auto> const & lhs, auto rhs) -> auto const { return lhs * Color{rhs}; }
constexpr auto operator*(auto lhs, Color<auto> const & rhs) -> auto const { return Color{lhs} * rhs; }
auto operator*=(Color<auto> & lhs, auto rhs) -> auto & { return lhs = lhs * Color{rhs}; }

constexpr auto operator/(Color<auto> const & lhs, Color<auto> const & rhs) -> auto const { return Color{lhs.get_red() / rhs.get_red(), lhs.get_green() / rhs.get_green(), lhs.get_blue() / rhs.get_blue()}; }
constexpr auto operator/(Color<auto> const & lhs, auto rhs) -> auto const { return lhs / Color{rhs}; }
constexpr auto operator/(auto lhs, Color<auto> const & rhs) -> auto const { return Color{lhs} / rhs; }
auto operator/=(Color<auto> & lhs, auto rhs) -> auto & { return lhs = lhs / Color{rhs}; }


constexpr auto operator==(Color<auto> const & lhs, Color<auto> const & rhs) { return lhs.get_red() == rhs.get_red() && lhs.get_green() == rhs.get_green() && lhs.get_blue() == rhs.get_blue(); }
constexpr auto operator==(Color<auto> const & lhs, auto rhs) { return lhs == Color{rhs}; }
constexpr auto operator==(auto lhs, Color<auto> const & rhs) { return Color{lhs} == rhs; }

constexpr auto operator!=(Color<auto> const & lhs, Color<auto> const & rhs) { return !(lhs == rhs); }
constexpr auto operator!=(Color<auto> const & lhs, auto rhs) { return lhs != Color{rhs}; }
constexpr auto operator!=(auto lhs, Color<auto> const & rhs) { return Color{lhs} != rhs; }


auto operator<<(std::ostream & os, Color<auto> const & color) -> auto & { return os << "(" << color.get_red() << "," << color.get_green() << "," << color.get_blue() << ")"; }

};

namespace raffer
{

// CSS Level 1
constexpr auto black                = Color{0x00};
constexpr auto silver               = Color{0xC0};
constexpr auto gray                 = Color{0x80};
constexpr auto white                = Color{0xFF};
constexpr auto maroon               = Color{0x80, 0x00, 0x00};
constexpr auto red                  = Color{0xFF, 0x00, 0x00};
constexpr auto purple               = Color{0x80, 0x00, 0x80};
constexpr auto fuchsia              = Color{0xFF, 0x00, 0xFF};
constexpr auto green                = Color{0x00, 0x80, 0x00};
constexpr auto lime                 = Color{0x00, 0xFF, 0x00};
constexpr auto olive                = Color{0x80, 0x80, 0x00};
constexpr auto yellow               = Color{0xFF, 0xFF, 0x00};
constexpr auto navy                 = Color{0x00, 0x00, 0x80};
constexpr auto blue                 = Color{0x00, 0x00, 0xFF};
constexpr auto teal                 = Color{0x00, 0x80, 0x80};
constexpr auto aqua                 = Color{0x00, 0xFF, 0xFF};

// CSS Level 2 (Revision 1)
constexpr auto orange               = Color{0xff, 0xA5, 0x00};

// CSS Color Module Level 3
constexpr auto aliceblue            = Color{0xF0, 0xF8, 0xFF};
constexpr auto antiquewhite         = Color{0xFA, 0xEB, 0xD7};
constexpr auto aquamarine           = Color{0x7F, 0xFF, 0xD4};
constexpr auto azure                = Color{0xF0, 0xFF, 0xFF};
constexpr auto beige                = Color{0xF5, 0xF5, 0xDC};
constexpr auto bisque               = Color{0xFF, 0xE4, 0xC4};
constexpr auto blanchedalmond       = Color{0xFF, 0xEB, 0xCD};
constexpr auto blueviolet           = Color{0x8A, 0x2B, 0xE2};
constexpr auto brown                = Color{0xA5, 0x2A, 0x2A};
constexpr auto burlywood            = Color{0xDE, 0xB8, 0x87};
constexpr auto cadetblue            = Color{0x5F, 0x9E, 0xA0};
constexpr auto chartreuse           = Color{0x7F, 0xFF, 0x00};
constexpr auto chocolate            = Color{0xD2, 0x69, 0x1E};
constexpr auto coral                = Color{0xFF, 0x7F, 0x50};
constexpr auto cornflowerblue       = Color{0x64, 0x95, 0xED};
constexpr auto cornsilk             = Color{0xFF, 0xF8, 0xDC};
constexpr auto crimson              = Color{0xDC, 0x14, 0x3C};
constexpr auto cyan                 = aqua;
constexpr auto darkblue             = Color{0x00, 0x00, 0x8B};
constexpr auto darkcyan             = Color{0x00, 0x8B, 0x8B};
constexpr auto darkgoldenrod        = Color{0xB8, 0x86, 0x0B};
constexpr auto darkgray             = Color{0xA9};
constexpr auto darkgreen            = Color{0x00, 0x64, 0x00};
constexpr auto darkgrey             = darkgray;
constexpr auto darkkhaki            = Color{0xBD, 0xB7, 0x6B};
constexpr auto darkmagenta          = Color{0x8B, 0x00, 0x8B};
constexpr auto darkolivegreen       = Color{0x55, 0x6B, 0x2F};
constexpr auto darkorange           = Color{0xFF, 0x8C, 0x00};
constexpr auto darkorchid           = Color{0x99, 0x32, 0xCC};
constexpr auto darkred              = Color{0x8B, 0x00, 0x00};
constexpr auto darksalmon           = Color{0xE9, 0x96, 0x7A};
constexpr auto darkseagreen         = Color{0x8F, 0xBC, 0x8F};
constexpr auto darkslateblue        = Color{0x48, 0x3D, 0x8B};
constexpr auto darkslategray        = Color{0x2F, 0x4F, 0x4F};
constexpr auto darkslategrey        = darkslategray;
constexpr auto darkturquoise        = Color{0x00, 0xCE, 0xD1};
constexpr auto darkviolet           = Color{0x94, 0x00, 0xD3};
constexpr auto deeppink             = Color{0xFF, 0x14, 0x93};
constexpr auto deepskyblue          = Color{0x00, 0xBF, 0xFF};
constexpr auto dimgray              = Color{0x69};
constexpr auto dimgrey              = dimgray;
constexpr auto dodgerblue           = Color{0x1E, 0x90, 0xFF};
constexpr auto firebrick            = Color{0xB2, 0x22, 0x22};
constexpr auto floralwhite          = Color{0xFF, 0xFA, 0xF0};
constexpr auto forestgreen          = Color{0x22, 0x8B, 0x22};
constexpr auto gainsboro            = Color{0xDC};
constexpr auto ghostwhite           = Color{0xF8, 0xF8, 0xFF};
constexpr auto gold                 = Color{0xFF, 0xD7, 0x00};
constexpr auto goldenrod            = Color{0xDA, 0xA5, 0x20};
constexpr auto greenyellow          = Color{0xAD, 0xFF, 0x2F};
constexpr auto grey                 = gray;
constexpr auto honeydew             = Color{0xF0, 0xFF, 0xF0};
constexpr auto hotpink              = Color{0xFF, 0x69, 0xB4};
constexpr auto indianred            = Color{0xCD, 0x5C, 0x5C};
constexpr auto indigo               = Color{0x4B, 0x00, 0x82};
constexpr auto ivory                = Color{0xFF, 0xFF, 0xF0};
constexpr auto khaki                = Color{0xF0, 0xE6, 0x8C};
constexpr auto lavender             = Color{0xE6, 0xE6, 0xFA};
constexpr auto lavenderblush        = Color{0xFF, 0xF0, 0xF5};
constexpr auto lawngreen            = Color{0x7C, 0xFC, 0x00};
constexpr auto lemonchiffon         = Color{0xFF, 0xFA, 0xCD};
constexpr auto lightblue            = Color{0xAD, 0xD8, 0xE6};
constexpr auto lightcoral           = Color{0xF0, 0x80, 0x80};
constexpr auto lightcyan            = Color{0xE0, 0xFF, 0xFF};
constexpr auto lightgoldenrodyellow = Color{0xFA, 0xFA, 0xD2};
constexpr auto lightgray            = Color{0xD3};
constexpr auto lightgreen           = Color{0x90, 0xEE, 0x90};
constexpr auto lightgrey            = lightgray;
constexpr auto lightpink            = Color{0xFF, 0xB6, 0xC1};
constexpr auto lightsalmon          = Color{0xFF, 0xA0, 0x7A};
constexpr auto lightseagreen        = Color{0x20, 0xB2, 0xAA};
constexpr auto lightskyblue         = Color{0x87, 0xCE, 0xFA};
constexpr auto lightslategray       = Color{0x77, 0x88, 0x99};
constexpr auto lightslategrey       = lightslategray;
constexpr auto lightsteelblue       = Color{0xB0, 0xC4, 0xDE};
constexpr auto lightyellow          = Color{0xFF, 0xFF, 0xE0};
constexpr auto limegreen            = Color{0x32, 0xCD, 0x32};
constexpr auto linen                = Color{0xFA, 0xF0, 0xE6};
constexpr auto magenta              = fuchsia;
constexpr auto mediumaquamarine     = Color{0x66, 0xCD, 0xAA};
constexpr auto mediumblue           = Color{0x00, 0x00, 0xCD};
constexpr auto mediumorchid         = Color{0xBA, 0x55, 0xD3};
constexpr auto mediumpurple         = Color{0x93, 0x70, 0xDB};
constexpr auto mediumseagreen       = Color{0x3C, 0xB3, 0x71};
constexpr auto mediumslateblue      = Color{0x7B, 0x68, 0xEE};
constexpr auto mediumspringgreen    = Color{0x00, 0xFA, 0x9A};
constexpr auto mediumturquoise      = Color{0x48, 0xD1, 0xCC};
constexpr auto mediumvioletred      = Color{0xC7, 0x15, 0x85};
constexpr auto midnightblue         = Color{0x19, 0x19, 0x70};
constexpr auto mintcream            = Color{0xF5, 0xFF, 0xFA};
constexpr auto mistyrose            = Color{0xFF, 0xE4, 0xE1};
constexpr auto moccasin             = Color{0xFF, 0xE4, 0xB5};
constexpr auto navajowhite          = Color{0xFF, 0xDE, 0xAD};
constexpr auto oldlace              = Color{0xFD, 0xF5, 0xE6};
constexpr auto olivedrab            = Color{0x6B, 0x8E, 0x23};
constexpr auto orangered            = Color{0xFF, 0x45, 0x00};
constexpr auto orchid               = Color{0xDA, 0x70, 0xD6};
constexpr auto palegoldenrod        = Color{0xEE, 0xE8, 0xAA};
constexpr auto palegreen            = Color{0x98, 0xFB, 0x98};
constexpr auto paleturquoise        = Color{0xAF, 0xEE, 0xEE};
constexpr auto palevioletred        = Color{0xDB, 0x70, 0x93};
constexpr auto papayawhip           = Color{0xFF, 0xEF, 0xD5};
constexpr auto peachpuff            = Color{0xFF, 0xDA, 0xB9};
constexpr auto peru                 = Color{0xCD, 0x85, 0x3F};
constexpr auto pink                 = Color{0xFF, 0xC0, 0xCB};
constexpr auto plum                 = Color{0xDD, 0xA0, 0xDD};
constexpr auto powderblue           = Color{0xB0, 0xE0, 0xE6};
constexpr auto rosybrown            = Color{0xBC, 0x8F, 0x8F};
constexpr auto royalblue            = Color{0x41, 0x69, 0xE1};
constexpr auto saddlebrown          = Color{0x8B, 0x45, 0x13};
constexpr auto salmon               = Color{0xFA, 0x80, 0x72};
constexpr auto sandybrown           = Color{0xF4, 0xA4, 0x60};
constexpr auto seagreen             = Color{0x2E, 0x8B, 0x57};
constexpr auto seashell             = Color{0xFF, 0xF5, 0xEE};
constexpr auto sienna               = Color{0xA0, 0x52, 0x2D};
constexpr auto skyblue              = Color{0x87, 0xCE, 0xEB};
constexpr auto slateblue            = Color{0x6A, 0x5A, 0xCD};
constexpr auto slategray            = Color{0x70, 0x80, 0x90};
constexpr auto slategrey            = slategray;
constexpr auto snow                 = Color{0xFF, 0xFA, 0xFA};
constexpr auto springgreen          = Color{0x00, 0xFF, 0x7F};
constexpr auto steelblue            = Color{0x46, 0x82, 0xB4};
constexpr auto tan                  = Color{0xD2, 0xB4, 0x8C};
constexpr auto thistle              = Color{0xD8, 0xBF, 0xD8};
constexpr auto tomato               = Color{0xFF, 0x63, 0x47};
constexpr auto turquoise            = Color{0x40, 0xE0, 0xD0};
constexpr auto violet               = Color{0xEE, 0x82, 0xEE};
constexpr auto wheat                = Color{0xF5, 0xDE, 0xB3};
constexpr auto whitesmoke           = Color{0xF5};
constexpr auto yellowgreen          = Color{0x9A, 0xCD, 0x32};

// CSS Color Module Level 4
constexpr auto rebeccapurple        = Color{0x66, 0x33, 0x99};

};

#endif // COLOR_HPP
