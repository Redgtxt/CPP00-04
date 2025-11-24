#include "Fixed.hpp"



//Default constructor
Fixed::Fixed(/* args */)
{
    std::cout << "Default constructor called" << std::endl;
    setRawBits(0);
}

//Cria um novo objeto e copia aka Copie Constructor
Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if(this != &other) // evita que eu faça a = a
        this->setRawBits(other.getRawBits());
    
    return *this;
}

//Destructor
Fixed::~Fixed()
{
    std::cout << "Default Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
     std::cout << "getRawBits member function called" << std::endl;
    return fixed_point;
}

void Fixed::setRawBits( int const raw )
{
    fixed_point = raw;
}