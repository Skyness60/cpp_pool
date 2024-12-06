#include "HumanA.hpp"
// Constructor
HumanA::HumanA(std::string name, Weapon& weapon) : name(name)
{
	this->weapon = &weapon;
	std::cout << GREEN_BOLD << this->name << " spawn in the world with a " << YELLOW_BOLD << this->weapon->getType() << RESET << std::endl;
}
// Deconstructor
HumanA::~HumanA()
{
	std::cout << RED_BOLD << this->name << " dead" << RESET << std::endl;
}
// Methods
void HumanA::attack()
{
	std::cout << BLUE_BOLD << this->name << " attacks with their " << YELLOW_BOLD << this->weapon->getType() << RESET << std::endl;
}
