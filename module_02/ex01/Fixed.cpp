#include "Fixed.hpp"

// Constructor default
Fixed::Fixed(void)
{
	// Member initialization
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

// Constructor int
Fixed::Fixed(const int value)
{
	// Member initialization
	std::cout << "Int constructor called" << std::endl;
	this->value = (value << bits);
}

// Constructor float
Fixed::Fixed(const float floating)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(floating * (1 << bits));
}

// Operator assignation
Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this not_eq &copy)
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
	return (this->value / (float)(1 << bits));
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
