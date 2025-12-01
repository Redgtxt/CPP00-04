#include <iostream>
#include <cmath>

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

    bool operator<(Fixed const &other) const;
    bool operator>(Fixed const &other) const;
    bool operator>=(Fixed const &other) const;
    bool operator<=(Fixed const &other) const;
    bool operator==(Fixed const &other) const;
    bool operator!=(Fixed const &other) const;

    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Increment/Decrement operators
    Fixed& operator++();    // Pre-increment
    Fixed operator++(int);  // Post-increment
    Fixed& operator--();    // Pre-decrement
    Fixed operator--(int);  // Post-decrement

    static Fixed& min(Fixed &num1,Fixed &num2);
    static Fixed& max(Fixed &num1,Fixed &num2);
    static const Fixed& min(const Fixed &num1, const Fixed &num2);
    static const Fixed& max(const Fixed &num1, const Fixed &num2);


};

std::ostream &operator<<(std::ostream &out, Fixed const &source);
