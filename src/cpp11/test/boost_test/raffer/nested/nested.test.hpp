#if __cplusplus >= 201103L

#ifndef RAFFER_NESTED_NESTED_TEST_HPP
#define RAFFER_NESTED_NESTED_TEST_HPP

#include <raffer/nested/nested.hpp>


#include <vector>

BOOST_AUTO_TEST_CASE(test_raffer_nested_vector)
{
	BOOST_TEST(std::is_same<raffer::nested_t<std::vector, 0, int>, int>::value);
	BOOST_TEST(std::is_same<raffer::nested_t<std::vector, 1, std::vector<int>>, int>::value);
	BOOST_TEST(std::is_same<raffer::nested_t<std::vector, 2, std::vector<std::vector<int>>>, int>::value);
	BOOST_TEST(std::is_same<raffer::nested_t<std::vector, 3, std::vector<std::vector<std::vector<int>>>>, int>::value);
	BOOST_TEST(std::is_same<raffer::nested_t<std::vector, 4, std::vector<std::vector<std::vector<std::vector<int>>>>>, int>::value);
	BOOST_TEST(std::is_same<raffer::nested_t<std::vector, 5, std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>>, int>::value);
}


#endif // RAFFER_NESTED_NESTED_TEST_HPP

#endif // __cplusplus >= 201103L
