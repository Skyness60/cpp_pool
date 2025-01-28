#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackPoints(0)
{
	std::cout << "The ClapTrap " << this->name << " was bord !" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
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

ClapTrap::~ClapTrap()
{
	std::cout << "The ClapTrap " << this->name << " is dead !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "The ClapTrap " << this->name << " was born and copy the ClapTrap " << other.name << std::endl;
	*this = other;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead and can't attack !" << std::endl;
		return ;
	}
	else if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy and can't attack !" << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << "ClapTrap " << this->name << " attack " << target << ", causing " << this->attackPoints << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead and can't be repaired !" << std::endl;
		return ;
	}
	else if (this->hitPoints == 100)
	{
		std::cout << "ClapTrap " << this->name << " is already full life !" << std::endl;
		return ;
	}
	if (this->hitPoints + amount > 100)
		this->hitPoints = 100;
	else
		this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " is repaired by " << amount << " points !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is already dead !" << std::endl;
		return ;
	}
	if (this->hitPoints < amount)
	{
		this->hitPoints = 0;
		std::cout << "ClapTrap " << this->name << " is already dead !" << std::endl;
		return ;
	}
	else
		this->hitPoints -= amount;
	std::cout << "ClapTrap " << this->name << " take " << amount << " points of damage !" << std::endl;
}