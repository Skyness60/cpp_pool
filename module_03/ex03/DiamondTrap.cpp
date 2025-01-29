#include "DiamondTrap.hpp"

// constructor with name
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap("default"), FragTrap("default"), name(name)
{
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackPoints = FragTrap::attackPoints;
	std::cout << BOLD_GREEN << "The DiamondTrap " << this->name << " was bord !" << RESET << std::endl;
}

// copy constructor
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
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
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap("default"), FragTrap("default")
{
	std::cout << BOLD_CYAN << "The DiamondTrap " << this->name << " was born and copy the DiamondTrap " << other.name << RESET << std::endl;
	*this = other;
}

// destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << BOLD_RED << "The DiamondTrap " << this->name << " is dead !" << RESET << std::endl;
}

// whoAmI method only for DiamondTrap
void	DiamondTrap::whoAmI()
{
	std::cout << BOLD_MAGENTA << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::name << RESET << std::endl;
}