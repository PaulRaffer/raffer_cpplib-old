#include "call.hpp"

#include <iostream>
#include "../../system/system.hpp"
#include <windows.h>

namespace raffer
{

template <typename Regex>
auto call(
    function_body<typename Regex::value_type> const & _this,
    ordered_functions<typename Regex::value_type> const & functions,
    regex_namespace::match_results<typename std::basic_string<typename Regex::value_type>::const_iterator> const & arg)
    -> std::basic_string<typename Regex::value_type>
{
    using Char = typename Regex::value_type;

    try { return std::get<function_body_ptr<Char>>(_this)(arg); }
    catch (std::bad_variant_access const &)
    {
        std::basic_string<Char> ret = std::get<std::basic_string<Char>>(_this);

        for (auto fg = 0u; fg < functions.size(); ++fg)
            while (!is_down(VK_ESCAPE))
            {
                auto func = function<Char>{};
                auto next_match = regex_namespace::match_results<typename std::basic_string<Char>::const_iterator>{};
                auto next_match_pos = std::numeric_limits<int>::max();

                for (auto & f : functions.at(fg))
                {
                    auto match = basic_smatch<Char>{};
                    if (regex_search(ret, match,
                        regex_namespace::basic_regex<Char>(f.first),
                        regex_namespace::regex_constants::format_first_only))
                        if (match.position() < next_match_pos)
                        {
                            func = f;
                            next_match = match;
                            next_match_pos = match.position();
                            if (!next_match_pos) break;
                        }
                }

                if(next_match_pos != std::numeric_limits<int>::max())
                {
                    ret = regex_replace(ret,
                        regex_namespace::basic_regex<Char>(func.first),
                        call<regex_namespace::basic_regex<Char>>(func.second, functions, next_match),
                        regex_namespace::regex_constants::format_first_only);

                    fg = 0u;
                    continue;
                }

                break;
            }

        //std::wcout << std::endl << L"<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl << ret << std::endl << L">>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
        return ret;
    }
}
/*
template auto call<std::regex>(
    function_body<char> const & _this,
    ordered_functions<char> const & functions,
    basic_smatch<char> const & arg)
    -> std::basic_string<char>;
*/
/*template auto call<std::wregex>(
    function_body<wchar_t> const & _this,
    ordered_functions<wchar_t> const & functions,
    basic_smatch<wchar_t> const & arg)
    -> std::basic_string<wchar_t>;
*/
/*
template auto call<boost::regex>(
    function_body<char> const & _this,
    ordered_functions<char> const & functions,
    basic_smatch<char> const & arg)
    -> std::basic_string<char>;
*/
template auto call<boost::wregex>(
    function_body<wchar_t> const & _this,
    ordered_functions<wchar_t> const & functions,
    basic_smatch<wchar_t> const & arg)
    -> std::basic_string<wchar_t>;

}
