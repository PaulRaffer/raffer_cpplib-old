#include "finally.hpp"

namespace raffer
{

finally::finally(std::function<void ()> const & action) : action{action} {}
finally::~finally() { action(); }

}
