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