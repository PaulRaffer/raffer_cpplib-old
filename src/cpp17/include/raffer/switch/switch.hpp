#ifndef RAFFER_SWITCH_SWITCH_HPP
#define RAFFER_SWITCH_SWITCH_HPP


#if __cplusplus >= 201703L

#include <initializer_list>
#include <utility>

namespace raffer // interface
{

constexpr auto equ(auto a, auto b);

} // namespace raffer

#endif // __cplusplus >= 201703L




#if __cplusplus >= 201703L

namespace raffer // implementation
{

constexpr auto equ(auto a, auto b){ return a == b; }

} // namespace raffer

#endif // __cplusplus >= 201703L






#if __cplusplus >= 201703L

namespace raffer
{

template <typename F_true, typename F_false = void (*)(), typename... Args>
constexpr auto if_(bool condition, F_true true_case, F_false false_case = []{}, Args&&... args);

template <typename T, typename F = void (*)(), bool (*equ)(T const &, T const &) = equ>
constexpr auto switch_(T const & condition, std::initializer_list<std::pair<T const, F>> const & cases);

} // namespace raffer

#endif // __cplusplus >= 201703L




#if __cplusplus >= 201703L

namespace raffer
{

template <typename F_true, typename F_false, typename... Args>
constexpr auto if_(bool condition, F_true true_case, F_false false_case, Args&&... args)
{ return condition ? true_case(args...) : false_case(args...); }


template <typename T, typename F, bool (*equ)(T const &, T const &)>
constexpr auto switch_(T const & condition, std::initializer_list<std::pair<T const, F>> const & cases)
{
    for (auto [value, action] : cases)
        if (equ(condition, value))
            return action();
    return typename std::invoke_result_t<F>();
}

} // namespace raffer

#endif // __cplusplus >= 201703L


#endif // RAFFER_SWITCH_SWITCH_HPP
