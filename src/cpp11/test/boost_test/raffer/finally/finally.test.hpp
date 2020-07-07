#if __cplusplus >= 201103L

#ifndef RAFFER_FINALLY_FINALLY_TEST_HPP
#define RAFFER_FINALLY_FINALLY_TEST_HPP

#include <raffer/finally/finally.hpp>
#include <raffer/finally/macros.hpp>


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



BOOST_AUTO_TEST_CASE(test_raffer_finally_macro)
{
	auto res = 0;
	try
	{
		res = 1;
		raffer::FINALLY
			res = 2;
		END
		res = 3;
		throw 99;
		res = 4;
	}
	catch (int i) {}
	BOOST_TEST(res == 2);
}


#endif // RAFFER_FINALLY_FINALLY_TEST_HPP

#endif // __cplusplus >= 201103L
