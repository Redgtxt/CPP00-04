#include "Fixed.hpp"


Fixed::Fixed()
{
    setRawBits(0);
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    setRawBits(value << frac_bit);
    std::cout << "Int constructor called" << std::endl;
    //fixed_point_value = value;
}

Fixed::Fixed(const float value)
{
    setRawBits(roundf(value * float(1 << frac_bit)));
    std::cout << "Float constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this !=  &other)
        setRawBits(other.getRawBits());
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const
{
    return getRawBits() >> frac_bit;
}

float Fixed::toFloat(void) const
{
    return float( getRawBits() / float(1 << frac_bit));
}

int Fixed::getRawBits( void ) const
{
    return fixed_point_value;
}

void Fixed::setRawBits( int const raw )
{
    fixed_point_value = raw;
}

std::ostream &operator<<(std::ostream &out, Fixed const &source)
{
	out << source.toFloat();
	return (out);
}