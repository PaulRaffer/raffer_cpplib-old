#if __cplusplus >= 201103L

#ifndef RAFFER_LANG_CPP_CPP_TEST_HPP
#define RAFFER_LANG_CPP_CPP_TEST_HPP

#include <raffer/lang/cpp/cpp.hpp>


BOOST_AUTO_TEST_CASE(test_raffer_lang_cpp_version)
{
	BOOST_TEST(raffer::lang::cpp::version::cpp20 == 202002L);
	BOOST_TEST(raffer::lang::cpp::version::cpp17 == 201703L);
	BOOST_TEST(raffer::lang::cpp::version::cpp14 == 201402L);
	BOOST_TEST(raffer::lang::cpp::version::cpp11 == 201103L);
	BOOST_TEST(raffer::lang::cpp::version::cpp98 == 199711L);
}


#endif // RAFFER_LANG_CPP_CPP_TEST_HPP

#endif // __cplusplus >= 201103L
