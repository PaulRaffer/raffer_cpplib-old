#if __cplusplus >= 201703L

#ifndef RAFFER_REGEX_CALL_CALL_HPP
#define RAFFER_REGEX_CALL_CALL_HPP

#define raffer_cpplib_regex_call__ 202006L


#include <iostream>
#include <sstream>
#include <vector>
#include <variant>
#include <unordered_map>


#include <regex>
namespace regex_namespace = std;
// for boost:
//#include <boost/regex.hpp>
//namespace regex_namespace = boost;


namespace raffer // interface
{

template <typename Char>
using basic_smatch =
	regex_namespace::match_results<
		typename std::basic_string<
			Char>::const_iterator>;


template <typename Char = char>
using function_body_ptr =
	std::function<
		auto (
			basic_smatch<Char> const &)
			-> std::basic_string<Char>>;

template <typename Char = char>
using function_body =
	std::variant<
		std::basic_string<Char>,
		function_body_ptr<Char>>;

template <typename Char = char>
using function =
	std::pair<
		std::basic_string<Char>,
		function_body<Char>>;

template <typename Char = char>
using unordered_functions =
	std::unordered_map<
		std::basic_string<Char>,
		function_body<Char>>;

template <typename Char = char>
using ordered_functions =
	std::vector<
		unordered_functions<Char>>;


template <typename Char = char>
auto call(
	function_body<Char> const & this_,
	ordered_functions<Char> const & functions,
	basic_smatch<Char> const & arg)
	-> std::basic_string<Char>;

} // namespace raffer


#endif // RAFFER_REGEX_CALL_CALL_HPP

#endif // __cplusplus >= 201703L
