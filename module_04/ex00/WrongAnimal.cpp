#include "WrongAnimal.hpp"

// Constructor default
WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << BOLD_GREEN << "WrongAnimal constructor called" << RESET << std::endl;
}

// Constructor with type
WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << BOLD_GREEN << "WrongAnimal " << type << " constructor called" << RESET << std::endl;
}

// Copy Constructor
WrongAnimal::WrongAnimal(const WrongAnimal &copy) : type(copy.type)
{
	std::cout << BOLD_CYAN << "WrongAnimal " << copy.type << " copy constructor called" << RESET << std::endl;
}

// Assignation operator
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << BOLD_CYAN << "WrongAnimal " << copy.type << " assignation operator called" << RESET << std::endl;
	if (this not_eq &copy)
	{
		this->type = copy.type;
	}
	return (*this);
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << BOLD_RED << "WrongAnimal destructor called" << RESET << std::endl;
}

// Make sound method
void WrongAnimal::makeSound() const
{
	std::cout << BOLD_MAGENTA << "WrongAnimal say nothing" << RESET << std::endl;
}
