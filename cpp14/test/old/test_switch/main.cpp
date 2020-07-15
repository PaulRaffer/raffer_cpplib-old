#include "../../lib/switch/switch.hpp"

#include <iostream>
#include <functional>

#define USE_IF_MACROS1

#ifdef USE_IF_MACROS1
    #define IF [&]{if(
    #define THEN ){
    #define ELSE }else{
    #define ELIF }else if(
    #define END }}();
#endif // USE_IF_MACROS1

#ifdef USE_IF_MACROS2
    #define IF if_(
    #define THEN ,[&]{
    #define ELSE },[&]{
    #define END });
#endif // USE_IF_MACROS2

int main()
{
    std::cout << []{switch (3)
        {
        case 1:
            return 5;
        }
    }();



    using namespace raffer;

std::string str = "1234";
    raffer::if_(true,[&]{
        std::cout << "Hallo" << str << std::endl;
    },[&]{
        std::cout << "Welt!" << std::endl;
    });

    IF 0 THEN
        std::cout << "Hallo" << str << std::endl;
    END

    std::cout <<
        IF 0 THEN
            return 7;
        ELIF 1 THEN
            return 8;
        ELSE

        END
}
