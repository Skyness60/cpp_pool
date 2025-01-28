#include "Fixed.hpp"

// Constructor default
Fixed::Fixed(void)
{
	// Member initialization
	std::cout << BOLD_GREEN << "Default constructor called" << RESET << std::endl;
	value = 0;
}

// Constructor int
Fixed::Fixed(const int value)
{
	// Member initialization
	std::cout << BOLD_GREEN << "Int constructor called" << RESET << std::endl;
	this->value = (value << bits);
}

// Constructor float
Fixed::Fixed(const float floating)
{
	std::cout << BOLD_GREEN << "Float constructor called" << RESET << std::endl;
	this->value = roundf(floating * (1 << bits));
}

// Operator assignation
Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << BOLD_YELLOW << "Copy assignment operator called" << RESET << std::endl;
	if (this not_eq &copy)
		this->value = copy.getRawBits();
	return (*this);
}
// Constructor copy
Fixed::Fixed(const Fixed &copy)
{
	std::cout << BOLD_CYAN << "Copy constructor called" << RESET << std::endl;
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
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

// Setter
void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

// Method public
float Fixed::toFloat(void) const
{
	return (float(this->value) / (1 << bits));
}

int Fixed::toInt(void) const
{
	return (this->value >> bits);
}

// Overload operator <<
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
