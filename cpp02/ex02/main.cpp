#include "Fixed.hpp"

int main()
{
    Fixed a( 5.5f );
    Fixed b( 10.1f );

    if (a < b)
    {
        std::cout << "a is smaller than b" << std::endl;
    }

    if (a == a)
    {
        std::cout << "a is equal to itself" << std::endl;
    }
    
    
    return 0;
}
