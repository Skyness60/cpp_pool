#include "../include/whatever.hpp"

int main( void ) {
	{
		std::cout << BOLD_BLUE << "********** Test with int **********" << RESET << std::endl;
		int a = 2;
		int b = 3;
		std::cout << BOLD_GREEN << "a = " << a << ", b = " << b << RESET << std::endl;
		::swap( a, b );
		std::cout << BOLD_GREEN << "After Swap : a = " << a << ", b = " << b << RESET << std::endl;
		std::cout << BOLD_YELLOW << "min( a, b ) = " << ::min( a, b ) << RESET << std::endl;
		std::cout << BOLD_RED << "max( a, b ) = " << ::max( a, b ) << RESET << std::endl;
		std::cout << std::endl << BOLD_BLUE << "********** Test with char **********" << RESET << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		std::cout << BOLD_GREEN << "c = " << c << ", d = " << d << RESET << std::endl;
		::swap(c, d);
		std::cout << BOLD_GREEN << "After Swap : c = " << c << ", d = " << d << RESET << std::endl;
		std::cout << BOLD_YELLOW << "min( c, d ) = " << ::min( c, d ) << RESET << std::endl;
		std::cout << BOLD_RED << "max( c, d ) = " << ::max( c, d ) << RESET << std::endl;
	}
	return 0;
}