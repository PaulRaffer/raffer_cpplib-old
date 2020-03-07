#ifndef CALL_STD_HPP
#define CALL_STD_HPP

#include <vector>
#include <string>
#include <unordered_map>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <conio.h>

#include "call.hpp"

namespace raffer
{

constexpr int precision = 15;
using Char = wchar_t;

[[nodiscard]] auto std_basic_func_ignore(Basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_basic_func_if    (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_basic_func_system(Basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_basic_func_print (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_basic_func_fprint(Basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_basic_func_arg1  (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_math_const_pi    (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_const_e     (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_const_c     (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_math_func_rmsign (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_func_pow    (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_func_root   (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_func_log    (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_func_mult   (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_func_div    (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_func_mod    (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_func_add    (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_func_sub    (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_logic_const_true (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_logic_const_false(Basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_logic_func_not   (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_logic_func_and   (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_logic_func_or    (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_logic_func_nand  (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_logic_func_nor   (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_logic_func_xor   (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_logic_func_xnor  (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_basic_func_range (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_math_func_floor  (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;
[[nodiscard]] auto std_math_func_ceil   (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;

[[nodiscard]] auto std_math_func_sin    (Basic_smatch<Char> const & arg) -> std::basic_string<Char>;

};

#endif // CALL_STD_H
