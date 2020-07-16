
// Copyright (c) 2020 Paul Raffer.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#if __cplusplus >= 201103L

#include <boost/test/unit_test.hpp>

#include <raffer/lang/cpp/cpp.hpp>


BOOST_AUTO_TEST_SUITE(test_raffer_lang_cpp)

BOOST_AUTO_TEST_CASE(test_raffer_lang_cpp_version_1)
{
	BOOST_TEST(static_cast<long>(raffer::lang::cpp::version::cpp20) == 202002L);
	BOOST_TEST(static_cast<long>(raffer::lang::cpp::version::cpp17) == 201703L);
	BOOST_TEST(static_cast<long>(raffer::lang::cpp::version::cpp14) == 201402L);
	BOOST_TEST(static_cast<long>(raffer::lang::cpp::version::cpp11) == 201103L);
	BOOST_TEST(static_cast<long>(raffer::lang::cpp::version::cpp98) == 199711L);
}

BOOST_AUTO_TEST_SUITE_END()


#endif // __cplusplus >= 201103L
