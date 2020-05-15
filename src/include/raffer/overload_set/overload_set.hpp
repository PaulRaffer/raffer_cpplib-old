#ifndef RAFFER_OVERLOAD_SET_OVERLOAD_SET_HPP
#define RAFFER_OVERLOAD_SET_OVERLOAD_SET_HPP

namespace raffer // interface
{

template <typename... F> struct overload_set : public F... { using F::operator()...; };
template <typename... F> overload_set(F&&...) -> overload_set<F...>;

}

#endif // RAFFER_OVERLOAD_SET_OVERLOAD_SET_HPP
