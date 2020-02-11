#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "../../lib/regex/call/call.hpp"
#include "../../lib/regex/call/call_std.hpp"
#include "../../lib/type/type.hpp"

#include <string>

#include <fcntl.h>
#include <io.h>

Unordered_functions<Char> std_func =
{
    { L"std::basic::func::if", std_basic_func_if },
    { L"std::basic::func::system", std_basic_func_system },
    { L"std::inout::func::print", std_basic_func_print },
    { L"std::inout::func::printf", std_basic_func_printf },

    { L"std::math::func::rm[-\\+]", std_math_func_rmsign },
    { L"std::basic::func::arg1", std_basic_func_arg1 },

    { L"std::math::const::pi", std_math_const_pi },
    { L"std::math::const::e", std_math_const_e },
    { L"std::phys::const::c", std_math_const_c },


    { L"std::math::func::pow", std_math_func_pow },
    { L"std::math::func::root", std_math_func_root },
    { L"std::math::func::log", std_math_func_log },
    { L"std::math::func::mult", std_math_func_mult },
    { L"std::math::func::div", std_math_func_div },
    { L"std::math::func::mod", std_math_func_mod },
    { L"std::math::func::add", std_math_func_add },
    { L"std::math::func::sub", std_math_func_sub },

    { L"std::logic::const::true", std_logic_const_true },
    { L"std::logic::const::false", std_logic_const_false },

    { L"std::logic::func::not", std_logic_func_not },
    { L"std::logic::func::and", std_logic_func_and },
    { L"std::logic::func::or", std_logic_func_or },
    { L"std::logic::func::nand", std_logic_func_nand },
    { L"std::logic::func::nor", std_logic_func_nor },
    { L"std::logic::func::xor", std_logic_func_xor },
    { L"std::logic::func::xnor", std_logic_func_xnor },

    { L"std::basic::func::range", std_basic_func_range },

    { L"std::math::func::floor", std_math_func_floor },
    { L"std::math::func::ceil", std_math_func_ceil },

    { L"std::math::func::sin", std_math_func_sin }
};

int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    Ordered_functions<Char> func(40);

    Function_body_ptr<Char> std_func_func =
        [&func](regex_namespace::wsmatch const & arg) -> std::wstring
        {
            unsigned p;
            std::wstringstream(arg.str(1)) >> p;
            func.at(p)[arg.str(2)] = arg.str(3);
            //ret = "1";
            //ret = arg.at(2);
            return L"/*TODO*/";
        };

    Function_body_ptr<Char> std_func_func_std =
        [&func](regex_namespace::wsmatch const & arg) -> std::wstring
        {
            unsigned p;
            std::wstringstream(arg.str(1)) >> p;
            //std::wcout << arg.str(3);
            func.at(p)[arg.str(2)] = std_func[arg.str(3)];
            return arg.str(2);
        };

    /*Function_body_ptr<Char> std_func_cmd =
        [&func](regex_namespace::wsmatch const & arg) -> std::wstring
        {
            std::wcout << "!!!" << arg.str(1) << "???" << std::endl;
            std::wstring output;
            return call<Char>(arg.str(1), func, regex_namespace::wsmatch{});
        };*/

    Function_body_ptr<Char> std_func_script =
        [&func](regex_namespace::wsmatch const & arg)
        {
            /*std::wifstream file("main.txt");
            std::wstring script((std::istreambuf_iterator<Char>(file)), std::istreambuf_iterator<Char>());
            //std::stringstream buf;
            //buf << file.rdbuf();
            //std::string script = buf.str();
            file.close();
            return call(script, func, regex_namespace::wsmatch{});*/

            FILE * file = _wfopen(arg.str(1).c_str(), L"r");
            _setmode(_fileno(file), _O_U8TEXT);
            fseek(file, 0, SEEK_END);
            auto chars = ftell(file);
            fseek(file, 0, SEEK_SET);
            auto script = (Char*)calloc(chars, sizeof(Char));
            fread(script, sizeof(Char), chars, file);

            return call<Char>((Char*)script, func, regex_namespace::wsmatch{});
        };

    Function_body_ptr<Char> std_basic_statement =
        [&func](regex_namespace::wsmatch const & arg)
        {
            return call<Char>(arg.str(1), func, regex_namespace::wsmatch{});
        };


    Function_body_ptr<Char> std_basic_func_printall =
        [&func](regex_namespace::wsmatch const & arg)
        {
            //std::cout << std::setw(3) <<  " | " << std::left << std::setw(40) << " | " << std::endl;
            for (unsigned i = 0; i < func.size(); ++ i)
                for (const auto& [name, body] : func.at(i))
                {
                    std::wcout << std::right << std::setw(3) << i << " | " << std::left << std::setw(50) << name << " | ";
                    try
                    {
                        std::wcout << std::get<std::wstring>(body);
                    }
                    catch (const std::bad_variant_access&)
                    {
                        std::wcout << "std::function";
                    }
                    std::wcout << std::endl;
                }
            return L"";/*TODO*/
        };


    //func.at(4).insert({ LR"(PRIORITY\s*(\d+)\s*(\S+)\s*=\s*(.+))", std_func_func });
    //func.at(4).insert({ LR"(PRIORITY\s*(\d+)\s*(\S+)\s*=\s*(std::\S+))", std_func_func_std });
    // or for boost:
    func.at(4).insert({ LR"(PRIORITY\s*(\d+)\s*(\S+)\s*=\s*([^\n]+)$)", std_func_func });
    func.at(4).insert({ LR"(PRIORITY\s*(\d+)\s*(\S+)\s*=\s*(std::\S+))", std_func_func_std });


    //func.at(3).insert({ R"((?<statement>\{(?&statement)*\}|(if)(boolean)then(?&statement)end))", std_basic_statement });
    //func.at(3).insert({ R"((if)(boolean)then(?&statement)end))", std_basic_statement });
    func.at(7).insert({ L"script\\s*\"([^\"]*)\"", std_func_script });
    func.at(25).insert({ L"print\\s*all", std_basic_func_printall });







    std::wstring input;
    #ifdef DEBUG
        std::wcout <<
    #endif


    //call<Char>(LR"(script "script/init (std).script")", func, regex_namespace::wsmatch{});
    // or for boost:
    call<Char>(LR"(script "script/init (boost).script")", func, regex_namespace::wsmatch{});


    //#ifdef DEBUG
        //std::cout << "<<< " << output << std::endl << std::endl;
        //std_basic_func_printall(regex_namespace::wsmatch{});
    //#endif

    while (true)
    {
        std::fflush(stdin);
        std::wcout << ">>> ";
        while (!std::getline(std::wcin, input));
        std::wcout << "<<< " << call<Char>(input, func, regex_namespace::wsmatch{}) << std::endl;
    }
}
