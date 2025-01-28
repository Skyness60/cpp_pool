#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap("default"), FragTrap("default"), name(name)
{
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackPoints = FragTrap::attackPoints;
	std::cout << "The DiamondTrap " << this->name << " was bord !" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	if (this not_eq &copy)
	{
		this->name = copy.name;
		this->hitPoints = copy.hitPoints;
		this->energyPoints = copy.energyPoints;
		this->attackPoints = copy.attackPoints;
	}
	return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap("default"), FragTrap("default")
{
	std::cout << "The DiamondTrap " << this->name << " was born and copy the DiamondTrap " << other.name << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "The DiamondTrap " << this->name << " is dead !" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}