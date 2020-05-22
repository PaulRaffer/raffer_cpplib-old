#if __cplusplus >= 201103L

#include "system.hpp"


#include <cstdlib>

#if defined(_WIN32)
    #include <fcntl.h>
    #include <io.h>
    #include <windows.h>
#endif

namespace raffer // implementation
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

auto enable_unicode(FILE * file) -> int
{
    #if defined(_WIN32)
        return _setmode(_fileno(file), _O_U16TEXT);
    #endif
}

auto disable_unicode(FILE * file) -> int
{
    #if defined(_WIN32)
        return _setmode(_fileno(file), _O_TEXT);
    #endif
}


auto enable_unicode_stdio() -> void
{
    enable_unicode(stdin);
    enable_unicode(stdout);
}

auto disable_unicode_stdio() -> void
{
    disable_unicode(stdin);
    disable_unicode(stdout);
}

auto is_down(key k) -> bool
{
    #if defined(_WIN32)
        return GetAsyncKeyState(static_cast<int>(k));
    #else
        return false;
    #endif
}

auto is_up(key k) -> bool
{ return !is_down(k); }

} // namespace raffer


#endif // #if __cplusplus >= 201103L