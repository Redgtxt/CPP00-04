#include <iostream>

class Fixed
{
private:
    int fixed_point;
    static const int frac_bits = 8;

public:
    Fixed(/* args */);
    Fixed(const Fixed &obj);
    Fixed& operator=(const Fixed&);
    ~Fixed();

    int getRawBits( void ) const;
    void setRawBits( int const raw );
};


 