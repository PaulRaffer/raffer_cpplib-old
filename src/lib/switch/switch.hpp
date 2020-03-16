#ifndef SWITCH_HPP
#define SWITCH_HPP

#include <initializer_list>
#include <utility>

namespace raffer
{
constexpr auto equ(auto a, auto b);
}

namespace raffer
{
constexpr auto equ(auto a, auto b){ return a == b; }
}



namespace raffer
{

template <typename T, typename Action = void (*)(), bool (*equ)(T const &, T const &) = equ>
constexpr auto switch_(T const & condition, std::initializer_list<std::pair<T const, Action>> const & cases);

}


namespace raffer
{

template <typename T, typename Action, bool (*equ)(T const &, T const &)>
constexpr auto switch_(T const & condition, std::initializer_list<std::pair<T const, Action>> const & cases)
{
    for (auto [value, action] : cases)
        if (equ(condition, value))
            return action();
    return typename std::invoke_result_t<Action>();
}

}

#endif // SWITCH_HPP
