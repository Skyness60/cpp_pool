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
        AMateria* materia = character->getMateria(i);
        if (materia) {
			if (materia->getType() == "ice")
				std::cout << "Slot " << i << ": " << "🧊" << RESET << std::endl;
			else if (materia->getType() == "cure")
				std::cout << "Slot " << i << ": " << "🩹" << RESET << std::endl;
        } else {
			std::cout << "Slot " << i << ": " << "🔒" << RESET << std::endl;
        }
    }
}

void	clearScreen() {
	std::cout << "\033[2J\033[H";
	std::cout << "\033[3J";
	std::cout.flush();
}

void	personnage()
{
	std::cout << "         Bob" << std::endl;
	std::cout << "      ////^\\\\\\\\\n";
	std::cout << "      | ^   ^ |\n";
	std::cout << "     @ (o) (o) @\n";
	std::cout << "      |   <   |\n";
	std::cout << "      |  ___  |\n";
	std::cout << "       \\_____/\n";
	std::cout << "     ____|  |____\n";
	std::cout << "    /    \\__/    \\\n";
	std::cout << "   /              \\\n";
	std::cout << "  /\\_/|        |\\_/\\\n";
	std::cout << " / /  |        |  \\ \\\n";
	std::cout << "( <   |        |   > )\n";
	std::cout << " \\ \\  |        |  / /\n";
	std::cout << "  \\ \\ |________| / /\n";
}

void	menu()
{
    std::cout << "\nChoose an action:\n";
    std::cout << "1. Show Inventory\n";
    std::cout << "2. Learn a Materia\n";
    std::cout << "3. Create a Materia\n";
    std::cout << "4. Equip Materia\n";
    std::cout << "5. Use Materia on Bob\n";
    std::cout << "6. Unequip Materia\n";
    std::cout << "7. Quit\n";
    std::cout << "Enter choice: ";
}

int main() {
	clearScreen();
	std::cout << GREEN << "=== Bienvenue dans le JEU du Système de Materia ===" << RESET << std::endl;
	std::cout << BLUE << "\n--- Création d'une Source de Materia ---" << RESET << std::endl;
	IMateriaSource* src = new MateriaSource();

	std::cout << BLUE << "\n--- Création des Personnages ---" << RESET << std::endl;
	ICharacter* me = new Character("moi");
	ICharacter* bob = new Character("bob");

	AMateria* tmpice;
	AMateria* tmpcure;
	std::string choice;
	bool running = true;
	bool learncure = false;
	bool learnice = false;
	bool craftedice = false;
	bool craftedcure = false;
	personnage();
	menu();
	while (running) {
		std::getline(std::cin, choice);
		if (std::cin.eof())
			break;
		if (choice == "1") {
			clearScreen();
			personnage();
			std::cout << "Choose an action:\n";
			std::cout << "1. BACK\n";
			printInventory(me);
			std::cout << "Enter choice: ";
			while (true)
			{
				std::getline(std::cin, choice);
				if (std::cin.eof())
				{
					running = false;
					break;
				}
				if (choice != "1") {
					std::cout << RED << "Invalid choice!" << RESET << std::endl;
					std::cout << "Enter choice: ";
				}
				else
					break;
			}
			clearScreen();
			personnage();
			menu();
		} else if (choice == "2") {
			clearScreen();
			personnage();
			std::cout << "Choose a Materia to learn:\n";
			std::cout << "1. Ice\n";
			std::cout << "2. Cure\n";
			std::cout << "3. Both\n";
			std::cout << "4. Back\n";
			std::cout << "Enter choice: ";
			while (true)
			{
				std::getline(std::cin, choice);
				if (std::cin.eof())
				{
					running = false;
					break;
				}
				if (choice == "1") {
					if (learnice) {
						clearScreen();
						std::cout << RED << "You have already learned Ice!" << RESET << std::endl;
						break;
					} else {
						clearScreen();
						std::cout << MAGENTA << "me" << RESET << " is learning a new Materia:\n";
						src->learnMateria(new Ice());
						learnice = true;
						break;
					}
				} else if (choice == "2") {
					if (learncure) {
						clearScreen();
						std::cout << RED << "You have already learned Cure!" << RESET << std::endl;
						break;
					} else {
						clearScreen();
						std::cout << MAGENTA << "me" << RESET << " is learning a new Materia:\n";
						src->learnMateria(new Cure());
						learncure = true;
						break;
					}
				} else if (choice == "3") {
					if (learnice and learncure) {
						clearScreen();
						std::cout << RED << "You have already learned both!" << RESET << std::endl;
						break;
					}
					else if (learnice and !learncure) {
						clearScreen();
						std::cout << MAGENTA << "me" << RESET << " is learning a new Materia:\n";
						src->learnMateria(new Cure());
						learncure = true;
						break;
					}
					else if (!learnice and learncure) {
						clearScreen();
						std::cout << MAGENTA << "me" << RESET << " is learning a new Materia:\n";
						src->learnMateria(new Ice());
						learnice = true;
						break;
					}
					else {
						clearScreen();
						std::cout << MAGENTA << "me" << RESET << " is learning a new Materia:\n";
						src->learnMateria(new Ice());
						src->learnMateria(new Cure());
						learnice = true;
						learncure = true;
						break;
					}
				} else if (choice == "4")
				{
					clearScreen();
					break;
				}
				else {
					std::cout << RED << "Invalid choice!" << RESET << std::endl;
					std::cout << "Enter choice: ";
				}
			}
			personnage();
			menu();
		} else if (choice == "3") {
			clearScreen();
			personnage();
			std::cout << "Choose a Materia to create:\n";
			std::cout << "1. Ice\n";
			std::cout << "2. Cure\n";
			std::cout << "3. Back\n";
			std::cout << "Enter choice: ";

			int iceCount = 0;
			int cureCount = 0;
			for (int i = 0; i < 4; i++) {
				AMateria* materia = me->getMateria(i);
				if (materia) {
					if (materia->getType() == "ice")
						iceCount++;
					else if (materia->getType() == "cure")
						cureCount++;
				}
			}

			while (true)
			{
				if (iceCount + cureCount == 4) {
					clearScreen();
					std::cout << RED << "You have already equipped 4 Materias!" << RESET << std::endl;
					break;
				}
				std::getline(std::cin, choice);
				if (std::cin.eof())
				{
					running = false;
					break;
				}
				if (choice == "1") {
					if (!learnice) {
						clearScreen();
						std::cout << RED << "You have not learned Ice yet!" << RESET << std::endl;
						break;
					} else if (!craftedice) {
						clearScreen();
						std::cout << MAGENTA << "me" << RESET << " is creating a new Materia:\n";
						tmpice = src->createMateria("ice");
						craftedice = true;
						break;
					}
					else if (craftedice) {
						clearScreen();
						std::cout << RED << "You have already crafted Ice!" << RESET << std::endl;
						break;
					}
				} else if (choice == "2") {
					if (!learncure) {
						clearScreen();
						std::cout << RED << "You have not learned Cure yet!" << RESET << std::endl;
						break;
					} else if (!craftedcure) {
						
						clearScreen();
						std::cout << MAGENTA << "me" << RESET << " is creating a new Materia:\n";
						tmpcure = src->createMateria("cure");
						craftedcure = true;
						break;
					}
					else if (craftedcure) {
						clearScreen();
						std::cout << RED << "You have already crafted Cure!" << RESET << std::endl;
						break;
					}
				} else if (choice == "3") {
					clearScreen();
					break;
				} else {
					std::cout << RED << "Invalid choice!" << RESET << std::endl;
					std::cout << "Enter choice: ";
				}
			}
			personnage();
			menu();
		} else if (choice == "4") {
			clearScreen();
			personnage();
			std::cout << "Choose a Materia to equip:\n";
			std::cout << "1. Ice\n";
			std::cout << "2. Cure\n";
			std::cout << "3. Back\n";
			std::cout << "Enter choice: ";
			while (true)
			{
				std::getline(std::cin, choice);
				if (std::cin.eof())
				{
					running = false;
					break;
				}
				if (choice == "1") {
					if (!learnice) {
						clearScreen();
						std::cout << RED << "You have not learned Ice yet!" << RESET << std::endl;
						break;
					} else if (craftedice) {
						clearScreen();
						std::cout << MAGENTA << "me" << RESET << " is equipping Materia at slot:\n";
						me->equip(tmpice);
						std::cout << RED << "You have equipped Ice!" << RESET << std::endl;
						craftedice = false;
						break;
					}
					else if (!craftedice) {
						clearScreen();
						std::cout << RED << "You have not crafted Ice yet!" << RESET << std::endl;
						break;
					}
				} else if (choice == "2") {
					if (!learncure) {
						clearScreen();
						std::cout << RED << "You have not learned Cure yet!" << RESET << std::endl;
						break;
					} else if (craftedcure) {
						clearScreen();
						std::cout << MAGENTA << "me" << RESET << " is equipping Materia at slot:\n";
						me->equip(tmpcure);
						craftedcure = false;
						break;
					}
					else if (!craftedcure) {
						clearScreen();
						std::cout << RED << "You have not crafted Cure yet!" << RESET << std::endl;
						break;
					}
				} else if (choice == "3") {
					clearScreen();
					break;
				} else {
					std::cout << RED << "Invalid choice!" << RESET << std::endl;
					std::cout << "Enter choice: ";
				}
			}
			personnage();
			menu();
		} else if (choice == "5") {
			clearScreen();
			personnage();
			std::cout << "Choose a Materia to use on Bob:\n";
			printInventory(me);
			std::cout << "4. Back\n";
			std::cout << "Enter choice: ";
			while (true)
			{
				std::getline(std::cin, choice);
				if (std::cin.eof())
				{
					running = false;
					break;
				}
				if (choice == "0")
				{
					clearScreen();
					me->use(0, *bob);
					break;
				}
				else if (choice == "1")
				{
					clearScreen();
					me->use(1, *bob);
					break;
				}
				else if (choice == "2")
				{
					clearScreen();
					me->use(2, *bob);
					break;
				}
				else if (choice == "3")
				{
					clearScreen();
					me->use(3, *bob);
					break;
				}
				else if (choice == "4")
				{
					clearScreen();
					break;
				}
				else
				{
					std::cout << RED << "Invalid choice!" << RESET << std::endl;
					std::cout << "Enter choice: ";
				}
			}
			personnage();
			menu();
		} else if (choice == "6") {
			clearScreen();
			personnage();
			std::cout << "Choose a Materia to unequip:\n";
			printInventory(me);
			std::cout << "4. Back\n";
			std::cout << "Enter choice: ";
			while (true)
			{
				std::getline(std::cin, choice);
				if (std::cin.eof())
				{
					running = false;
					break;
				}
				if (choice == "0")
				{
					clearScreen();
					me->unequip(0);
					std::cout << RED << "You have unequipped a Materia !" << RESET << std::endl;
					break;
				}
				else if (choice == "1")
				{
					clearScreen();
					me->unequip(1);
					std::cout << RED << "You have unequipped a Materia !" << RESET << std::endl;
					break;
				}
				else if (choice == "2")
				{
					clearScreen();
					me->unequip(2);
					std::cout << RED << "You have unequipped a Materia !" << RESET << std::endl;
					break;
				}
				else if (choice == "3")
				{
					clearScreen();
					me->unequip(3);
					std::cout << RED << "You have unequipped a Materia !" << RESET << std::endl;
					break;
				}
				else if (choice == "4")
				{
					clearScreen();
					break;
				}
				else
				{
					std::cout << RED << "Invalid choice!" << RESET << std::endl;
					std::cout << "Enter choice: ";
				}
			}
			personnage();
			menu();
		} else if (choice == "7") {
			running = false;
		} else {
			std::cout << RED << "Invalid choice!" << RESET << std::endl;
			std::cout << "Enter choice: ";
		}
	}

	std::cout << RED << "\n--- Cleaning Up Memory ---" << RESET << std::endl;
	delete bob;
	delete me;
	delete src;
	if (craftedice)
		delete tmpice;
	if (craftedcure)
		delete tmpcure;
	std::cout << GREEN << "\n=== Materia System Test Complete! ===" << RESETALL << std::endl;
	return 0;
}
