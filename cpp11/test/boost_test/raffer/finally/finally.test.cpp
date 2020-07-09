#if __cplusplus >= 201103L

#include <boost/test/unit_test.hpp>

#include <raffer/finally/finally.hpp>
#include <raffer/finally/macros.hpp>


BOOST_AUTO_TEST_CASE(test_raffer_finally)
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



BOOST_AUTO_TEST_CASE(test_raffer_finally_macro)
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


#endif // __cplusplus >= 201103L
