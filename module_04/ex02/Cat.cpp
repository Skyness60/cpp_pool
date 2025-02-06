#include "Cat.hpp"

// Constructor 
Cat::Cat() : AAnimal("Cat"), catbrain(new Brain())
{
	std::cout << BOLD_GREEN << "Cat constructor called" << RESET << std::endl;
}

// Constructor with type
Cat::Cat(std::string type) : AAnimal(type), catbrain(new Brain())
{
	std::cout << BOLD_GREEN << "Cat" << type << " constructor called" << RESET << std::endl;
}

// Copy Constructor
Cat::Cat(const Cat &other) : AAnimal(other), catbrain(new Brain(*other.catbrain))
{
	std::cout << BOLD_CYAN << "Cat" << other.type << " copy constructor called" << RESET << std::endl;
}

// Assignation operator
Cat &Cat::operator=(const Cat &copy)
{
	std::cout << BOLD_CYAN << "Cat" << copy.type << " assignation operator called" << RESET << std::endl;
	if (this not_eq &copy)
	{
		delete this->catbrain;
		this->type = copy.type;
		this->catbrain = new Brain(*copy.catbrain);
	}
	return (*this);
}

// Destructor
Cat::~Cat()
{
	std::cout << BOLD_RED << "Cat destructor called" << RESET << std::endl;
	delete this->catbrain;
}

// Make sound method
void Cat::makeSound() const
{
	std::cout << BOLD_MAGENTA << this->type << " say Miaouuuuuuuuuu" << RESET << std::endl;
}

// Get brain method
Brain	*Cat::getBrain(void) const
{
	return this->catbrain;
}
