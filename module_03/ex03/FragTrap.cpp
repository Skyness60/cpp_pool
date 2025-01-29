#include "FragTrap.hpp"

// constructor with name
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackPoints = 30;
	std::cout << BOLD_GREEN << "The FragTrap " << this->name << " was bord !" << RESET << std::endl;
}

// overload operator
FragTrap &FragTrap::operator=(const FragTrap &copy)
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
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << BOLD_CYAN << "The FragTrap " << this->name << " was born and copy the FragTrap " << other.name << RESET << std::endl;
	*this = other;
}

// destructor
FragTrap::~FragTrap()
{
	std::cout << BOLD_RED << "The FragTrap " << this->name << " is dead !" << RESET << std::endl;
}

// high fives guys method only for FragTrap and child
void	FragTrap::highFivesGuys(void)
{
	std::cout << BOLD_MAGENTA << "FragTrap " << this->name << " high fives guys ! ✋" << RESET << std::endl;
}