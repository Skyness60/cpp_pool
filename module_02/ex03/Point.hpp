#pragma once
# include <iostream>
# include <cmath>
# include "Fixed.hpp"

// Class Point
class Point {
	// The private section
	private:
		// The x coordinate
		Fixed x;
		// The y coordinate
		Fixed y;
	public:
		// Constructor default
		Point(void);
		// Constructor copy
		Point(const Point &copy);
		// Operator assignation
		Point &operator=(const Point &copy);
		// Constructor parametric
		Point(const Fixed x, const Fixed y);
		// Destructor
		~Point();
		// Getter
		Fixed getX(void) const;
		Fixed getY(void) const;
		// Setter
		void setX(const Fixed x);
		void setY(const Fixed y);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);