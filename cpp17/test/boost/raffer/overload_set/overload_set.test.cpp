#if __cplusplus >= 201702L

#include <boost/test/unit_test.hpp>

#include <raffer/overload_set/overload_set.hpp>


BOOST_AUTO_TEST_SUITE(test_raffer_overload_set)

auto d(double) { return 'd'; }

struct c { auto operator()(char) { return 'c'; } };

BOOST_AUTO_TEST_CASE(overload_set)
{
    auto functions = raffer::overload_set
    {
        [](int) { return 'i'; },
		std::function{d},
		std::function{c{}},
    };
	
	BOOST_TEST((functions(7) == 'i'));
	BOOST_TEST((functions(7.0) == 'd'));
	BOOST_TEST((functions('7') == 'c'));
}

BOOST_AUTO_TEST_SUITE_END()


#endif // __cplusplus >= 201702L
