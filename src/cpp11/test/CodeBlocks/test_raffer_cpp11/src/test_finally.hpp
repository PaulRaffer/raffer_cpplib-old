#if __cplusplus >= 201103L

#ifndef RAFFER_TEST_FINALLY_HPP
#define RAFFER_TEST_FINALLY_HPP

#include "../../../../include/raffer/finally/finally.hpp"
#include "../../../../include/raffer/finally/macros.hpp"


namespace raffer // test
{
namespace test__
{
namespace finally
{

void finally()
{
	std::cout <<
		"+------------------------------+\n"
		"| finally():                   |\n"
		"+------------------------------+\n";
	try
	{
		std::cout << "before finally\n";
		raffer::finally f([]{
			std::cout << "finally\n";
		});
		std::cout << "before throw\n";
		throw (4);
		std::cout << "after throw\n";
	}
	catch (int i)
	{
		std::cout << "catch\n";
	}
	std::cout << std::endl;
}

void macros()
{
	std::cout <<
		"+------------------------------+\n"
		"| macros():                    |\n"
		"+------------------------------+\n";
	try
	{
		std::cout << "before finally\n";
		raffer::FINALLY
			std::cout << "finally\n";
		END
		std::cout << "before throw\n";
		throw (4);
		std::cout << "after throw\n";
	}
	catch (int i)
	{
		std::cout << "catch\n";
	}
	std::cout << std::endl;
}

void all()
{
	finally();
	macros();
}

} // namespace finally
} // namespace test__
} // namespace raffer


#endif // RAFFER_TEST_FINALLY_HPP

#endif // __cplusplus >= 201103L
