#define BOOST_TEST_MODULE raffer_cpplib CPP11 test
#include <boost/test/included/unit_test.hpp>

#include <raffer/raffer.hpp>

BOOST_AUTO_TEST_CASE(test_raffer_finally)
{
	auto res = 0;
	try
	{
		res = 1;
		auto f = raffer::finally{
		[&res]{
			res = 2;
		}};
		res = 3;
		throw 99;
		res = 4;
	}
	catch (int i) {}
	BOOST_TEST(res == 2);
}