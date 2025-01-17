#include <iostream>
#include <iomanip>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

int main() {
    std::cout << GREEN << "=== Welcome to the Materia System Test ===" << RESET << std::endl;

    std::cout << BLUE << "\n--- Creating a Materia Source ---" << RESET << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << BLUE << "\n--- Creating Characters ---" << RESET << std::endl;
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    std::cout << BLUE << "\n--- Creating and Equipping Materias ---" << RESET << std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << BLUE << "\n--- Using Materias ---" << RESET << std::endl;
    std::cout << MAGENTA << "me" << RESET << " is using Materias on " << CYAN << "bob" << RESET << ":\n";
    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << BLUE << "\n--- Unequipping a Materia ---" << RESET << std::endl;
    std::cout << MAGENTA << "me" << RESET << " unequips Materia at slot 0." << std::endl;
    me->unequip(0);

    std::cout << BLUE << "\n--- Attempting to Use an Unequipped Slot ---" << RESET << std::endl;
    me->use(0, *bob);

    std::cout << RED << "\n--- Cleaning Up Memory ---" << RESET << std::endl;
    delete bob;
    delete me;
    delete src;

    std::cout << GREEN << "\n=== Materia System Test Complete! ===" << RESET << std::endl;
    return 0;
}
