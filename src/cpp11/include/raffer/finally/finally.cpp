#if __cplusplus >= 201103L

#include "finally.hpp"


namespace raffer // implementation
{

finally::finally(std::function<void ()> action)
: action{std::move(action)} {}

finally::~finally() { action(); }

} // namespace raffer


#endif // __cplusplus >= 201103L
