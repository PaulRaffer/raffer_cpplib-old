#ifndef RAFFER_FINALLY_FINALLY_HPP
#define RAFFER_FINALLY_FINALLY_HPP

#if __cplusplus >= 201103L

#include <functional>

namespace raffer // interface
{

class finally
{
    std::function<void ()> action;

public:
    explicit finally(std::function<void ()> action);
    ~finally();
};

} // namespace raffer

#endif //  __cplusplus >= 201103L

#endif // RAFFER_FINALLY_FINALLY_HPP