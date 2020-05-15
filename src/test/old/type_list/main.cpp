#include <type_traits>
#include <iostream>



template <typename... Types> struct type_list;
template <typename... Types> using tl = type_list<Types...>;




using empty_type_list = type_list<>;

using integral_types = type_list<bool, char,
#if __cpluscplus > 202002L
char8_t,
#endif
char16_t, char32_t, wchar_t, short, int, long, long long>;

using floating_point_types = type_list<float, double, long double>;



// Types:

template <template <typename...> typename TL> struct size_type;
template <> struct size_type<type_list> { using type = std::size_t; };

template <template <typename...> typename TL> using size_type_t = typename size_type<TL>::type;



// Element access:

template <typename TL, size_type_t<type_list> N> struct at;
//template <size_type_t<type_list> N> struct at<empty_type_list, N> {};
template <typename Head, typename... Tail> struct at<type_list<Head, Tail...>, 0> { using type = Head; };
template <typename Head, typename... Tail, size_type_t<type_list> N> struct at<type_list<Head, Tail...>, N> { using type = typename at<type_list<Tail...>, N - 1>::type; };

template <typename TL, size_type_t<type_list> N> using at_t = typename at<TL, N>::type;



template <typename TL> struct front;
template <typename Head, typename... Tail> struct front<type_list<Head, Tail...>> { using type = Head; };

template <typename TL> using front_t = typename front<TL>::type;



template <typename TL> struct back;
template <typename Back> struct back<type_list<Back>> { using type = Back; };
template <typename Head, typename... Tail> struct back<type_list<Head, Tail...>> { using type = typename back<type_list<Tail...>>::type; };

template <typename TL> using back_t = typename back<TL>::type;



// Capacity:

template <typename TL> struct empty : std::false_type {};
template <> struct empty<empty_type_list> : std::true_type {};

template <typename TL> constexpr auto empty_v = empty<TL>::value;



template <typename TL> struct size;
template <typename... Types> struct size<type_list<Types...>> : std::integral_constant<std::size_t, sizeof... (Types)> {};

template <typename TL> constexpr auto size_v = size<TL>::value;



// Modifiers:

template <typename TL> struct clear;
template <typename... Types> struct clear<type_list<Types...>> { using type = empty_type_list; };

template <typename TL> using clear_t = typename clear<TL>::type;



// Lookup:

template <typename TL, typename T> struct contains;
template <typename T> struct contains<empty_type_list, T> : std::false_type {};
template <typename Head, typename... Tail, typename T> struct contains<type_list<Head, Tail...>, T> : std::bool_constant<std::is_same_v<Head, T> || contains<type_list<Tail...>, T>::value> {};

template <typename TL, typename T> constexpr auto contains_v = contains<TL, T>::value;





int main()
{
    using ints = type_list<int, bool, float>;

    std::cout << std::numeric_limits<std::ptrdiff_t>::max() << std::endl;

    //std::cout << size<type_list<int>>::value;

    std::cout << typeid(at<ints, 1>::type).name() << std::endl;
    std::cout << typeid(back_t<ints>).name() << std::endl;
    std::cout << size<ints>::value << std::endl;
    std::cout << contains_v<ints, void> << std::endl;
}
