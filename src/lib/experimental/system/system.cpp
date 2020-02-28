#include "system.hpp"

#include <cstdlib>

namespace raffer
{

auto clear_screen() -> int
{
    #if defined(__linux__) || (defined(__APPLE__) && defined(__MACH__))
        return system("clear");
    #elif defined(_WIN32)
        return system("cls");
    #else
        #error "OS not supported!"
    #endif
}

};
