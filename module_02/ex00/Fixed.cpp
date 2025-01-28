#include "Fixed.hpp"

// Constructor default
Fixed::Fixed(void)
{
	std::cout << BOLD_GREEN << "Default constructor called" << RESET << std::endl;
	value = 0;
}
// Operator assignation
Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << BOLD_YELLOW <<"Copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
		this->value = copy.getRawBits();
	return (*this);
}
// Constructor copy
Fixed::Fixed(const Fixed &copy)
{
	std::cout << BOLD_CYAN <<"Copy constructor called" << RESET << std::endl;
	*this = copy;
}
// Destructor
Fixed::~Fixed(void)
{
	std::cout << BOLD_RED << "Destructor called" << RESET << std::endl;
}
// Getter
int Fixed::getRawBits(void) const
{
	std::cout << BOLD_WHITE << "getRawBits member function called" << RESET << std::endl;
	return (this->value);
}
// Setter
void Fixed::setRawBits(int const raw)
{
	std::cout << BOLD_WHITE << "setRawBits member function called" << RESET << std::endl;
	value = raw;
}
