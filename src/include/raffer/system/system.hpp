#ifndef RAFFER_SYSTEM_SYSTEM_HPP
#define RAFFER_SYSTEM_SYSTEM_HPP

namespace raffer
{

auto clear_screen() -> int;

auto enable_unicode() -> void;

auto is_down(int key) -> bool;

}

#endif // RAFFER_SYSTEM_SYSTEM_HPP

