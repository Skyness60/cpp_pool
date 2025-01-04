#include "Point.hpp"

// Constructor default
Point::Point(void)
{
	this->x = Fixed(0);
	this->y = Fixed(0);
}

// Constructor copy
Point::Point(const Point &copy)
{
	*this = copy;
}

// Operator assignation
Point &Point::operator=(const Point &copy)
{
	this->x = copy.getX();
	this->y = copy.getY();
	return *this;
}

// Constructor parametric
Point::Point(const Fixed x, const Fixed y)
{
	this->x = x;
	this->y = y;
}

// Destructor
Point::~Point()
{
}

// Getter
Fixed Point::getX(void) const
{
	return this->x;
}

Fixed Point::getY(void) const
{
	return this->y;
}

// Setter
void Point::setX(const Fixed x)
{
	this->x = x;
}

void Point::setY(const Fixed y)
{
	this->y = y;
}
