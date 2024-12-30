#include "Fixed.hpp"

int main( void ) {
	// Default constructor called
	Fixed a;
	// Copy constructor called
	Fixed b( a );
	// Default constructor called
	Fixed c;
	// Copy assignment operator called
	c = b;
	// getRawBits member function called
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}

