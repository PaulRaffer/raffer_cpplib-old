#if __cplusplus >= 201702L

#include <boost/test/unit_test.hpp>

#include <boost/mpl/list.hpp>
#include <boost/mpl/insert_range.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/remove.hpp>
#include <boost/mpl/size.hpp>

#include <raffer/container/container.hpp>


namespace raffer // interface
{
	
using fundamental_void_types = boost::mpl::list<
	void>;


using fundamental_nullptr_t_types = boost::mpl::list<
	std::nullptr_t>;


using fundamental_boolean_types = boost::mpl::list<
	bool>;


using fundamental_signed_integer_types = boost::mpl::list<
	short,
	int,
	long,
	long long>;
using fundamental_unsigned_integer_types = boost::mpl::list<
	unsigned short,
	unsigned int,
	unsigned long,
	unsigned long long>;
using fundamental_integer_types = boost::mpl::insert_range<
	fundamental_signed_integer_types, boost::mpl::end<fundamental_signed_integer_types>::type,
	fundamental_unsigned_integer_types>::type;


using fundamental_signed_character_types = boost::mpl::list<
	signed char>;
using fundamental_unsigned_character_types = boost::mpl::list<
	unsigned char>;
using fundamental_character_types = boost::mpl::push_front<boost::mpl::insert_range<
	fundamental_signed_character_types, boost::mpl::end<fundamental_signed_character_types>::type,
	fundamental_unsigned_character_types>::type,
	char>::type;


using fundamental_floating_point_types = boost::mpl::list<
	float,
	double,
	long double>;


using fundamental_types = boost::mpl::insert_range<boost::mpl::insert_range<boost::mpl::insert_range<boost::mpl::insert_range<
	fundamental_void_types, boost::mpl::end<fundamental_void_types>::type,
	fundamental_nullptr_t_types>::type, boost::mpl::end<fundamental_nullptr_t_types>::type,
	fundamental_boolean_types>::type, boost::mpl::end<fundamental_boolean_types>::type,
	fundamental_integer_types>::type, boost::mpl::end<fundamental_integer_types>::type,
	fundamental_character_types>::type;
	
using fundamental_types_without_void = boost::mpl::remove<fundamental_types, void>::type;
	
using fundamental_types2 = boost::mpl::list<int>;

} // namespace raffer


class Test {};
template <typename... T> class Test_vector : public std::vector<T...> {};


using test_types = raffer::fundamental_types_without_void;
using test_types_without_bool = boost::mpl::remove<test_types, bool>::type;
using test_types_without_nullptr_t = boost::mpl::remove<test_types, std::nullptr_t>::type;

BOOST_AUTO_TEST_SUITE(test_raffer_container)

BOOST_AUTO_TEST_SUITE(is_container)

BOOST_AUTO_TEST_CASE_TEMPLATE(array, T, test_types)
{
	BOOST_TEST((raffer::is_container_v<std::array<T, 5>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(vector, T, test_types_without_bool)
{
	BOOST_TEST((raffer::is_container_v<std::vector<T>>));
}
BOOST_AUTO_TEST_CASE(vector_bool)
{
	BOOST_TEST((raffer::is_container_v<std::vector<bool>> == false)); // class template specialization
}


BOOST_AUTO_TEST_CASE_TEMPLATE(deque, T, test_types)
{
	BOOST_TEST((raffer::is_container_v<std::deque<T>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(forward_list, T, test_types)
{
	BOOST_TEST((raffer::is_container_v<std::forward_list<T>> == false)); // no size member
}


BOOST_AUTO_TEST_CASE_TEMPLATE(list, T, test_types)
{
	BOOST_TEST((raffer::is_container_v<std::list<T>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(stack, T, test_types)
{
	BOOST_TEST((raffer::is_container_v<std::stack<T>> == false)); // Container adaptor
}


BOOST_AUTO_TEST_CASE_TEMPLATE(queue, T, test_types)
{
	BOOST_TEST((raffer::is_container_v<std::queue<T>> == false)); // Container adaptor
}


BOOST_AUTO_TEST_CASE_TEMPLATE(priority_queue, T, test_types)
{
	BOOST_TEST((raffer::is_container_v<std::priority_queue<T>> == false)); // Container adaptor
}


BOOST_AUTO_TEST_CASE_TEMPLATE(set, T, test_types)
{
	BOOST_TEST((raffer::is_container_v<std::set<T>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(multiset, T, test_types)
{
	BOOST_TEST((raffer::is_container_v<std::multiset<T>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(map, T, test_types)
{
	BOOST_TEST((raffer::is_container_v<std::map<T, int>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(multimap, T, test_types)
{
	BOOST_TEST((raffer::is_container_v<std::multimap<T, int>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(unordered_set, T, test_types_without_nullptr_t)
{
	BOOST_TEST((raffer::is_container_v<std::unordered_set<T>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(unordered_multiset, T, test_types_without_nullptr_t)
{
	BOOST_TEST((raffer::is_container_v<std::unordered_multiset<T>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(unordered_map, T, test_types_without_nullptr_t)
{
	BOOST_TEST((raffer::is_container_v<std::unordered_map<T, int>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(unordered_multimap, T, test_types_without_nullptr_t)
{
	BOOST_TEST((raffer::is_container_v<std::unordered_multimap<T, int>>));
}

BOOST_AUTO_TEST_SUITE_END()




BOOST_AUTO_TEST_SUITE(is_stl_container)

BOOST_AUTO_TEST_CASE_TEMPLATE(array, T, test_types)
{
	BOOST_TEST((raffer::is_stl_container_v<std::array<T, 5>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(vector, T, test_types)
{
	BOOST_TEST((raffer::is_stl_container_v<std::vector<T>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(deque, T, test_types)
{
	BOOST_TEST((raffer::is_stl_container_v<std::deque<T>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(forward_list, T, test_types)
{
	BOOST_TEST((raffer::is_stl_container_v<std::forward_list<T>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(list, T, test_types)
{
	BOOST_TEST((raffer::is_stl_container_v<std::list<T>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(stack, T, test_types)
{
	BOOST_TEST((raffer::is_stl_container_v<std::stack<T>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(queue, T, test_types)
{
	BOOST_TEST((raffer::is_stl_container_v<std::queue<T>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(priority_queue, T, test_types)
{
	BOOST_TEST((raffer::is_stl_container_v<std::priority_queue<T>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(set, T, test_types)
{
	BOOST_TEST((raffer::is_stl_container_v<std::set<T>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(multiset, T, test_types)
{
	BOOST_TEST((raffer::is_stl_container_v<std::multiset<T>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(map, T, test_types)
{
	BOOST_TEST((raffer::is_stl_container_v<std::map<T, int>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(multimap, T, test_types)
{
	BOOST_TEST((raffer::is_stl_container_v<std::multimap<T, int>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(unordered_set, T, test_types_without_nullptr_t)
{
	BOOST_TEST((raffer::is_stl_container_v<std::unordered_set<T>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(unordered_multiset, T, test_types_without_nullptr_t)
{
	BOOST_TEST((raffer::is_stl_container_v<std::unordered_multiset<T>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(unordered_map, T, test_types_without_nullptr_t)
{
	BOOST_TEST((raffer::is_stl_container_v<std::unordered_map<T, int>>));
}


BOOST_AUTO_TEST_CASE_TEMPLATE(unordered_multimap, T, test_types_without_nullptr_t)
{
	BOOST_TEST((raffer::is_stl_container_v<std::unordered_multimap<T, int>>));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


#endif // __cplusplus >= 201702L
