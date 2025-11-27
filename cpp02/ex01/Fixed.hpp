#include <iostream>
#include <cmath>

//Esqueleto das funcoes done agora so falta fazer a funcionalidade delas

class Fixed
{
private:
    static const int frac_bit = 8;
    int fixed_point_value;
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);

    Fixed(const Fixed &obj);
    Fixed&operator=(const Fixed&);

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    ~Fixed();

    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &source);