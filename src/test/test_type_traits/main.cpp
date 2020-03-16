#include "../../lib/type_traits/type_traits.hpp"

#include <iostream>

template <typename T, typename = void> struct is_container : std::false_type {};
template <typename T> constexpr auto is_container_v = is_container<T>::value;

template<typename T> struct is_container<T, std::void_t<
    typename T::value_type,
    typename T::reference,
    typename T::const_reference,
    typename T::iterator,
    typename T::const_iterator,
    typename T::difference_type,
    typename T::size_type,
    decltype (std::declval<T>().begin()),
    decltype (std::declval<T>().end()),
    decltype (std::declval<T>().cbegin()),
    decltype (std::declval<T>().cend()),
    decltype (std::declval<T>().size()),
    decltype (std::declval<T>().max_size()),
    decltype (std::declval<T>().empty())
>> : std::true_type {};

int main()
{
    std::cout << is_container_v<std::forward_list<double>>;
}
