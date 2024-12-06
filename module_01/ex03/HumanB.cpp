#include "HumanB.hpp"
// Constructor
HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
	std::cout << GREEN_BOLD << this->name << " spawn in the world without a weapon" << std::endl;
}
// Deconstructor
HumanB::~HumanB()
{
	std::cout << RED_BOLD << this->name << " dead" << std::endl;
}
// Methods
void HumanB::attack()
{
	if (this->weapon)
		std::cout << BLUE_BOLD << this->name << " attacks with their " << YELLOW_BOLD << this->weapon->getType() << RESET << std::endl;
	else
		std::cout << this->name << " can't attack because he don't have a weapon" << std::endl;
}
// Setters
void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
	std::cout << MAGENTA_BOLD << this->name << " take the weapon : " << YELLOW_BOLD << this->weapon->getType() << RESET << std::endl;
}
// Getters
Weapon *HumanB::getWeapon()
{
	return (this->weapon);
}
