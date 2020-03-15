#include "system.hpp"

#include <cstdlib>

#include <cstdio>
#include <fcntl.h>
#include <io.h>

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

auto enable_unicode() -> void
{
    #if defined(_WIN32)
        _setmode(_fileno(stdin), _O_U16TEXT);
        _setmode(_fileno(stdout), _O_U16TEXT);
    #endif
}

}
