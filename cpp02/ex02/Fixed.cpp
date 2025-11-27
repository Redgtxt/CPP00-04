#include "Fixed.hpp"

Fixed::Fixed()
{
    setRawBits(0);
}

Fixed::Fixed(const int value)
{
    setRawBits(value << frac_bit);
}

Fixed::Fixed(const float value)
{
    setRawBits(roundf(value * float(1 << frac_bit)));
}

Fixed::Fixed(const Fixed &obj)
{
    *this = obj;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if(this !=  &other)
        setRawBits(other.getRawBits());
    return *this;
}

Fixed::~Fixed()
{
}


/// @brief 
/// @param  
/// @return Passa os bits para a direita removendo assim a parte decimal do numero
int Fixed::toInt(void) const
{
    return getRawBits() >> frac_bit;
}

/// @brief Converte o valor armazenado em formato de ponto fixo para float
/// @return Valor float obtido através da divisão dos bits brutos por 2^frac_bit, restaurando assim o valor original com parte decimal
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

/// @brief Overload ao tradicional << para printar um objeto
/// @param out std::cout vou modficar o stream para colocar data nele
/// @param source Objeto que vai ser printado
/// @return vai returnar a referencia ao stream assim podendo usar este operador em varias linhas seguidas
std::ostream &operator<<(std::ostream &out, Fixed const &source)
{
	out << source.toFloat();
	return (out);
}

bool Fixed::operator<(Fixed const &other)
{
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator==(Fixed const &other)
{
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator>(Fixed const &other)
{
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator>=(Fixed const &other)
{
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(Fixed const &other)
{
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator!=(Fixed const &other)
{
    return this->getRawBits() != other.getRawBits();
}
