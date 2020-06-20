#if __cplusplus >= 201103L

#ifndef RAFFER_FINALLY_FINALLY_HPP
#define RAFFER_FINALLY_FINALLY_HPP


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


#endif // RAFFER_FINALLY_FINALLY_HPP

#endif //  __cplusplus >= 201103L
