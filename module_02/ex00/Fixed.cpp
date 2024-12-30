#include "Fixed.hpp"

// Constructor default
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}
// Operator assignation
Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->value = copy.getRawBits();
	return (*this);
}
// Constructor copy
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}
// Destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
// Getter
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}
// Setter
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}
