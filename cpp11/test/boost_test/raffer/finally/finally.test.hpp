#if __cplusplus >= 201103L

#ifndef TEST_BOOST_RAFFER_FINALLY_FINALLY_TEST_HPP
#define TEST_BOOST_RAFFER_FINALLY_FINALLY_TEST_HPP

#include <raffer/finally/finally.hpp>
#include <raffer/finally/macros.hpp>


BOOST_AUTO_TEST_SUITE(test_raffer_finally)

BOOST_AUTO_TEST_CASE(test_raffer_finally_1)
{
	auto test = 0;
	try
	{
		test = 1;
		auto f = raffer::finally{
		[&test]{
			test = 2;
		}};
		test = 3;
		throw 99;
		test = 4;
	}
	catch (int i) {}
	BOOST_TEST(test == 2);
}


BOOST_AUTO_TEST_CASE(test_raffer_finally_macro_1)
{
	auto test = 0;
	try
	{
		test = 1;
		raffer::FINALLY
			test = 2;
		END
		test = 3;
		throw 99;
		test = 4;
	}
	catch (int i) {}
	BOOST_TEST(test == 2);
}

BOOST_AUTO_TEST_SUITE_END()


#endif // TEST_BOOST_RAFFER_FINALLY_FINALLY_TEST_HPP

#endif // __cplusplus >= 201103L
