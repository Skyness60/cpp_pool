#include "Weapon.hpp"
// Constructeur
Weapon::Weapon(std::string type) : type(type)
{
	this->type = type;
	return ;
}
// Deconstructor
Weapon::~Weapon()
{
	return ;
}
// Getter
std::string Weapon::getType(void)
{
	return (this->type);
}
// Setter
void Weapon::setType(std::string type)
{
	this->type = type;
}
