#include "Fixed.hpp"
#include <iostream>

int main( void ) {

    std::cout << "--- Constructors & Assignment ---" << std::endl;
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "\n--- Comparisons ---" << std::endl;
    std::cout << "b < c: " << (b < c) << std::endl;
    std::cout << "b > c: " << (b > c) << std::endl;
    std::cout << "b <= d: " << (b <= d) << std::endl;
    std::cout << "b >= d: " << (b >= d) << std::endl;
    std::cout << "b == d: " << (b == d) << std::endl;
    std::cout << "b != c: " << (b != c) << std::endl;

    std::cout << "\n--- Arithmetic ---" << std::endl;
    Fixed const e( 2 );
    Fixed const f( 4 );
    
    std::cout << "c + b = " << (c + b) << std::endl;
    std::cout << "c - b = " << (c - b) << std::endl;
    std::cout << "b * b = " << (b * b) << std::endl;
    std::cout << "f / e = " << (f / e) << std::endl;

    std::cout << "\n--- Increment/Decrement ---" << std::endl;
    Fixed g;
    std::cout << "g: " << g << std::endl;
    std::cout << "++g: " << ++g << std::endl;
    std::cout << "g: " << g << std::endl;
    std::cout << "g++: " << g++ << std::endl;
    std::cout << "g: " << g << std::endl;
    
    std::cout << "--g: " << --g << std::endl;
    std::cout << "g--: " << g-- << std::endl;
    std::cout << "g: " << g << std::endl;

    std::cout << "\n--- Min/Max ---" << std::endl;
    std::cout << "max(a, b): " << Fixed::max( a, b ) << std::endl;
    std::cout << "min(a, b): " << Fixed::min( a, b ) << std::endl;
    
    // Test const versions
    std::cout << "max(const b, const c): " << Fixed::max( b, c ) << std::endl;
    std::cout << "min(const b, const c): " << Fixed::min( b, c ) << std::endl;

    return 0;
}
