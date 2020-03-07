#include "call_std.hpp"

#include <cmath>
#include "../../type/type.hpp"


namespace raffer
{

auto std_basic_func_ignore(Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    return L"";
}

auto std_basic_func_if    (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    bool c;
    std::wcout << "<if>" << arg.str(1) << ", " << arg.str(2) << ", " << arg.str(3) << "</if>" << std::endl;
    std::wstringstream(arg.str(1)) >> c;
    return c ? arg.str(2) : arg.str(3);
}

auto to_char_arr(wchar_t const * wchar_t_arr) -> char *
{
    auto len = wcslen(wchar_t_arr);
    auto chararr = new char[len + 1];
    memset(chararr, 0, len + 1);
    wcstombs(chararr, wchar_t_arr, len);
    return chararr;
}

auto std_basic_func_system(Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    return to_string<Char>(system(to_char_arr(arg.str(1).c_str())));
}

auto std_basic_func_print (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    std::wcout << arg.str(1);
    return arg.str(1);
}



auto std_basic_func_fprint(Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    std::ofstream file{wstring_to_string(arg.str(1))};
    if(!file);
    else
    {
        file << wstring_to_string(arg.str(2));
        //ret = "\"" + arg.at(1) + "\"<<";
        file.close();
    }
    return L"";
}

auto std_basic_func_arg1  (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    return arg.str(1);
}

auto std_math_const_pi    (Basic_smatch<Char> const & arg) -> std::basic_string<Char> { return L"3.14159265359"; }
auto std_math_const_e     (Basic_smatch<Char> const & arg) -> std::basic_string<Char> { return L"2.71828182846"; }
auto std_math_const_c     (Basic_smatch<Char> const & arg) -> std::basic_string<Char> { return L"299792458"; }

auto std_math_func_rmsign (Basic_smatch<Char> const & arg) -> std::basic_string<Char> { return arg.str(1) == arg.str(2) ? L"+" : L"-"; }

auto std_math_func_pow    (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    double a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_string<Char>(pow(a, b), precision);
}
auto std_math_func_root   (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    double a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_string<Char>(pow(a, 1 / b), precision);
}
auto std_math_func_log    (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    double a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_string<Char>(log(a) / log(b), precision);
}
auto std_math_func_mult   (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    double a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_string<Char>(a * b, precision);
}
auto std_math_func_div    (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    double a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_string<Char>(a / b, precision);
}
auto std_math_func_mod    (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    int a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_string<Char>(a % b, precision);
}
auto std_math_func_add    (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    double a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    //std::wcout << arg.str(1) << arg.str(2);
    return to_string<Char>(a + b, precision);
}
auto std_math_func_sub    (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    double a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_string<Char>(a - b, precision);
}



auto std_logic_const_true (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    return L"1";
}
auto std_logic_const_false(Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    return L"0";
}

auto std_logic_func_not   (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    bool a;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    return to_string<Char>(!a, precision);
}

auto std_logic_func_and   (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    bool a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_string<Char>(a && b, precision);
}

auto std_logic_func_or    (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    bool a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_string<Char>(a || b, precision);
}

auto std_logic_func_nand  (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    bool a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_string<Char>(!(a && b), precision);
}

auto std_logic_func_nor   (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    bool a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_string<Char>(!(a || b), precision);
}

auto std_logic_func_xor   (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    bool a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_string<Char>(a ^ b, precision);
}

auto std_logic_func_xnor  (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    bool a, b;
    std::basic_istringstream<Char>(arg.str(1)) >> a;
    std::basic_istringstream<Char>(arg.str(2)) >> b;
    return to_string<Char>(!(a ^ b), precision);
}


auto std_basic_func_range (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    double first, last, step = 1;
    std::wstring range;
    std::basic_istringstream<Char>(arg.str(1)) >> first;
    std::basic_istringstream<Char>(arg.str(2)) >> last;
    for (auto i = first; i < last; i += step)
        range += to_string<Char>(i, precision) + L",";
    return range;
}

auto std_math_func_floor  (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    float x;
    std::basic_istringstream<Char>(arg.str(1)) >> x;
    return to_string<Char>(std::floor(x), precision);
}

auto std_math_func_ceil   (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    float x;
    std::basic_istringstream<Char>(arg.str(1)) >> x;
    return to_string<Char>(std::ceil(x), precision);
}

auto std_math_func_sin    (Basic_smatch<Char> const & arg) -> std::basic_string<Char>
{
    float x;
    std::basic_istringstream<Char>(arg.str(1)) >> x;
    return to_string<Char>(sin(x), precision);
}

};
