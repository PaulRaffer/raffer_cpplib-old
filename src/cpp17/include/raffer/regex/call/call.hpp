#ifndef RAFFER_REGEX_CALL_CALL_HPP
#define RAFFER_REGEX_CALL_CALL_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <variant>
#include <unordered_map>


//#include <regex>
//namespace regex_namespace = std;
// for boost:
#include <boost/regex.hpp>
namespace regex_namespace = boost;

namespace raffer
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



template <typename Regex>
auto call(
    function_body<typename Regex::value_type> const & _this,
    ordered_functions<typename Regex::value_type> const & functions,
    regex_namespace::match_results<typename std::basic_string<typename Regex::value_type>::const_iterator> const & arg)
    -> std::basic_string<typename Regex::value_type>;


}

#endif // RAFFER_REGEX_CALL_CALL_HPP
