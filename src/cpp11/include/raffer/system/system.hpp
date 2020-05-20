#ifndef RAFFER_SYSTEM_SYSTEM_HPP
#define RAFFER_SYSTEM_SYSTEM_HPP


#if __cplusplus >= 201103L

namespace raffer
{

auto clear_screen() -> int;

auto enable_unicode() -> void;

auto is_down(int key) -> bool;

} // namespace raffer

#endif // __cplusplus >= 201103L


#endif // RAFFER_SYSTEM_SYSTEM_HPP
