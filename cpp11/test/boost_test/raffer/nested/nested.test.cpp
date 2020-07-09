#if __cplusplus >= 201103L

#include <boost/test/unit_test.hpp>

#include <raffer/nested/nested.hpp>


#include <vector>

BOOST_AUTO_TEST_CASE(test_raffer_nested_vector)
{
	auto test =
		std::is_same<raffer::nested_t<std::vector, 0, int>, int>::value &&
		std::is_same<raffer::nested_t<std::vector, 1, int>, std::vector<int>>::value &&
		std::is_same<raffer::nested_t<std::vector, 2, int>, std::vector<std::vector<int>>>::value &&
		std::is_same<raffer::nested_t<std::vector, 3, int>, std::vector<std::vector<std::vector<int>>>>::value &&
		std::is_same<raffer::nested_t<std::vector, 4, int>, std::vector<std::vector<std::vector<std::vector<int>>>>>::value &&
		std::is_same<raffer::nested_t<std::vector, 5, int>, std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>>::value;
	BOOST_TEST(test);
}


#endif // __cplusplus >= 201103L
