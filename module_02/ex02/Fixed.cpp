#include "Fixed.hpp"

// Constructor default
Fixed::Fixed(void)
{
	value = 0;
}

// Constructor int
Fixed::Fixed(const int value)
{
	this->value = (value << bits);
}

// Constructor float
Fixed::Fixed(const float floating)
{
	this->value = roundf(floating * (1 << bits));
}

// Operator assignation
Fixed &Fixed::operator=(const Fixed &copy)
{
	if (this not_eq &copy)
		this->value = copy.getRawBits();
	return (*this);
}
// Operator comparison
bool Fixed::operator>(const Fixed &compare) const
{
	return (this->value > compare.getRawBits());
}

bool Fixed::operator<(const Fixed &compare) const
{
	return (this->value < compare.getRawBits());
}

bool Fixed::operator>=(const Fixed &compare) const
{
	return (this->value >= compare.getRawBits());
}

bool Fixed::operator<=(const Fixed &compare) const
{
	return (this->value <= compare.getRawBits());
}

bool Fixed::operator==(const Fixed &compare) const
{
	return (this->value == compare.getRawBits());
}

bool Fixed::operator!=(const Fixed &compare) const
{
	return (this->value not_eq compare.getRawBits());
}

// Operator arithmetic
Fixed Fixed::operator+(const Fixed &add) const
{
	Fixed result;

	result.setRawBits(this->value + add.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &sub) const
{
	Fixed result;

	result.setRawBits(this->value - sub.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &mul) const
{
	Fixed result;

	result.setRawBits((this->value * mul.getRawBits()) >> bits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &div) const
{
	Fixed result;

	result.setRawBits((this->value << bits) / div.getRawBits());
	return (result);
}

// Operator incrementation
Fixed &Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);

	operator++();
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);

	operator--();
	return (tmp);
}

// Constructor copy
Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}
// Destructor
Fixed::~Fixed(void)
{
}
// Getter
int Fixed::getRawBits(void) const
{
	return (this->value);
}

// Setter
void Fixed::setRawBits(int const raw)
{
	value = raw;
}

// Method public
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

float Fixed::toFloat(void) const
{
	return (this->value / (float)(1 << bits));
}

int Fixed::toInt(void) const
{
	return (this->value >> bits);
}