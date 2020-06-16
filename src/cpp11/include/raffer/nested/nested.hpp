#if __cplusplus >= 201103L

#ifndef RAFFER_NESTED_NESTED_HPP
#define RAFFER_NESTED_NESTED_HPP

#define raffer_cpplib_nested__ 202006L


namespace raffer // interface
{

    template <template <typename...> typename Template, std::size_t N, typename H, typename... T>
    struct nested { using type = Template<typename nested<Template, N - 1, H, T...>::type, T...>; };

    template <template <typename...> typename Template, typename H, typename... T>
    struct nested<Template, 0, H, T...> { using type = H; };

    template <template <typename...> typename Template, std::size_t N, typename H, typename... T>
    using nested_t = typename nested<Template, N, H, T...>::type;

} // namespace raffer


#endif // RAFFER_NESTED_NESTED_HPP

#endif // __cplusplus >= 201103L
