#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed b(a);//Copy constructor
    Fixed c;

    c = a;//operator=
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
}