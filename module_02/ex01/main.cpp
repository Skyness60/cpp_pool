#include "Fixed.hpp"

int	main_original(){
	std::cout << "===================" << std::endl;
	std::cout << "Original main" << std::endl;
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}

int main() {
	main_original();
	std::cout << "===================" << std::endl;
	std::cout << "My main" << std::endl;
    // Exemple 1: Utilisation d'un entier
    Fixed fixedInt(42);  // L'entier 42 devient 42 << 8
    std::cout << "Fixed point representation of 42 as int: " << fixedInt << std::endl;

    // Exemple 2: Utilisation d'un flottant
    Fixed fixedFloat(3.14f);  // La valeur 3.14 devient 3.14 * (1 << 8)
    std::cout << "Fixed point representation of 3.14 as float: " << fixedFloat << std::endl;

    // Conversion de Fixed vers int
    int intValue = fixedInt.toInt();  // Conversion du Fixed vers un entier
    std::cout << "Fixed point 42 as integer: " << intValue << std::endl;

    // Conversion de Fixed vers float
    float floatValue = fixedFloat.toFloat();  // Conversion du Fixed vers un float
    std::cout << "Fixed point 3.14 as float: " << floatValue << std::endl;

    return 0;
}