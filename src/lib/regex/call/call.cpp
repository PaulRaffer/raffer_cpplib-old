#include "call.hpp"

#include <iostream>
#include "../../system/system.hpp"
#include <windows.h>

namespace raffer
{

template <typename Char>
auto call(
    function_body<Char> const & _this,
    ordered_functions<Char> const & functions,
    basic_smatch<Char> const & arg)
    -> std::basic_string<Char>
{
    try
    {
        return std::get<function_body_ptr<Char>>(_this)(arg);
    }
    catch (std::bad_variant_access const &)
    {
        auto pos_min = int{};
        std::basic_string<Char> ret = std::get<std::basic_string<Char>>(_this);

        for (auto fg = 0u; fg < functions.size(); ++fg)
            while (!is_down(VK_ESCAPE))
            {
                auto match = basic_smatch<Char>{};
                auto func = function<Char>{};

                pos_min = std::numeric_limits<int>::max();
                for (auto const & f : functions.at(fg))
                    if (regex_namespace::regex_search(ret, match,
                        regex_namespace::basic_regex<Char>(f.first),
                        regex_namespace::regex_constants::format_first_only))
                        if (match.position() < pos_min)
                        {
                            func = f;
                            pos_min = match.position();
                        }

                if(pos_min != std::numeric_limits<int>::max())
                {
                    regex_namespace::regex_search(ret, match,
                        regex_namespace::basic_regex<Char>(func.first),
                        regex_namespace::regex_constants::format_first_only);

                    ret = regex_namespace::regex_replace(ret,
                        regex_namespace::basic_regex<Char>(func.first),
                        call(func.second, functions, match),
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

template auto call(
    function_body<char> const & _this,
    ordered_functions<char> const & functions,
    basic_smatch<char> const & arg)
    -> std::basic_string<char>;

template auto call(
    function_body<wchar_t> const & _this,
    ordered_functions<wchar_t> const & functions,
    basic_smatch<wchar_t> const & arg)
    -> std::basic_string<wchar_t>;

}
