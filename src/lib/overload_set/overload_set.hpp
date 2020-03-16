#ifndef OVERLOAD_SET_HPP
#define OVERLOAD_SET_HPP

namespace raffer
{

template <typename... F> struct overload_set : public F... { using F::operator()...; };
template <typename... F> overload_set(F&&...) -> overload_set<F...>;

}

#endif // OVERLOAD_SET_HPP
