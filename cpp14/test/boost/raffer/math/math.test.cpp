
// Copyright (c) 2020 Paul Raffer.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#if __cplusplus >= 201402L

#include <boost/test/unit_test.hpp>

#include <raffer/math/math.hpp>


BOOST_AUTO_TEST_SUITE(test_raffer_math)

BOOST_AUTO_TEST_SUITE(odd_even)

BOOST_AUTO_TEST_CASE(is_odd)
{
	BOOST_TEST(raffer::is_odd(-5));
	BOOST_TEST(raffer::is_odd(-3));
	BOOST_TEST(raffer::is_odd(-1));
	BOOST_TEST(raffer::is_odd(1));
	BOOST_TEST(raffer::is_odd(3));
	BOOST_TEST(raffer::is_odd(5));
}

BOOST_AUTO_TEST_CASE(is_even)
{
	BOOST_TEST(raffer::is_even(-6));
	BOOST_TEST(raffer::is_even(-4));
	BOOST_TEST(raffer::is_even(-2));
	BOOST_TEST(raffer::is_even(0));
	BOOST_TEST(raffer::is_even(2));
	BOOST_TEST(raffer::is_even(4));
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(prime)

BOOST_AUTO_TEST_CASE(is_prime)
{
	BOOST_TEST(raffer::is_prime(2));
	BOOST_TEST(raffer::is_prime(3));
	BOOST_TEST(raffer::is_prime(5));
	BOOST_TEST(raffer::is_prime(7));
	BOOST_TEST(raffer::is_prime(11));
	BOOST_TEST(raffer::is_prime(13));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


#endif // __cplusplus >= 201402L
