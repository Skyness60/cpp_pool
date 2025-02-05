#include "AAnimal.hpp"

// Constructor default
AAnimal::AAnimal() : type("default")
{
	std::cout << BOLD_GREEN << "Animal " << type << " constructor called" << RESET << std::endl;
}

// Constructor with type
AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << BOLD_GREEN << "Animal " << type << " constructor called" << RESET << std::endl;
}

// Copy Constructor
AAnimal::AAnimal(const AAnimal &other) : type(other.type)
{
	std::cout << BOLD_CYAN << "Animal " << type << " copy constructor called" << RESET << std::endl;
}

// Assignation operator
AAnimal &AAnimal::operator=(const AAnimal &copy)
{
	std::cout << BOLD_YELLOW << "Animal " << type << " assignation operator called" << RESET << std::endl;
	if (this not_eq &copy)
	{
		this->type = copy.type;
	}
	return (*this);
}

// Destructor
AAnimal::~AAnimal()
{
	std::cout << BOLD_RED << "Animal " << type << " destructor called" << RESET << std::endl;
}

// Getters
std::string AAnimal::getType() const
{
	return this->type;
}
