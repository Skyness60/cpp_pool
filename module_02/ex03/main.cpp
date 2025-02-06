#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define LIGHT_MAGENTA "\033[95m" 
#define MAGENTA "\033[35m"
#define RESET "\033[0m"
#define CHAR_EMPTY '.'
#define CHAR_A 'A'
#define CHAR_B 'B'
#define CHAR_C 'C'
#define CHAR_P 'P'
#define CHAR_EDGE 'O'
#define CHAR_INSIDE 'X'
#define COLOR_PRINT(char, color) (std::cout << color << char << RESET << " ")
#define IS_BETWEEN(val, min, max) ((val) >= (min) and (val) <= (max))

bool isOnEdge(Point p1, Point p2, Point p) {
    Fixed crossProduct = (p2.getX() - p1.getX()) * (p.getY() - p1.getY()) -
                         (p2.getY() - p1.getY()) * (p.getX() - p1.getX());
    if (crossProduct not_eq 0)
        return false;
    return IS_BETWEEN(p.getX(), Fixed::min(p1.getX(), p2.getX()), Fixed::max(p1.getX(), p2.getX())) and
           IS_BETWEEN(p.getY(), Fixed::min(p1.getY(), p2.getY()), Fixed::max(p1.getY(), p2.getY()));
}

int main() {
    Point a(0, 0), b(10, 0), c(0, 10), point(2, 5);

    int maxX = Fixed::max(Fixed::max(a.getX(), b.getX()), c.getX()).toInt();
    int maxY = Fixed::max(Fixed::max(a.getY(), b.getY()), c.getY()).toInt();
    int gridSize = std::max(maxX, maxY) + 1;

    char grid[gridSize][gridSize];
    for (int i = 0; i < gridSize; i++)
        for (int j = 0; j < gridSize; j++)
            grid[i][j] = CHAR_EMPTY;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            Point currentPoint(j, i);

            if (i == a.getY().toInt() and j == a.getX().toInt()) grid[i][j] = CHAR_A;
            else if (i == b.getY().toInt() and j == b.getX().toInt()) grid[i][j] = CHAR_B;
            else if (i == c.getY().toInt() and j == c.getX().toInt()) grid[i][j] = CHAR_C;
            else if (isOnEdge(a, b, currentPoint) or isOnEdge(b, c, currentPoint) or isOnEdge(a, c, currentPoint))
                grid[i][j] = CHAR_EDGE;
            else if (bsp(a, b, c, currentPoint))
                grid[i][j] = CHAR_INSIDE;
        }
    }

    int pX = point.getX().toInt(), pY = point.getY().toInt();
    if (pX < gridSize and pY < gridSize) grid[pY][pX] = CHAR_P;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            switch (grid[i][j]) {
                case CHAR_A: COLOR_PRINT(CHAR_A, RED); break;
                case CHAR_B: COLOR_PRINT(CHAR_B, GREEN); break;
                case CHAR_C: COLOR_PRINT(CHAR_C, LIGHT_MAGENTA); break;
                case CHAR_P: COLOR_PRINT(CHAR_P, YELLOW); break;
                case CHAR_EDGE: COLOR_PRINT(CHAR_EDGE, CYAN); break;
                case CHAR_INSIDE: COLOR_PRINT(CHAR_INSIDE, MAGENTA); break;
                default: std::cout << CHAR_EMPTY << " ";
            }
        }
        std::cout << std::endl;
    }

    if (bsp(a, b, c, point))
        std::cout << GREEN << "The point P is inside the triangle." << RESET << std::endl;
    else
        std::cout << RED << "The point P is outside the triangle." << RESET << std::endl;

    return 0;
}
