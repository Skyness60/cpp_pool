#include "Fixed.hpp"

int	main_original(){
	std::cout << BOLD_WHITE << "===================" << RESET << std::endl;
	std::cout << BOLD_WHITE << "Original main" << RESET << std::endl;
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << BOLD_MAGENTA << "a is " << a << RESET << std::endl;
	std::cout << BOLD_MAGENTA << "b is " << b << RESET << std::endl;
	std::cout << BOLD_MAGENTA << "c is " << c << RESET << std::endl;
	std::cout << BOLD_MAGENTA << "d is " << d << RESET << std::endl;
	std::cout << BOLD_MAGENTA << "a is " << a.toInt() << " as integer" << RESET << std::endl;
	std::cout << BOLD_MAGENTA << "b is " << b.toInt() << " as integer" << RESET << std::endl;
	std::cout << BOLD_MAGENTA << "c is " << c.toInt() << " as integer" << RESET << std::endl;
	std::cout << BOLD_MAGENTA << "d is " << d.toInt() << " as integer" << RESET << std::endl;
	return 0;
}

int main() {
	main_original();
	std::cout << BOLD_MAGENTA << "===================" << RESET << std::endl;
	std::cout << BOLD_MAGENTA << "My main" << RESET << std::endl;
    // Exemple 1: Utilisation d'un entier
    Fixed fixedInt(42);  // L'entier 42 devient 42 << 8
    std::cout << BOLD_MAGENTA << "Fixed point representation of 42 as int: " << fixedInt << RESET << std::endl;

    // Exemple 2: Utilisation d'un flottant
    Fixed fixedFloat(3.14f);  // La valeur 3.14 devient 3.14 * (1 << 8)
    std::cout << BOLD_MAGENTA << "Fixed point representation of 3.14 as float: " << fixedFloat << RESET << std::endl;

    // Conversion de Fixed vers int
    int intValue = fixedInt.toInt();  // Conversion du Fixed vers un entier
    std::cout << BOLD_MAGENTA << "Fixed point 42 as integer: " << intValue << RESET << std::endl;

    // Conversion de Fixed vers float
    float floatValue = fixedFloat.toFloat();  // Conversion du Fixed vers un float
    std::cout << BOLD_MAGENTA << "Fixed point 3.14 as float: " << floatValue << RESET << std::endl;

	intValue = fixedFloat.toInt();  // Conversion du Fixed vers un entier
	std::cout << BOLD_MAGENTA << "Fixed point 3.14 as integer: " << intValue << RESET << std::endl;



    return 0;
}