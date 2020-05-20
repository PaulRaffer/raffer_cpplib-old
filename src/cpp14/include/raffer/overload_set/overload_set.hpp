#ifndef RAFFER_OVERLOAD_SET_OVERLOAD_SET_HPP
#define RAFFER_OVERLOAD_SET_OVERLOAD_SET_HPP


#if __cplusplus >= 201402L

namespace raffer // interface
{

template <typename... F> struct overload_set : public F... { using F::operator()...; };
template <typename... F> overload_set(F&&...) -> overload_set<F...>;

}

#endif // __cplusplus >= 201402L


#endif // RAFFER_OVERLOAD_SET_OVERLOAD_SET_HPP
