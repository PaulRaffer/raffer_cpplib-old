
// Copyright (c) 2020 Paul Raffer.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#if __cplusplus >= 202002L

#ifndef RAFFER_COLOR_COLOR_HPP
#define RAFFER_COLOR_COLOR_HPP


#include <iostream>


namespace raffer // interface
{

template <typename T>
class color
{
	T red, green, blue;

public:
	constexpr color(T red, T green, T blue);
	constexpr color(T brightness = T{});
	template <typename T1> constexpr color(color<T1> const & rhs);
	
	
	[[nodiscard]] constexpr auto get_red() const;
	void set_red(T red);
	
	[[nodiscard]] constexpr auto get_green() const;
	void set_green(T green);
	
	[[nodiscard]] constexpr auto get_blue() const;
	void set_blue(T blue);
};

[[nodiscard]] constexpr auto operator+(color<auto> const & lhs, color<auto> const & rhs) -> auto const;
[[nodiscard]] constexpr auto operator+(color<auto> const & lhs, auto rhs) -> auto const;
[[nodiscard]] constexpr auto operator+(auto lhs, color<auto> const & rhs) -> auto const;
auto operator+=(color<auto> & lhs, auto rhs) -> auto &;
auto operator++(color<auto> & lhs) -> auto &;
auto operator++(color<auto> & lhs, int) -> auto const;

[[nodiscard]] constexpr auto operator-(color<auto> const & lhs, color<auto> const & rhs) -> auto const;
[[nodiscard]] constexpr auto operator-(color<auto> const & lhs, auto rhs) -> auto const;
[[nodiscard]] constexpr auto operator-(auto lhs, color<auto> const & rhs) -> auto const;
auto operator-=(color<auto> & lhs, auto rhs) -> auto &;
auto operator--(color<auto> & lhs) -> auto &;
auto operator--(color<auto> & lhs, int) -> auto const;

[[nodiscard]] constexpr auto operator*(color<auto> const & lhs, color<auto> const & rhs) -> auto const;
[[nodiscard]] constexpr auto operator*(color<auto> const & lhs, auto rhs) -> auto const;
[[nodiscard]] constexpr auto operator*(auto lhs, color<auto> const & rhs) -> auto const;
auto operator*=(color<auto> & lhs, auto rhs) -> auto &;

[[nodiscard]] constexpr auto operator/(color<auto> const & lhs, color<auto> const & rhs) -> auto const;
[[nodiscard]] constexpr auto operator/(color<auto> const & lhs, auto rhs) -> auto const;
[[nodiscard]] constexpr auto operator/(auto lhs, color<auto> const & rhs) -> auto const;
auto operator/=(color<auto> & lhs, auto rhs) -> auto &;


[[nodiscard]] constexpr auto operator==(color<auto> const & lhs, color<auto> const & rhs);
[[nodiscard]] constexpr auto operator==(color<auto> const & lhs, auto rhs);
[[nodiscard]] constexpr auto operator==(auto lhs, color<auto> const & rhs);

[[nodiscard]] constexpr auto operator!=(color<auto> const & lhs, color<auto> const & rhs);
[[nodiscard]] constexpr auto operator!=(color<auto> const & lhs, auto rhs);
[[nodiscard]] constexpr auto operator!=(auto lhs, color<auto> const & rhs);


auto operator>>(std::istream & is, color<auto> & rhs) -> auto &;
auto operator<<(std::ostream & os, color<auto> const & rhs) -> auto &;

} // namespace raffer

#endif // __cplusplus >= 202002L




#if __cplusplus >= 202002L

namespace raffer
{

template <typename T> constexpr color<T>::color(T red, T green, T blue)
: red{red}, green{green}, blue{blue} {}

template <typename T> constexpr color<T>::color(T brightness)
: red{brightness}, green{brightness}, blue{brightness} {}

template <typename T> template <typename T1> constexpr color<T>::color(color<T1> const & rhs)
: red(rhs.get_red()), green(rhs.get_green()), blue(rhs.get_blue()) {}




template <typename T> constexpr auto color<T>::get_red() const { return red; }
template <typename T> void color<T>::set_red(T red) { this->red = red; }

template <typename T> constexpr auto color<T>::get_green() const { return green; }
template <typename T> void color<T>::set_green(T green) { this->green = green; }

template <typename T> constexpr auto color<T>::get_blue() const { return blue; }
template <typename T> void color<T>::set_blue(T blue) { this->blue = blue; }




constexpr auto operator+(color<auto> const & lhs, color<auto> const & rhs) -> auto const
{ return color{lhs.get_red() + rhs.get_red(), lhs.get_green() + rhs.get_green(), lhs.get_blue() + rhs.get_blue()}; }

constexpr auto operator+(color<auto> const & lhs, auto rhs) -> auto const { return lhs + color{rhs}; }

constexpr auto operator+(auto lhs, color<auto> const & rhs) -> auto const { return color{lhs} + rhs; }

auto operator+=(color<auto> & lhs, auto rhs) -> auto & { return lhs = lhs + color{rhs}; }

auto operator++(color<auto> & lhs) -> auto & { return lhs += 1; }

auto operator++(color<auto> & lhs, int) -> auto const { auto temp = lhs; lhs += 1; return temp; }


constexpr auto operator-(color<auto> const & lhs, color<auto> const & rhs) -> auto const
{ return color{lhs.get_red() - rhs.get_red(), lhs.get_green() - rhs.get_green(), lhs.get_blue() - rhs.get_blue()}; }

constexpr auto operator-(color<auto> const & lhs, auto rhs) -> auto const { return lhs - color{rhs}; }

constexpr auto operator-(auto lhs, color<auto> const & rhs) -> auto const { return color{lhs} - rhs; }

auto operator-=(color<auto> & lhs, auto rhs) -> auto & { return lhs = lhs - color{rhs}; }

auto operator--(color<auto> & lhs) -> auto & { return lhs -= 1; }

auto operator--(color<auto> & lhs, int) -> auto const { auto temp = lhs; lhs -= 1; return temp; }


constexpr auto operator*(color<auto> const & lhs, color<auto> const & rhs) -> auto const
{ return color{lhs.get_red() * rhs.get_red(), lhs.get_green() * rhs.get_green(), lhs.get_blue() * rhs.get_blue()}; }

constexpr auto operator*(color<auto> const & lhs, auto rhs) -> auto const { return lhs * color{rhs}; }

constexpr auto operator*(auto lhs, color<auto> const & rhs) -> auto const { return color{lhs} * rhs; }

auto operator*=(color<auto> & lhs, auto rhs) -> auto & { return lhs = lhs * color{rhs}; }


constexpr auto operator/(color<auto> const & lhs, color<auto> const & rhs) -> auto const
{ return color{lhs.get_red() / rhs.get_red(), lhs.get_green() / rhs.get_green(), lhs.get_blue() / rhs.get_blue()}; }

constexpr auto operator/(color<auto> const & lhs, auto rhs) -> auto const { return lhs / color{rhs}; }

constexpr auto operator/(auto lhs, color<auto> const & rhs) -> auto const { return color{lhs} / rhs; }

auto operator/=(color<auto> & lhs, auto rhs) -> auto & { return lhs = lhs / color{rhs}; }




constexpr auto operator==(color<auto> const & lhs, color<auto> const & rhs)
{ return lhs.get_red() == rhs.get_red() && lhs.get_green() == rhs.get_green() && lhs.get_blue() == rhs.get_blue(); }

constexpr auto operator==(color<auto> const & lhs, auto rhs) { return lhs == color{rhs}; }

constexpr auto operator==(auto lhs, color<auto> const & rhs) { return color{lhs} == rhs; }


constexpr auto operator!=(color<auto> const & lhs, color<auto> const & rhs) { return !(lhs == rhs); }

constexpr auto operator!=(color<auto> const & lhs, auto rhs) { return lhs != color{rhs}; }

constexpr auto operator!=(auto lhs, color<auto> const & rhs) { return color{lhs} != rhs; }




auto operator<<(std::ostream & os, color<auto> const & rhs) -> auto &
{ return os << "(" << rhs.get_red() << "," << rhs.get_green() << "," << rhs.get_blue() << ")"; }

} // namespace raffer





namespace raffer // constants
{

// CSS Level 1
constexpr auto black				= color{0x00};
constexpr auto silver			   = color{0xC0};
constexpr auto gray				 = color{0x80};
constexpr auto white				= color{0xFF};
constexpr auto maroon			   = color{0x80, 0x00, 0x00};
constexpr auto red				  = color{0xFF, 0x00, 0x00};
constexpr auto purple			   = color{0x80, 0x00, 0x80};
constexpr auto fuchsia			  = color{0xFF, 0x00, 0xFF};
constexpr auto green				= color{0x00, 0x80, 0x00};
constexpr auto lime				 = color{0x00, 0xFF, 0x00};
constexpr auto olive				= color{0x80, 0x80, 0x00};
constexpr auto yellow			   = color{0xFF, 0xFF, 0x00};
constexpr auto navy				 = color{0x00, 0x00, 0x80};
constexpr auto blue				 = color{0x00, 0x00, 0xFF};
constexpr auto teal				 = color{0x00, 0x80, 0x80};
constexpr auto aqua				 = color{0x00, 0xFF, 0xFF};

// CSS Level 2 (Revision 1)
constexpr auto orange			   = color{0xff, 0xA5, 0x00};

// CSS Color Module Level 3
constexpr auto aliceblue			= color{0xF0, 0xF8, 0xFF};
constexpr auto antiquewhite		 = color{0xFA, 0xEB, 0xD7};
constexpr auto aquamarine		   = color{0x7F, 0xFF, 0xD4};
constexpr auto azure				= color{0xF0, 0xFF, 0xFF};
constexpr auto beige				= color{0xF5, 0xF5, 0xDC};
constexpr auto bisque			   = color{0xFF, 0xE4, 0xC4};
constexpr auto blanchedalmond	   = color{0xFF, 0xEB, 0xCD};
constexpr auto blueviolet		   = color{0x8A, 0x2B, 0xE2};
constexpr auto brown				= color{0xA5, 0x2A, 0x2A};
constexpr auto burlywood			= color{0xDE, 0xB8, 0x87};
constexpr auto cadetblue			= color{0x5F, 0x9E, 0xA0};
constexpr auto chartreuse		   = color{0x7F, 0xFF, 0x00};
constexpr auto chocolate			= color{0xD2, 0x69, 0x1E};
constexpr auto coral				= color{0xFF, 0x7F, 0x50};
constexpr auto cornflowerblue	   = color{0x64, 0x95, 0xED};
constexpr auto cornsilk			 = color{0xFF, 0xF8, 0xDC};
constexpr auto crimson			  = color{0xDC, 0x14, 0x3C};
constexpr auto cyan				 = aqua;
constexpr auto darkblue			 = color{0x00, 0x00, 0x8B};
constexpr auto darkcyan			 = color{0x00, 0x8B, 0x8B};
constexpr auto darkgoldenrod		= color{0xB8, 0x86, 0x0B};
constexpr auto darkgray			 = color{0xA9};
constexpr auto darkgreen			= color{0x00, 0x64, 0x00};
constexpr auto darkgrey			 = darkgray;
constexpr auto darkkhaki			= color{0xBD, 0xB7, 0x6B};
constexpr auto darkmagenta		  = color{0x8B, 0x00, 0x8B};
constexpr auto darkolivegreen	   = color{0x55, 0x6B, 0x2F};
constexpr auto darkorange		   = color{0xFF, 0x8C, 0x00};
constexpr auto darkorchid		   = color{0x99, 0x32, 0xCC};
constexpr auto darkred			  = color{0x8B, 0x00, 0x00};
constexpr auto darksalmon		   = color{0xE9, 0x96, 0x7A};
constexpr auto darkseagreen		 = color{0x8F, 0xBC, 0x8F};
constexpr auto darkslateblue		= color{0x48, 0x3D, 0x8B};
constexpr auto darkslategray		= color{0x2F, 0x4F, 0x4F};
constexpr auto darkslategrey		= darkslategray;
constexpr auto darkturquoise		= color{0x00, 0xCE, 0xD1};
constexpr auto darkviolet		   = color{0x94, 0x00, 0xD3};
constexpr auto deeppink			 = color{0xFF, 0x14, 0x93};
constexpr auto deepskyblue		  = color{0x00, 0xBF, 0xFF};
constexpr auto dimgray			  = color{0x69};
constexpr auto dimgrey			  = dimgray;
constexpr auto dodgerblue		   = color{0x1E, 0x90, 0xFF};
constexpr auto firebrick			= color{0xB2, 0x22, 0x22};
constexpr auto floralwhite		  = color{0xFF, 0xFA, 0xF0};
constexpr auto forestgreen		  = color{0x22, 0x8B, 0x22};
constexpr auto gainsboro			= color{0xDC};
constexpr auto ghostwhite		   = color{0xF8, 0xF8, 0xFF};
constexpr auto gold				 = color{0xFF, 0xD7, 0x00};
constexpr auto goldenrod			= color{0xDA, 0xA5, 0x20};
constexpr auto greenyellow		  = color{0xAD, 0xFF, 0x2F};
constexpr auto grey				 = gray;
constexpr auto honeydew			 = color{0xF0, 0xFF, 0xF0};
constexpr auto hotpink			  = color{0xFF, 0x69, 0xB4};
constexpr auto indianred			= color{0xCD, 0x5C, 0x5C};
constexpr auto indigo			   = color{0x4B, 0x00, 0x82};
constexpr auto ivory				= color{0xFF, 0xFF, 0xF0};
constexpr auto khaki				= color{0xF0, 0xE6, 0x8C};
constexpr auto lavender			 = color{0xE6, 0xE6, 0xFA};
constexpr auto lavenderblush		= color{0xFF, 0xF0, 0xF5};
constexpr auto lawngreen			= color{0x7C, 0xFC, 0x00};
constexpr auto lemonchiffon		 = color{0xFF, 0xFA, 0xCD};
constexpr auto lightblue			= color{0xAD, 0xD8, 0xE6};
constexpr auto lightcoral		   = color{0xF0, 0x80, 0x80};
constexpr auto lightcyan			= color{0xE0, 0xFF, 0xFF};
constexpr auto lightgoldenrodyellow = color{0xFA, 0xFA, 0xD2};
constexpr auto lightgray			= color{0xD3};
constexpr auto lightgreen		   = color{0x90, 0xEE, 0x90};
constexpr auto lightgrey			= lightgray;
constexpr auto lightpink			= color{0xFF, 0xB6, 0xC1};
constexpr auto lightsalmon		  = color{0xFF, 0xA0, 0x7A};
constexpr auto lightseagreen		= color{0x20, 0xB2, 0xAA};
constexpr auto lightskyblue		 = color{0x87, 0xCE, 0xFA};
constexpr auto lightslategray	   = color{0x77, 0x88, 0x99};
constexpr auto lightslategrey	   = lightslategray;
constexpr auto lightsteelblue	   = color{0xB0, 0xC4, 0xDE};
constexpr auto lightyellow		  = color{0xFF, 0xFF, 0xE0};
constexpr auto limegreen			= color{0x32, 0xCD, 0x32};
constexpr auto linen				= color{0xFA, 0xF0, 0xE6};
constexpr auto magenta			  = fuchsia;
constexpr auto mediumaquamarine	 = color{0x66, 0xCD, 0xAA};
constexpr auto mediumblue		   = color{0x00, 0x00, 0xCD};
constexpr auto mediumorchid		 = color{0xBA, 0x55, 0xD3};
constexpr auto mediumpurple		 = color{0x93, 0x70, 0xDB};
constexpr auto mediumseagreen	   = color{0x3C, 0xB3, 0x71};
constexpr auto mediumslateblue	  = color{0x7B, 0x68, 0xEE};
constexpr auto mediumspringgreen	= color{0x00, 0xFA, 0x9A};
constexpr auto mediumturquoise	  = color{0x48, 0xD1, 0xCC};
constexpr auto mediumvioletred	  = color{0xC7, 0x15, 0x85};
constexpr auto midnightblue		 = color{0x19, 0x19, 0x70};
constexpr auto mintcream			= color{0xF5, 0xFF, 0xFA};
constexpr auto mistyrose			= color{0xFF, 0xE4, 0xE1};
constexpr auto moccasin			 = color{0xFF, 0xE4, 0xB5};
constexpr auto navajowhite		  = color{0xFF, 0xDE, 0xAD};
constexpr auto oldlace			  = color{0xFD, 0xF5, 0xE6};
constexpr auto olivedrab			= color{0x6B, 0x8E, 0x23};
constexpr auto orangered			= color{0xFF, 0x45, 0x00};
constexpr auto orchid			   = color{0xDA, 0x70, 0xD6};
constexpr auto palegoldenrod		= color{0xEE, 0xE8, 0xAA};
constexpr auto palegreen			= color{0x98, 0xFB, 0x98};
constexpr auto paleturquoise		= color{0xAF, 0xEE, 0xEE};
constexpr auto palevioletred		= color{0xDB, 0x70, 0x93};
constexpr auto papayawhip		   = color{0xFF, 0xEF, 0xD5};
constexpr auto peachpuff			= color{0xFF, 0xDA, 0xB9};
constexpr auto peru				 = color{0xCD, 0x85, 0x3F};
constexpr auto pink				 = color{0xFF, 0xC0, 0xCB};
constexpr auto plum				 = color{0xDD, 0xA0, 0xDD};
constexpr auto powderblue		   = color{0xB0, 0xE0, 0xE6};
constexpr auto rosybrown			= color{0xBC, 0x8F, 0x8F};
constexpr auto royalblue			= color{0x41, 0x69, 0xE1};
constexpr auto saddlebrown		  = color{0x8B, 0x45, 0x13};
constexpr auto salmon			   = color{0xFA, 0x80, 0x72};
constexpr auto sandybrown		   = color{0xF4, 0xA4, 0x60};
constexpr auto seagreen			 = color{0x2E, 0x8B, 0x57};
constexpr auto seashell			 = color{0xFF, 0xF5, 0xEE};
constexpr auto sienna			   = color{0xA0, 0x52, 0x2D};
constexpr auto skyblue			  = color{0x87, 0xCE, 0xEB};
constexpr auto slateblue			= color{0x6A, 0x5A, 0xCD};
constexpr auto slategray			= color{0x70, 0x80, 0x90};
constexpr auto slategrey			= slategray;
constexpr auto snow				 = color{0xFF, 0xFA, 0xFA};
constexpr auto springgreen		  = color{0x00, 0xFF, 0x7F};
constexpr auto steelblue			= color{0x46, 0x82, 0xB4};
constexpr auto tan				  = color{0xD2, 0xB4, 0x8C};
constexpr auto thistle			  = color{0xD8, 0xBF, 0xD8};
constexpr auto tomato			   = color{0xFF, 0x63, 0x47};
constexpr auto turquoise			= color{0x40, 0xE0, 0xD0};
constexpr auto violet			   = color{0xEE, 0x82, 0xEE};
constexpr auto wheat				= color{0xF5, 0xDE, 0xB3};
constexpr auto whitesmoke		   = color{0xF5};
constexpr auto yellowgreen		  = color{0x9A, 0xCD, 0x32};

// CSS color Module Level 4
constexpr auto rebeccapurple		= color{0x66, 0x33, 0x99};

} // namespace raffer


#endif // RAFFER_COLOR_COLOR_HPP

#endif // __cplusplus >= 202002L
