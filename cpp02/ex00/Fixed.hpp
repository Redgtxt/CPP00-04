#include <iostream>

class Fixed
{
private:
    int fixed_point;
    static const int frac_bits = 8;
public:

    int getRawBits( void ) const;
    void setRawBits( int const raw );
    Fixed(/* args */);
    ~Fixed();
};


 