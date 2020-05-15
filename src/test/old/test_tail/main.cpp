#include <iostream>
#include <type_traits>

namespace raffer
{


template <typename First, typename Second> struct type_pair
{
    using first = First;
    using second = Second;
};

template <typename... Types> using tp = type_pair<Types...>;



template <typename TL, typename TL::size_type N> struct at;
template <typename TL, typename N> struct contains;


template <typename Head = void, typename... Tail> struct type_list
{
    using size_type = std::size_t;

    using head = Head;
    using tail = type_list<Tail...>;
    template <size_type N> using at = typename at<type_list, N>::type;
    template <typename T> static constexpr auto contains = contains<type_list, T>::value;

    static constexpr auto empty =
    static constexpr size_type size = 1 + sizeof... (Tail);
};

template <typename... Types> using tl = type_list<Types...>;



template <typename TL> struct head { using type = typename TL::head; };

template <typename TL> using head_t = typename head<TL>::type;



template <typename TL> struct tail { using type = typename TL::tail; };

template <typename TL> using tail_t = typename tail<TL>::type;



template <typename TL, typename TL::size_type N> struct at { using type = typename at<typename TL::tail, N - 1>::type; };
template <typename TL> struct at<TL, 0> { using type = typename TL::head; };

template <typename TL, typename TL::size_type N> using at_t = typename at<TL, N>::type;

template <typename TL, typename T> struct contains { static constexpr bool value = std::is_same_v<T, typename TL::head> || contains<typename TL::tail, T>::value; };
template <typename T> struct contains<type_list<>, T> { static constexpr bool value = 0; };

template <typename TL, typename T> constexpr auto contains_v = contains<TL, T>::value;


















template <typename TL> struct is_raffer_type_list : std::false_type {};

template <typename... Types> struct is_raffer_type_list<type_list<Types...>> : std::true_type {};

template <typename TL> constexpr auto is_raffer_type_list_v = is_raffer_type_list<TL>::value;





template <typename TL, typename = void> struct is_type_list : std::false_type {};

template <typename TL> struct is_type_list<TL, std::enable_if_t<
    std::is_same_v<typename TL::head, head_t<TL>> && std::is_same_v<typename TL::head, typename head<TL>::type> &&
    std::is_same_v<typename TL::tail, tail_t<TL>> && std::is_same_v<typename TL::tail, typename tail<TL>::type> &&
    std::is_integral_v<typename TL::size_type> && std::is_unsigned_v<typename TL::size_type>

>> : std::true_type {};
}


int main()
{
    using types = raffer::tl<bool, float, unsigned>;
    //raffer::typelist<double, int, float>::at<8> i = 6.4;
    //std::cout << i << std::endl;

    raffer::at<types, 2>::type i = 6.4;
    std::cout << i << std::endl;

    types::at<2> j = 6.4;
    std::cout << j << std::endl;

    raffer::at_t<types, 2> k = 6.4;
    std::cout << k << std::endl;

    std::cout << types::size << std::endl;
    std::cout << std::endl;

    std::cout << types::contains<int> << std::endl << raffer::contains<types, int>::value << std::endl << raffer::contains_v<types, int> << std::endl;

    raffer::head_t<types> h = 5;
    std::cout << h << std::endl;

    std::cout << raffer::is_type_list<types>::value;


}
