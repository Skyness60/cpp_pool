#include "Fixed.hpp"

int main() {
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