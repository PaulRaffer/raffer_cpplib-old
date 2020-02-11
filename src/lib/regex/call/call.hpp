#ifndef CALL_HPP
#define CALL_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <variant>
#include <unordered_map>


//#include <regex>
//namespace regex_namespace = std;
// or for boost:
#include <boost/regex.hpp>
namespace regex_namespace = boost;


template <typename Char>
using Basic_smatch =
    regex_namespace::match_results<
        typename std::basic_string<
            Char>::const_iterator>;


template <typename Char = char>
using Function_body_ptr =
    std::function<
        auto (
            Basic_smatch<Char> const &)
            -> std::basic_string<Char>>;

template <typename Char = char>
using Function_body =
    std::variant<
        std::basic_string<Char>,
        Function_body_ptr<Char>>;

template <typename Char = char>
using Function =
    std::pair<
        std::basic_string<Char>,
        Function_body<Char>>;

template <typename Char = char>
using Unordered_functions =
    std::unordered_map<
        std::basic_string<Char>,
        Function_body<Char>>;

template <typename Char = char>
using Ordered_functions =
    std::vector<
        Unordered_functions<Char>>;


template <typename Char = char>
auto call(
    Function_body<Char> const & _this,
    Ordered_functions<Char> const & functions,
    Basic_smatch<Char> const & arg)
    -> std::basic_string<Char>;

#endif // CALL_HPP
