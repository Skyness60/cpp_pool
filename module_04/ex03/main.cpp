#include <iostream>
#include <iomanip>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

#define RESET   "\033[1m\033[37m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define BLUE    "\033[1;34m"
#define YELLOW  "\033[1;33m"
#define CYAN    "\033[1;36m"
#define MAGENTA "\033[1;35m"
#define RESETALL    "\033[0m"

void printInventory(ICharacter* character) {
    std::cout << YELLOW << "\n=== Inventory ===" << RESET << std::endl;
    for (int i = 0; i < 4; i++) {
        AMateria* materia = character->getMateria(i); // Assuming you have this method
        if (materia) {
            std::cout << "Slot " << i << ": " << materia->getType() << std::endl;
        } else {
            std::cout << "Slot " << i << ": Empty" << std::endl;
        }
    }
}

void	clearScreen() {
	std::cout << "\033[2J\033[H";
	std::cout << "\033[3J";
	std::cout.flush();
}

int main() {
	clearScreen();
    std::cout << GREEN << "=== Welcome to the Materia System Test ===" << RESET << std::endl;

    std::cout << BLUE << "\n--- Creating a Materia Source ---" << RESET << std::endl;
    IMateriaSource* src = new MateriaSource();

    std::cout << BLUE << "\n--- Creating Characters ---" << RESET << std::endl;
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    std::cout << BLUE << "\n--- Creating and Equipping Materias ---" << RESET << std::endl;
    AMateria* tmp;


    std::cout << BLUE << "\n--- Interactive Menu ---" << RESET << std::endl;
    char choice;
    bool running = true;
	bool learncure = false;
	bool learnice = false;
    while (running) {
        std::cout << "\nChoose an action:\n";
        std::cout << "1. Show Inventory\n";
        std::cout << "2. Learn a Materia\n";
        std::cout << "3. Create a Materia\n";
        std::cout << "4. Equip Materia\n";
        std::cout << "5. Use Materia on Bob\n";
        std::cout << "6. Unequip Materia\n";
        std::cout << "7. Quit\n";
        std::cout << "Enter choice: ";
        
        std::cin >> choice;
		if (not choice)
			break;
        switch (choice) {
            case '1':
				clearScreen();
                printInventory(me);
                break;
			case '2':
				clearScreen();
				std::cout << "Choose a Materia to learn:\n";
				std::cout << "1. Ice\n";
				std::cout << "2. Cure\n";
				std::cout << "3. Both\n";
				std::cout << "4. Back\n";
				std::cout << "Enter choice: ";
				std::cin >> choice;
				if (not choice)
					break;
				switch (choice)
				{
					case '1':
						if (learnice)
						{
							std::cout << RED << "You have already learned Ice!" << RESET << std::endl;
							break;
						}
						std::cout << MAGENTA << "me" << RESET << " is learning a new Materia:\n";
						src->learnMateria(new Ice());
						learnice = true;
						break;
					case '2':
						if (learncure)
						{
							std::cout << RED << "You have already learned Cure!" << RESET << std::endl;
							break;
						}
						std::cout << MAGENTA << "me" << RESET << " is learning a new Materia:\n";
						src->learnMateria(new Cure());
						learncure = true;
						break;
					case '3':
						if (learnice and learncure)
						{
							std::cout << RED << "You have already learned both!" << RESET << std::endl;
							break;
						}
						std::cout << MAGENTA << "me" << RESET << " is learning a new Materia:\n";
						src->learnMateria(new Ice());
						src->learnMateria(new Cure());
						learnice = true;
						learncure = true;
						break;
					case '4':
						break;
					default:
						std::cout << RED << "Invalid choice!" << RESET << std::endl;
				}
				break;
			case '3':
				clearScreen();
				std::cout << "Choose a Materia to create:\n";
				std::cout << "1. Ice\n";
				std::cout << "2. Cure\n";
				std::cout << "3. Back\n";
				std::cout << "Enter choice: ";
				std::cin >> choice;
				if (not choice)
					break;
				switch (choice)
				{
					case '1':
						if (not learnice)
						{
							std::cout << RED << "You have not learned Ice yet!" << RESET << std::endl;
							break;
						}
						std::cout << MAGENTA << "me" << RESET
							<< " is creating a new Materia:\n";
						tmp = src->createMateria("ice");
						break;
					case '2':
						if (not learncure)
						{
							std::cout << RED << "You have not learned Cure yet!" << RESET << std::endl;
							break;
						}
						std::cout << MAGENTA << "me" << RESET
							<< " is creating a new Materia:\n";
						tmp = src->createMateria("cure");
						break;
					case '3':
						break;
					default:
						std::cout << RED << "Invalid choice!" << RESET << std::endl;
				}
				break;
			case '4':
				clearScreen();
				std::cout << "Choose a Materia to equip:\n";
				std::cout << "1. Ice\n";
				std::cout << "2. Cure\n";
				std::cout << "3. Back\n";
				std::cout << "Enter choice: ";
				std::cin >> choice;
				if (not choice)
					break;
				switch (choice)
				{
					case '1':
						if (not learnice)
						{
							std::cout << RED << "You have not learned Ice yet!" << RESET << std::endl;
							break;
						}
						std::cout << MAGENTA << "me" << RESET << " is equipping Materia at slot :\n";
						me->equip(src->createMateria("ice"));
						std::cout << RED << "You have equipped Ice!" << RESET << std::endl;
						break;
					case '2':
						if (not learncure)
						{
							std::cout << RED << "You have not learned Cure yet!" << RESET << std::endl;
							break;
						}
						std::cout << MAGENTA << "me" << RESET << " is equipping Materia at slot:\n";
						me->equip(src->createMateria("cure"));
						break;
					case '3':
						break;
					default:
						std::cout << RED << "Invalid choice!" << RESET << std::endl;
				}
				break;
            case '5':
                std::cout << MAGENTA << "me" << RESET << " is using Materia on " << CYAN << "bob" << RESET << ":\n";
                me->use(0, *bob);
                me->use(1, *bob);
                break;
            case '6':
                std::cout << MAGENTA << "me" << RESET << " unequips Materia at slot 0." << std::endl;
                me->unequip(0);
                break;
            case '7':
                running = false;
                break;
            default:
                std::cout << RED << "Invalid choice!" << RESET << std::endl;
        }
    }

    std::cout << RED << "\n--- Cleaning Up Memory ---" << RESET << std::endl;
    delete bob;
    delete me;
    delete src;

    std::cout << GREEN << "\n=== Materia System Test Complete! ===" << RESETALL << std::endl;
    return 0;
}
