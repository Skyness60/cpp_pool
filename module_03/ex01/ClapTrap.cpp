#include "ClapTrap.hpp"

// constructor with name
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackPoints(0)
{
	std::cout << BOLD_GREEN << "The ClapTrap " << this->name << " was bord !" << RESET << std::endl;
}

// copy constructor
ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << BOLD_YELLOW <<"Copy assignment operator called" << RESET << std::endl;
	if (this not_eq &copy)
	{
		this->name = copy.name;
		this->hitPoints = copy.hitPoints;
		this->energyPoints = copy.energyPoints;
		this->attackPoints = copy.attackPoints;
	}
	return (*this);
}

// destructor
ClapTrap::~ClapTrap()
{
	std::cout << BOLD_RED << "The ClapTrap " << this->name << " is dead !" << RESET << std::endl;
}

// copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << BOLD_CYAN << "The ClapTrap " << this->name << " was born and copy the ClapTrap " << other.name << RESET << std::endl;
	*this = other;
}

// attack method
void	ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0)
	{
		std::cout << BOLD_RED << "ClapTrap " << this->name << " is dead and can't attack !" << RESET << std::endl;
		return ;
	}
	else if (this->energyPoints == 0)
	{
		std::cout << BOLD_RED << "ClapTrap " << this->name << " has no energy and can't attack !" << RESET << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << BOLD_RED << "ClapTrap " << this->name << " attack " << target << ", causing " << this->attackPoints << " points of damage!" << RESET << std::endl;
}

// take damage method
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << BOLD_RED << "ClapTrap " << this->name << " is dead and can't be repaired !" << RESET << std::endl;
		return ;
	}
	else if (this->hitPoints == 100)
	{
		std::cout << BOLD_YELLOW << "ClapTrap " << this->name << " is already full life !" << RESET << std::endl;
		return ;
	}
	if (this->hitPoints + amount > 100)
	{
		std::cout << BOLD_GREEN << "ClapTrap " << this->name << " is fully repaired !" << RESET << std::endl;
		this->hitPoints = 100;
		return ;
	}
	else
		this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " is repaired by " << amount << " points !" << std::endl;
}

// take damage method
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << BOLD_RED << "ClapTrap " << this->name << " is already dead !" << RESET << std::endl;
		return ;
	}
	if (this->hitPoints < amount)
	{
		this->hitPoints = 0;
		std::cout << BOLD_RED << "ClapTrap " << this->name << " is already dead !" << RESET << std::endl;
		return ;
	}
	else
		this->hitPoints -= amount;
	std::cout << BOLD_RED << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << RESET << std::endl;
}