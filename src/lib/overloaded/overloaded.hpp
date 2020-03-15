namespace raffer
{

template <typename... F> struct overloaded : public F... { using F::operator()...; };
template <typename... F> overloaded(F&&...) -> overloaded<F...>;

}
