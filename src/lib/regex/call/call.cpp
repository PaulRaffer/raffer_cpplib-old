#include "call.hpp"

namespace raffer
{

template <typename Char = char>
auto call(
    Function_body<Char> const & _this,
    Ordered_functions<Char> const & functions,
    regex_namespace::match_results<typename std::basic_string<Char>::const_iterator> const & arg)
    -> std::basic_string<Char>
{
    try
    {
        return std::get<Function_body_ptr<Char>>(_this)(arg);
    }
    catch (std::bad_variant_access const &)
    {
        Basic_smatch<Char> match;
        Function<Char> func;
        int pos_min;

        auto ret = std::get<std::basic_string<Char>>(_this);
        for (auto fg = 0u; fg < functions.size(); ++fg)
            do
            {
                pos_min = std::numeric_limits<int>::max();
                for (auto const & f : functions.at(fg))
                    if (regex_namespace::regex_search(ret, match, regex_namespace::basic_regex<Char>(f.first), regex_namespace::regex_constants::format_first_only))
                        if (match.position(int{0}) < pos_min)
                        {
                            func = f;
                            pos_min = match.position(int{0});
                        }

                if(pos_min != std::numeric_limits<int>::max())
                {
                    regex_namespace::regex_search(
                        ret, match, regex_namespace::basic_regex<Char>(func.first),
                        regex_namespace::regex_constants::format_first_only);

                    ret = regex_namespace::regex_replace(
                        ret, regex_namespace::basic_regex<Char>(func.first), call(func.second, functions, match),
                        regex_namespace::regex_constants::format_first_only);

                    fg = 0;
                }
            }
            while(pos_min != std::numeric_limits<int>::max());

        return ret;
    }
}

template auto call(
    Function_body<char> const & _this,
    Ordered_functions<char> const & functions,
    Basic_smatch<char> const & arg)
    -> std::basic_string<char>;

template auto call(
    Function_body<wchar_t> const & _this,
    Ordered_functions<wchar_t> const & functions,
    Basic_smatch<wchar_t> const & arg)
    -> std::basic_string<wchar_t>;

};
