#include "../../../include/raffer/finally/finally.hpp"
#include <iostream>

auto main() -> int
{
	try {
		raffer::finally f{std::function<void ()>{[]{
			std::cout << "Hallo";
		}}};
	} catch(...) {}
}
