#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackPoints = 30;
	std::cout << "The FragTrap " << this->name << " was bord !" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
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

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "The FragTrap " << this->name << " was born and copy the FragTrap " << other.name << std::endl;
	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << "The FragTrap " << this->name << " is dead !" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " high fives guys ! ✋" << std::endl;
}