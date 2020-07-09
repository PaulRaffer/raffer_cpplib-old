#if __cplusplus >= 201103L

#include <boost/test/unit_test.hpp>

#include <raffer/lang/cpp/cpp.hpp>


BOOST_AUTO_TEST_SUITE(test_raffer_lang_cpp)

BOOST_AUTO_TEST_CASE(test_raffer_lang_cpp_version_1)
{
	auto test = long{};
	
	test = static_cast<long>(raffer::lang::cpp::version::cpp20);
	BOOST_TEST(test == 202002L);
	
	test = static_cast<long>(raffer::lang::cpp::version::cpp17);
	BOOST_TEST(test == 201703L);
	
	test = static_cast<long>(raffer::lang::cpp::version::cpp14);
	BOOST_TEST(test == 201402L);
	
	test = static_cast<long>(raffer::lang::cpp::version::cpp11);
	BOOST_TEST(test == 201103L);
	
	test = static_cast<long>(raffer::lang::cpp::version::cpp98);
	BOOST_TEST(test == 199711L);
}

BOOST_AUTO_TEST_SUITE_END()


#endif // __cplusplus >= 201103L
