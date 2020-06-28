#if __cplusplus >= 202002L

#ifndef RAFFER_POINT_POINT_HPP
#define RAFFER_POINT_POINT_HPP


#include <cstddef>
#include <array>


namespace raffer // interface
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
[[nodiscard]] auto operator+(point<auto, dimensions> const & lhs, point<auto, dimensions> const & rhs);

} // namespace raffer





namespace raffer // implementaion
{

template <typename T, std::size_t D>
constexpr point<T, D>::point()
: values{} {}

template <typename T, std::size_t D>
constexpr point<T, D>::point(std::array<T, D> const & rhs)
: values{rhs} {}


template <typename T, std::size_t dimensions>
auto point<T, dimensions>::operator[](int dimension) const
{ return values[dimension]; }

template <typename T, std::size_t dimensions>
auto& point<T, dimensions>::operator[](int dimension)
{ return values[dimension]; }

} // namespace raffer


#endif // RAFFER_POINT_POINT_HPP

#endif // __cplusplus >= 202002L
