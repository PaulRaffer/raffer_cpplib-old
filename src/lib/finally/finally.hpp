#include <functional>


#define FINALLY finally finally([&]{
#define END });

namespace raffer
{

class finally
{
    std::function<void ()> action;

public:
    finally(std::function<void ()> const & action);
    ~finally();
};

}
