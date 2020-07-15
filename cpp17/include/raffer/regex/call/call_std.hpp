#if __cplusplus >= 201703L

#ifndef RAFFER_REGEX_CALL_CALL_STD_HPP
#define RAFFER_REGEX_CALL_CALL_STD_HPP


#include <vector>
#include <string>
#include <unordered_map>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

#include "call.hpp"

#include <cmath>
#include "../../type/type.hpp"


namespace raffer // interface
{

template <typename Char> constexpr auto & basic_cout = std::basic_ostream<Char>{};
template <> constexpr auto & basic_cout<char> = std::cout;
template <> constexpr auto & basic_cout<wchar_t> = std::wcout;

template <typename Char> constexpr auto & basic_cin = std::basic_istream<Char>{};
template <> constexpr auto & basic_cin<char> = std::cin;
template <> constexpr auto & basic_cin<wchar_t> = std::wcin;

} // namespace raffer





namespace raffer // interface
{

auto const default_precision = std::cout.precision();
constexpr auto max_precision = std::numeric_limits<long double>::digits10 + 1;
constexpr auto precision = 15;

template <typename Char> [[nodiscard]] auto std_basic_func_ignore(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

template <typename Char> [[nodiscard]] auto std_basic_func_if(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

template <typename Char> [[nodiscard]] auto std_basic_func_system(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

template <typename Char> [[nodiscard]] auto std_basic_func_print(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
template <typename Char> [[nodiscard]] auto std_basic_func_fprint(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

template <typename Char> [[nodiscard]] auto std_basic_func_arg1(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

template <typename Char> [[nodiscard]] auto std_math_const_pi(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
template <typename Char> [[nodiscard]] auto std_math_const_e(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
template <typename Char> [[nodiscard]] auto std_phys_const_c(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

template <typename Char> [[nodiscard]] auto std_math_func_rmsign(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
template <typename Char> [[nodiscard]] auto std_math_func_pow(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
template <typename Char> [[nodiscard]] auto std_math_func_root(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
template <typename Char> [[nodiscard]] auto std_math_func_log(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
template <typename Char> [[nodiscard]] auto std_math_func_mult(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
template <typename Char> [[nodiscard]] auto std_math_func_div(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
template <typename Char> [[nodiscard]] auto std_math_func_mod(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
template <typename Char> [[nodiscard]] auto std_math_func_add(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
template <typename Char> [[nodiscard]] auto std_math_func_sub(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

template <typename Char> [[nodiscard]] auto std_logic_const_true (basic_smatch<Char> const & arg) -> std::basic_string<Char>;
template <typename Char> [[nodiscard]] auto std_logic_const_false(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

template <typename Char> [[nodiscard]] auto std_logic_func_not(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
template <typename Char> [[nodiscard]] auto std_logic_func_and(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
template <typename Char> [[nodiscard]] auto std_logic_func_or(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
template <typename Char> [[nodiscard]] auto std_logic_func_nand(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
template <typename Char> [[nodiscard]] auto std_logic_func_nor(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
template <typename Char> [[nodiscard]] auto std_logic_func_xor(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
template <typename Char> [[nodiscard]] auto std_logic_func_xnor(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

template <typename Char> [[nodiscard]] auto std_basic_func_range(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

template <typename Char> [[nodiscard]] auto std_math_func_floor(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
template <typename Char> [[nodiscard]] auto std_math_func_ceil(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

template <typename Char> [[nodiscard]] auto std_math_func_sin(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

} // namespace raffer





namespace raffer // implementation
{

template <typename Char>
auto std_basic_func_ignore(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	return to_basic_string<Char>("");
}

template <typename Char>
auto std_basic_func_if(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	bool c;
	raffer::basic_cout<Char> << "<if>" << arg.str(1) << ", " << arg.str(2) << ", " << arg.str(3) << "</if>" << std::endl;
	std::basic_stringstream<Char>(arg.str(1)) >> c;
	return c ? arg.str(2) : arg.str(3);
}

template <typename Char>
auto std_basic_func_system(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	return to_basic_string<Char>(system(to_char_array(arg.str(1).c_str())));
}

template <typename Char>
auto std_basic_func_print(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	raffer::basic_cout<Char> << arg.str(1);
	return arg.str(1);
}



template <typename Char>
auto std_basic_func_fprint(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	auto file = std::basic_ofstream<Char>{to_basic_string<char>(arg.str(1))};
	if(!file);
	else
	{
		file << arg.str(2);
		//ret = "\"" + arg.at(1) + "\"<<";
		file.close();
	}
	return to_basic_string<Char>("");
}

template <typename Char>
auto std_basic_func_arg1(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	return arg.str(1);
}

template <typename Char>
auto std_math_const_pi(basic_smatch<Char> const & arg) -> std::basic_string<Char> { return to_basic_string<Char>("3.14159265359"); }
template <typename Char>
auto std_math_const_e(basic_smatch<Char> const & arg) -> std::basic_string<Char> { return to_basic_string<Char>("2.71828182846"); }
template <typename Char>
auto std_phys_const_c(basic_smatch<Char> const & arg) -> std::basic_string<Char> { return to_basic_string<Char>("299792458"); }

template <typename Char>
auto std_math_func_rmsign(basic_smatch<Char> const & arg) -> std::basic_string<Char> { return to_basic_string<Char>(arg.str(1) == arg.str(2) ? "+" : "-"); }

template <typename Char>
auto std_math_func_pow(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	double a, b;
	std::basic_istringstream<Char>(arg.str(1)) >> a;
	std::basic_istringstream<Char>(arg.str(2)) >> b;
	return to_basic_string<Char, precision>(pow(a, b));
}
template <typename Char>
auto std_math_func_root(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	double a, b;
	std::basic_istringstream<Char>(arg.str(1)) >> a;
	std::basic_istringstream<Char>(arg.str(2)) >> b;
	return to_basic_string<Char, precision>(pow(a, 1 / b));
}
template <typename Char>
auto std_math_func_log(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	double a, b;
	std::basic_istringstream<Char>(arg.str(1)) >> a;
	std::basic_istringstream<Char>(arg.str(2)) >> b;
	return to_basic_string<Char, precision>(log(a) / log(b));
}
template <typename Char>
auto std_math_func_mult(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	double a, b;
	std::basic_istringstream<Char>(arg.str(1)) >> a;
	std::basic_istringstream<Char>(arg.str(2)) >> b;
	return to_basic_string<Char, precision>(a * b);
}
template <typename Char>
auto std_math_func_div(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	double a, b;
	std::basic_istringstream<Char>(arg.str(1)) >> a;
	std::basic_istringstream<Char>(arg.str(2)) >> b;
	return to_basic_string<Char, precision>(a / b);
}
template <typename Char>
auto std_math_func_mod(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	int a, b;
	std::basic_istringstream<Char>(arg.str(1)) >> a;
	std::basic_istringstream<Char>(arg.str(2)) >> b;
	return to_basic_string<Char, precision>(a % b);
}
template <typename Char>
auto std_math_func_add(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	double a, b;
	std::basic_istringstream<Char>(arg.str(1)) >> a;
	std::basic_istringstream<Char>(arg.str(2)) >> b;
	//std::wcout << arg.str(1) << arg.str(2);
	return to_basic_string<Char, precision>(a + b);
}
template <typename Char>
auto std_math_func_sub(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	double a, b;
	std::basic_istringstream<Char>(arg.str(1)) >> a;
	std::basic_istringstream<Char>(arg.str(2)) >> b;
	return to_basic_string<Char, precision>(a - b);
}



template <typename Char>
auto std_logic_const_true(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	return to_basic_string<Char>("1");
}
template <typename Char>
auto std_logic_const_false(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	return to_basic_string<Char>("0");
}

template <typename Char>
auto std_logic_func_not(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	bool a;
	std::basic_istringstream<Char>(arg.str(1)) >> a;
	return to_basic_string<Char, precision>(!a);
}

template <typename Char>
auto std_logic_func_and(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	bool a, b;
	std::basic_istringstream<Char>(arg.str(1)) >> a;
	std::basic_istringstream<Char>(arg.str(2)) >> b;
	return to_basic_string<Char, precision>(a && b);
}

template <typename Char>
auto std_logic_func_or(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	bool a, b;
	std::basic_istringstream<Char>(arg.str(1)) >> a;
	std::basic_istringstream<Char>(arg.str(2)) >> b;
	return to_basic_string<Char, precision>(a || b);
}

template <typename Char>
auto std_logic_func_nand(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	bool a, b;
	std::basic_istringstream<Char>(arg.str(1)) >> a;
	std::basic_istringstream<Char>(arg.str(2)) >> b;
	return to_basic_string<Char, precision>(!(a && b));
}

template <typename Char>
auto std_logic_func_nor(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	bool a, b;
	std::basic_istringstream<Char>(arg.str(1)) >> a;
	std::basic_istringstream<Char>(arg.str(2)) >> b;
	return to_basic_string<Char, precision>(!(a || b));
}

template <typename Char>
auto std_logic_func_xor(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	bool a, b;
	std::basic_istringstream<Char>(arg.str(1)) >> a;
	std::basic_istringstream<Char>(arg.str(2)) >> b;
	return to_basic_string<Char, precision>(a ^ b);
}

template <typename Char>
auto std_logic_func_xnor(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	bool a, b;
	std::basic_istringstream<Char>(arg.str(1)) >> a;
	std::basic_istringstream<Char>(arg.str(2)) >> b;
	return to_basic_string<Char, precision>(!(a ^ b));
}


template <typename Char>
auto std_basic_func_range(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	double first, last, step = 1;
	auto range = std::basic_string<Char>{};
	std::basic_istringstream<Char>(arg.str(1)) >> first;
	std::basic_istringstream<Char>(arg.str(2)) >> last;
	for (auto i = first; i < last; i += step)
		range += to_basic_string<Char, precision>(i) + to_basic_string<Char>(",");
	return range;
}

template <typename Char>
auto std_math_func_floor(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	float x;
	std::basic_istringstream<Char>(arg.str(1)) >> x;
	return to_basic_string<Char, precision>(std::floor(x));
}

template <typename Char>
auto std_math_func_ceil(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	float x;
	std::basic_istringstream<Char>(arg.str(1)) >> x;
	return to_basic_string<Char, precision>(std::ceil(x));
}

template <typename Char>
auto std_math_func_sin(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
	float x;
	std::basic_istringstream<Char>(arg.str(1)) >> x;
	return to_basic_string<Char, precision>(sin(x));
}

} // namespace raffer


#endif // RAFFER_REGEX_CALL_CALL_STD_HPP

#endif // __cplusplus >= 201703L
