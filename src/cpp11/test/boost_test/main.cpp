#define BOOST_TEST_MODULE raffer_cpplib CPP11 test
#include <boost/test/included/unit_test.hpp>

#include <raffer/raffer.hpp>

BOOST_AUTO_TEST_CASE(test_example)
{
	int i = 1;
	BOOST_TEST(i);
	BOOST_TEST(i == 2);
}