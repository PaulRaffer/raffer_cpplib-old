#if __cplusplus >= 201702L

#ifndef RAFFER_OVERLOAD_SET_OVERLOAD_SET_HPP
#define RAFFER_OVERLOAD_SET_OVERLOAD_SET_HPP


namespace raffer // interface
{

template <typename... F> struct overload_set : public F... { using F::operator()...; };
template <typename... F> overload_set(F&&...) -> overload_set<F...>;

} // namespace  raffer


#endif // RAFFER_OVERLOAD_SET_OVERLOAD_SET_HPP

#endif // __cplusplus >= 201702L
