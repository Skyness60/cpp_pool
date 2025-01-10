#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    // Calculate the determinant for the vector from a to b and the vector from a to point
    // This helps determine the relative position of the point to the line segment ab
    Fixed x = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());

    // Calculate the determinant for the vector from b to c and the vector from b to point
    // This helps determine the relative position of the point to the line segment bc
    Fixed y = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());

    // Calculate the determinant for the vector from c to a and the vector from c to point
    // This helps determine the relative position of the point to the line segment ca
    Fixed z = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());

    // If all determinants have the same sign (all non-negative or all non-positive),
    // the point is inside the triangle or on its boundary
    if ((x > 0 and y > 0 and z > 0) or (x < 0 and y < 0 and z < 0))
        return true;

    // If the determinants have different signs, the point is outside the triangle
    return false;
}