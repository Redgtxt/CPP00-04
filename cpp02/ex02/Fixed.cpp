#include "Fixed.hpp"

Fixed::Fixed()
{
    setRawBits(0);
}

//1000000
Fixed::Fixed(const int value)
{
    setRawBits(value << frac_bit);
}
//Vou passar o float para inteiro 
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

bool Fixed::operator<(Fixed const &other) const
{
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator==(Fixed const &other) const
{
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator>(Fixed const &other) const
{
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator>=(Fixed const &other) const
{
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(Fixed const &other) const
{
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator!=(Fixed const &other) const
{
    return this->getRawBits() != other.getRawBits();
}


//Arithemit

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->fixed_point_value + other.fixed_point_value);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->fixed_point_value - other.fixed_point_value);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->fixed_point_value * other.fixed_point_value) >> frac_bit);//tenho de fazer isto porque se nao a escala dos bits  vai duplicar tambem ou seja em ves de ser 8 vai ser 16
    return result;
}


Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->fixed_point_value << frac_bit) / other.fixed_point_value);
    return result;
}


//increment/decrement

// Pre-increment (++a)
Fixed& Fixed::operator++()
{
    this->fixed_point_value++;
    return *this;
}

// Post-increment (a++)
Fixed Fixed::operator++(int)
{
    Fixed temp = *this;   // Guarda o valor atual
    this->fixed_point_value++; // Incrementa
    return temp;          // Retorna o valor antigo
}

// Pre-decrement (--a)
Fixed& Fixed::operator--()
{
    this->fixed_point_value--;
    return *this;
}

// Post-decrement (a--)
Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->fixed_point_value--;
    return temp;
}


Fixed& Fixed::min(Fixed &num1,Fixed &num2)
{
    if(num1 > num2)
        return num2;
    else
        return num1;

}

const Fixed& Fixed::min(const Fixed &num1, const Fixed &num2)
{
    if(num1 > num2)
        return num2;
    else
        return num1;
}

Fixed& Fixed::max(Fixed &num1,Fixed &num2)
{
    if(num1 < num2)
        return num2;
    else
        return num1;
}

const Fixed& Fixed::max(const Fixed &num1, const Fixed &num2)
{
    if(num1 < num2)
        return num2;
    else
        return num1;
}