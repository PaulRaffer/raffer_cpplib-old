#include <iostream>
#include <type_traits>
#include <vector>
#include "../../../include/raffer/nested/nested.hpp"


int main()
{
	std::cout << std::is_same<
		raffer::nested_t<std::vector, 0, int>,
		int
	>::value;
	
	std::cout << std::is_same<
		raffer::nested_t<std::vector, 1, int>,
		std::vector<int>
	>::value;
	
	std::cout << std::is_same<
		raffer::nested_t<std::vector, 2, int>,
		std::vector<std::vector<int>>
	>::value;
	
	std::cout << std::is_same<
		raffer::nested_t<std::vector, 3, int>,
		std::vector<std::vector<std::vector<int>>>
	>::value;
	
	std::cout << std::is_same<
		raffer::nested_t<std::vector, 4, int>,
		std::vector<std::vector<std::vector<std::vector<int>>>>
	>::value;
}
