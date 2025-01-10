#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackPoints = 20;
	std::cout << "The ScavTrap " << this->name << " was bord !" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
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

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "The ScavTrap " << this->name << " was born and copy the ScavTrap " << other.name << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << "The ScavTrap " << this->name << " is dead !" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " is dead and can't attack !" << std::endl;
		return ;
	}
	else if (this->energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " has no energy and can't attack !" << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << "ScavTrap " << this->name << " attack " << target << ", causing " << this->attackPoints << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " have enterred in Gate keeper mode !" << std::endl;
}