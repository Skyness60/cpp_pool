#include "Animal.hpp"

// Constructor default
Animal::Animal() : type("default")
{
	std::cout << BOLD_GREEN << "Animal " << type << " constructor called" << RESET << std::endl;
}

// Constructor with type
Animal::Animal(std::string type) : type(type)
{
	std::cout << BOLD_GREEN << "Animal " << type << " constructor called" << RESET << std::endl;
}

// Copy Constructor
Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << BOLD_CYAN << "Animal " << type << " copy constructor called" << RESET << std::endl;
}

// Assignation operator
Animal &Animal::operator=(const Animal &copy)
{
	std::cout << BOLD_YELLOW << "Animal " << type << " assignation operator called" << RESET << std::endl;
	if (this not_eq &copy)
	{
		this->type = copy.type;
	}
	return (*this);
}

// Destructor
Animal::~Animal()
{
	std::cout << BOLD_RED << "Animal " << type << " destructor called" << RESET << std::endl;
}

// Getters
std::string Animal::getType() const
{
	return this->type;
}

// Make sound method
void Animal::makeSound(void) const
{
	std::cout << BOLD_MAGENTA << "Animal " << this->type << " make a sound" << RESET << std::endl;
}
