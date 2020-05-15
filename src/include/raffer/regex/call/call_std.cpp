#include "call_std.hpp"

#include <cmath>
#include "../../type/type.hpp"


namespace raffer
{

auto std_basic_func_ignore(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    return L"";
}

auto std_basic_func_if(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    bool c;
    std::wcout << "<if>" << arg.str(1) << ", " << arg.str(2) << ", " << arg.str(3) << "</if>" << std::endl;
    std::wstringstream(arg.str(1)) >> c;
    return c ? arg.str(2) : arg.str(3);
}

auto std_basic_func_system(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    return to_basic_string<Char>(system(to_char_array(arg.str(1).c_str())));
}

auto std_basic_func_print(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    std::wcout << arg.str(1);
    return arg.str(1);
}



auto std_basic_func_fprint(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    std::ofstream file{to_string(arg.str(1))};
    if(!file);
    else
    {
        file << to_string(arg.str(2));
        //ret = "\"" + arg.at(1) + "\"<<";
        file.close();
    }
    return L"";
}

auto std_basic_func_arg1(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    return arg.str(1);
}

auto std_math_const_pi(basic_smatch<Char> const & arg) -> std::basic_string<Char> { return L"3.14159265359"; }
auto std_math_const_e(basic_smatch<Char> const & arg) -> std::basic_string<Char> { return L"2.71828182846"; }
auto std_math_const_c(basic_smatch<Char> const & arg) -> std::basic_string<Char> { return L"299792458"; }

auto std_math_func_rmsign(basic_smatch<Char> const & arg) -> std::basic_string<Char> { return arg.str(1) == arg.str(2) ? L"+" : L"-"; }

auto std_math_func_pow(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    double a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_basic_string<Char>(pow(a, b), precision);
}
auto std_math_func_root(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    double a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_basic_string<Char>(pow(a, 1 / b), precision);
}
auto std_math_func_log(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    double a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_basic_string<Char>(log(a) / log(b), precision);
}
auto std_math_func_mult(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    double a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_basic_string<Char>(a * b, precision);
}
auto std_math_func_div(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    double a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_basic_string<Char>(a / b, precision);
}
auto std_math_func_mod(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    int a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_basic_string<Char>(a % b, precision);
}
auto std_math_func_add(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    double a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    //std::wcout << arg.str(1) << arg.str(2);
    return to_basic_string<Char>(a + b, precision);
}
auto std_math_func_sub(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    double a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_basic_string<Char>(a - b, precision);
}



auto std_logic_const_true(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    return L"1";
}
auto std_logic_const_false(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    return L"0";
}

auto std_logic_func_not(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    bool a;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    return to_basic_string<Char>(!a, precision);
}

auto std_logic_func_and(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    bool a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_basic_string<Char>(a && b, precision);
}

auto std_logic_func_or(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    bool a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_basic_string<Char>(a || b, precision);
}

auto std_logic_func_nand(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    bool a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_basic_string<Char>(!(a && b), precision);
}

auto std_logic_func_nor(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    bool a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_basic_string<Char>(!(a || b), precision);
}

auto std_logic_func_xor(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    bool a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_basic_string<Char>(a ^ b, precision);
}

auto std_logic_func_xnor(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    bool a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_basic_string<Char>(!(a ^ b), precision);
}


auto std_basic_func_range(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    double first, last, step = 1;
    std::wstring range;
    std::basic_istringstream<Char>(arg.str(1)) >> first;
    std::basic_istringstream<Char>(arg.str(2)) >> last;
    for (auto i = first; i < last; i += step)
        range += to_basic_string<Char>(i, precision) + L",";
    return range;
}

auto std_math_func_floor(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    float x;
    std::basic_istringstream<Char>(arg.str(1)) >> x;
    return to_basic_string<Char>(std::floor(x), precision);
}

auto std_math_func_ceil(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    float x;
    std::basic_istringstream<Char>(arg.str(1)) >> x;
    return to_basic_string<Char>(std::ceil(x), precision);
}

auto std_math_func_sin(basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    float x;
    std::basic_istringstream<Char>(arg.str(1)) >> x;
    return to_basic_string<Char>(sin(x), precision);
}

}
