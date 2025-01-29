#include "ScavTrap.hpp"

// constructor with name
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackPoints = 20;
	std::cout << BOLD_GREEN << "The ScavTrap " << this->name << " was bord !" << RESET << std::endl;
}

// operator overload
ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
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

// copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << BOLD_CYAN << "The ScavTrap " << this->name << " was born and copy the ScavTrap " << other.name << RESET << std::endl;
	*this = other;
}

// destructor
ScavTrap::~ScavTrap()
{
	std::cout << BOLD_RED << "The ScavTrap " << this->name << " is dead !" << RESET << std::endl;
}

// attack method redefined
void	ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0)
	{
		std::cout << BOLD_RED << "ScavTrap " << this->name << " is dead and can't attack !" << RESET << std::endl;
		return ;
	}
	else if (this->energyPoints == 0)
	{
		std::cout << BOLD_RED << "ScavTrap " << this->name << " has no energy and can't attack !" << RESET << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << BOLD_RED << "ScavTrap " << this->name << " attack " << target << ", causing " << this->attackPoints << " points of damage!" << RESET << std::endl;
}

// guard gate method only for ScavTrap
void	ScavTrap::guardGate()
{
	std::cout << BOLD_MAGENTA << "ScavTrap " << this->name << " have enterred in Gate keeper mode !" << RESET << std::endl;
}