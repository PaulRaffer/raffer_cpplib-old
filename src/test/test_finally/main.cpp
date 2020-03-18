#include <iostream>
#include "../../lib/finally/finally.hpp"







int main()
{
    try
    {
        std::cout << "Open a file" << std::endl;
        FILE *file = fopen("test","w");

        raffer::FINALLY
            std::cout << "Finally you close the file." << std::endl;
            fclose(file);
        END

        std::cout << "do something before exception" << std::endl;

        throw("Some exception");

        std::cout << "do something after exception!?" << std::endl;
    }
    catch(char const *ex)
    {
        std::cout << ex << std::endl;
    }
    catch(...)
    {
        ; //do nothing
    }
}
