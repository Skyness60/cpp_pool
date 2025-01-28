#include "Fixed.hpp"

int	main()
{
	std::cout << BOLD_RED << "===================" << RESET << std::endl;
	std::cout << BOLD_RED << "Original main" << RESET << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << BOLD_YELLOW << a << RESET << std::endl;
	std::cout << BOLD_YELLOW << ++a << RESET << std::endl;
	std::cout << BOLD_YELLOW << a << RESET << std::endl;
	std::cout << BOLD_YELLOW << a++ << RESET << std::endl;
	std::cout << BOLD_YELLOW << a << RESET << std::endl;
	std::cout << BOLD_YELLOW << b << RESET << std::endl;
	std::cout << BOLD_YELLOW << Fixed::max( a, b ) << RESET << std::endl;
	return 0;
}