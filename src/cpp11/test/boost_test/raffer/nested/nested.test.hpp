#if __cplusplus >= 201103L

#ifndef RAFFER_NESTED_NESTED_TEST_HPP
#define RAFFER_NESTED_NESTED_TEST_HPP

#include <raffer/nested/nested.hpp>


#include <vector>

BOOST_AUTO_TEST_CASE(test_raffer_nested_vector)
{
	BOOST_TEST(std::is_same<raffer::nested_t<std::vector, 0, int>, int>::value);
	BOOST_TEST(std::is_same<raffer::nested_t<std::vector, 1, int>, std::vector<int>>::value);
	BOOST_TEST(std::is_same<raffer::nested_t<std::vector, 2, int>, std::vector<std::vector<int>>>::value);
	BOOST_TEST(std::is_same<raffer::nested_t<std::vector, 3, int>, std::vector<std::vector<std::vector<int>>>>::value);
	BOOST_TEST(std::is_same<raffer::nested_t<std::vector, 4, int>, std::vector<std::vector<std::vector<std::vector<int>>>>>::value);
	BOOST_TEST(std::is_same<raffer::nested_t<std::vector, 5, int>, std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>>::value);
}


#endif // RAFFER_NESTED_NESTED_TEST_HPP

#endif // __cplusplus >= 201103L
