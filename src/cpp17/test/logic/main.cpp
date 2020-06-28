#if __cplusplus >= 201703L

#include <iostream>
#include <bitset>
#include "../../include/raffer/logic/logic.hpp"


namespace raffer::test__::logic // test
{

auto logical_not()
{
	std::cout <<
		"+------------------------------+\n"
		"| logical_not():			   |\n"
		"+------------------------------+\n";
	
	std::cout
		<< "not 0 = " << raffer::logical_not(0) << "\n"
		<< "not 1 = " << raffer::logical_not(1) << "\n"
		<< std::endl;
}


auto logical_and()
{
	std::cout <<
		"+------------------------------+\n"
		"| logical_and():			   |\n"
		"+------------------------------+\n";
	
	std::cout
		<< "0 and 0 and 0 = " << raffer::logical_and(0, 0, 0) << "\n"
		<< "0 and 0 and 1 = " << raffer::logical_and(0, 0, 1) << "\n"
		<< "0 and 1 and 0 = " << raffer::logical_and(0, 1, 0) << "\n"
		<< "0 and 1 and 1 = " << raffer::logical_and(0, 1, 1) << "\n"
		<< "1 and 0 and 0 = " << raffer::logical_and(1, 0, 0) << "\n"
		<< "1 and 0 and 1 = " << raffer::logical_and(1, 0, 1) << "\n"
		<< "1 and 1 and 0 = " << raffer::logical_and(1, 1, 0) << "\n"
		<< "1 and 1 and 1 = " << raffer::logical_and(1, 1, 1) << "\n"
		<< std::endl;
}


auto logical_or()
{
	std::cout <<
		"+------------------------------+\n"
		"| logical_or():				|\n"
		"+------------------------------+\n";
	
	std::cout
		<< "0 or 0 or 0 = " << raffer::logical_or(0, 0, 0) << "\n"
		<< "0 or 0 or 1 = " << raffer::logical_or(0, 0, 1) << "\n"
		<< "0 or 1 or 0 = " << raffer::logical_or(0, 1, 0) << "\n"
		<< "0 or 1 or 1 = " << raffer::logical_or(0, 1, 1) << "\n"
		<< "1 or 0 or 0 = " << raffer::logical_or(1, 0, 0) << "\n"
		<< "1 or 0 or 1 = " << raffer::logical_or(1, 0, 1) << "\n"
		<< "1 or 1 or 0 = " << raffer::logical_or(1, 1, 0) << "\n"
		<< "1 or 1 or 1 = " << raffer::logical_or(1, 1, 1) << "\n"
		<< std::endl;
}


auto logical_nand()
{
	std::cout <<
		"+------------------------------+\n"
		"| logical_nand():			    |\n"
		"+------------------------------+\n";
	
	std::cout
		<< "0 nand 0 nand 0 = " << raffer::logical_nand(0, 0, 0) << "\n"
		<< "0 nand 0 nand 1 = " << raffer::logical_nand(0, 0, 1) << "\n"
		<< "0 nand 1 nand 0 = " << raffer::logical_nand(0, 1, 0) << "\n"
		<< "0 nand 1 nand 1 = " << raffer::logical_nand(0, 1, 1) << "\n"
		<< "1 nand 0 nand 0 = " << raffer::logical_nand(1, 0, 0) << "\n"
		<< "1 nand 0 nand 1 = " << raffer::logical_nand(1, 0, 1) << "\n"
		<< "1 nand 1 nand 0 = " << raffer::logical_nand(1, 1, 0) << "\n"
		<< "1 nand 1 nand 1 = " << raffer::logical_nand(1, 1, 1) << "\n"
		<< std::endl;
}


auto logical_nor()
{
	std::cout <<
		"+------------------------------+\n"
		"| logical_nor():			   |\n"
		"+------------------------------+\n";
	
	std::cout
		<< "0 nor 0 nor 0 = " << raffer::logical_nor(0, 0, 0) << "\n"
		<< "0 nor 0 nor 1 = " << raffer::logical_nor(0, 0, 1) << "\n"
		<< "0 nor 1 nor 0 = " << raffer::logical_nor(0, 1, 0) << "\n"
		<< "0 nor 1 nor 1 = " << raffer::logical_nor(0, 1, 1) << "\n"
		<< "1 nor 0 nor 0 = " << raffer::logical_nor(1, 0, 0) << "\n"
		<< "1 nor 0 nor 1 = " << raffer::logical_nor(1, 0, 1) << "\n"
		<< "1 nor 1 nor 0 = " << raffer::logical_nor(1, 1, 0) << "\n"
		<< "1 nor 1 nor 1 = " << raffer::logical_nor(1, 1, 1) << "\n"
		<< std::endl;
}


auto bit_not()
{
	std::cout <<
		"+------------------------------+\n"
		"| bit_not():				   |\n"
		"+------------------------------+\n";
	
	std::cout
		<< "not 0b10 = " << std::bitset<2>(raffer::bit_not(0b10)) << "\n"
		<< "not 0b01 = " << std::bitset<2>(raffer::bit_not(0b01)) << "\n"
		<< std::endl;
}


auto bit_and()
{
	std::cout <<
		"+------------------------------+\n"
		"| bit_and():				   |\n"
		"+------------------------------+\n";
		
	std::cout
		<< "0b10 and 0b10 and 0b10 = " << std::bitset<2>(raffer::bit_and(0b10, 0b10, 0b10)) << "\n"
		<< "0b10 and 0b10 and 0b01 = " << std::bitset<2>(raffer::bit_and(0b10, 0b10, 0b01)) << "\n"
		<< "0b10 and 0b01 and 0b10 = " << std::bitset<2>(raffer::bit_and(0b10, 0b01, 0b10)) << "\n"
		<< "0b10 and 0b01 and 0b01 = " << std::bitset<2>(raffer::bit_and(0b10, 0b01, 0b01)) << "\n"
		<< "0b01 and 0b10 and 0b10 = " << std::bitset<2>(raffer::bit_and(0b01, 0b10, 0b10)) << "\n"
		<< "0b01 and 0b10 and 0b01 = " << std::bitset<2>(raffer::bit_and(0b01, 0b10, 0b01)) << "\n"
		<< "0b01 and 0b01 and 0b10 = " << std::bitset<2>(raffer::bit_and(0b01, 0b01, 0b10)) << "\n"
		<< "0b01 and 0b01 and 0b01 = " << std::bitset<2>(raffer::bit_and(0b01, 0b01, 0b01)) << "\n"
		<< std::endl;
}


auto bit_or()
{
	std::cout <<
		"+------------------------------+\n"
		"| bit_or():					|\n"
		"+------------------------------+\n";
		
	std::cout
		<< "0b10 or 0b10 or 0b10 = " << std::bitset<2>(raffer::bit_or(0b10, 0b10, 0b10)) << "\n"
		<< "0b10 or 0b10 or 0b01 = " << std::bitset<2>(raffer::bit_or(0b10, 0b10, 0b01)) << "\n"
		<< "0b10 or 0b01 or 0b10 = " << std::bitset<2>(raffer::bit_or(0b10, 0b01, 0b10)) << "\n"
		<< "0b10 or 0b01 or 0b01 = " << std::bitset<2>(raffer::bit_or(0b10, 0b01, 0b01)) << "\n"
		<< "0b01 or 0b10 or 0b10 = " << std::bitset<2>(raffer::bit_or(0b01, 0b10, 0b10)) << "\n"
		<< "0b01 or 0b10 or 0b01 = " << std::bitset<2>(raffer::bit_or(0b01, 0b10, 0b01)) << "\n"
		<< "0b01 or 0b01 or 0b10 = " << std::bitset<2>(raffer::bit_or(0b01, 0b01, 0b10)) << "\n"
		<< "0b01 or 0b01 or 0b01 = " << std::bitset<2>(raffer::bit_or(0b01, 0b01, 0b01)) << "\n"
		<< std::endl;
}


auto bit_nand()
{
	std::cout <<
		"+------------------------------+\n"
		"| bit_nand():				  |\n"
		"+------------------------------+\n";
		
	std::cout
		<< "0b10 nand 0b10 nand 0b10 = " << std::bitset<2>(raffer::bit_nand(0b10, 0b10, 0b10)) << "\n"
		<< "0b10 nand 0b10 nand 0b01 = " << std::bitset<2>(raffer::bit_nand(0b10, 0b10, 0b01)) << "\n"
		<< "0b10 nand 0b01 nand 0b10 = " << std::bitset<2>(raffer::bit_nand(0b10, 0b01, 0b10)) << "\n"
		<< "0b10 nand 0b01 nand 0b01 = " << std::bitset<2>(raffer::bit_nand(0b10, 0b01, 0b01)) << "\n"
		<< "0b01 nand 0b10 nand 0b10 = " << std::bitset<2>(raffer::bit_nand(0b01, 0b10, 0b10)) << "\n"
		<< "0b01 nand 0b10 nand 0b01 = " << std::bitset<2>(raffer::bit_nand(0b01, 0b10, 0b01)) << "\n"
		<< "0b01 nand 0b01 nand 0b10 = " << std::bitset<2>(raffer::bit_nand(0b01, 0b01, 0b10)) << "\n"
		<< "0b01 nand 0b01 nand 0b01 = " << std::bitset<2>(raffer::bit_nand(0b01, 0b01, 0b01)) << "\n"
		<< std::endl;
}


auto bit_nor()
{
	std::cout <<
		"+------------------------------+\n"
		"| bit_nor():				   |\n"
		"+------------------------------+\n";
	
	std::cout
		<< "0b10 nor 0b10 nor 0b10 = " << std::bitset<2>(raffer::bit_nor(0b10, 0b10, 0b10)) << "\n"
		<< "0b10 nor 0b10 nor 0b01 = " << std::bitset<2>(raffer::bit_nor(0b10, 0b10, 0b01)) << "\n"
		<< "0b10 nor 0b01 nor 0b10 = " << std::bitset<2>(raffer::bit_nor(0b10, 0b01, 0b10)) << "\n"
		<< "0b10 nor 0b01 nor 0b01 = " << std::bitset<2>(raffer::bit_nor(0b10, 0b01, 0b01)) << "\n"
		<< "0b01 nor 0b10 nor 0b10 = " << std::bitset<2>(raffer::bit_nor(0b01, 0b10, 0b10)) << "\n"
		<< "0b01 nor 0b10 nor 0b01 = " << std::bitset<2>(raffer::bit_nor(0b01, 0b10, 0b01)) << "\n"
		<< "0b01 nor 0b01 nor 0b10 = " << std::bitset<2>(raffer::bit_nor(0b01, 0b01, 0b10)) << "\n"
		<< "0b01 nor 0b01 nor 0b01 = " << std::bitset<2>(raffer::bit_nor(0b01, 0b01, 0b01)) << "\n"
		<< std::endl;
}

} // namespace raffer::test__::logic



auto main() -> int
{
	using namespace raffer::test__::logic;
	
	logical_not();
	logical_and();
	logical_or();
	logical_nand();
	logical_nor();
	
	bit_not();
	bit_and();
	bit_or();
	bit_nand();
	bit_nor();
	
	std::cout << "C++ Standard: " << __cplusplus << std::endl;
}


#endif // __cplusplus >= 201703L
