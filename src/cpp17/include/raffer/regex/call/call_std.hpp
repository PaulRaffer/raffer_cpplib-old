#ifndef RAFFER_RAGEX_CALL_CALL_STD_HPP
#define RAFFER_RAGEX_CALL_CALL_STD_HPP

#include <vector>
#include <string>
#include <unordered_map>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
//#include <conio.h>

#include "call.hpp"

namespace raffer
{

constexpr int precision = 15;
using Char = wchar_t;

[[nodiscard]] auto std_basic_func_ignore(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_basic_func_if(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_basic_func_system(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_basic_func_print (basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_basic_func_fprint(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_basic_func_arg1(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_math_const_pi(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_const_e(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_const_c(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_math_func_rmsign(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_func_pow(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_func_root(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_func_log(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_func_mult(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_func_div(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_func_mod(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_func_add(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_func_sub(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_logic_const_true (basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_logic_const_false(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_logic_func_not(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_logic_func_and(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_logic_func_or(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_logic_func_nand(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_logic_func_nor(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_logic_func_xor(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_logic_func_xnor(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_basic_func_range(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_math_func_floor(basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_func_ceil(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_math_func_sin(basic_smatch<Char> const & arg) -> std::basic_string<Char>;

}

#endif // RAFFER_RAGEX_CALL_CALL_STD_HPP
