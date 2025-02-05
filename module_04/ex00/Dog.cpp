#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << BOLD_GREEN << "Dog constructor called" << RESET << std::endl;
}

// Constructor with type
Dog::Dog(std::string type) : Animal(type)
{
	std::cout << BOLD_GREEN << "Dog " << type << " constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << BOLD_CYAN << "Dog " << other.type << " copy constructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << BOLD_CYAN << "Dog " << copy.type << " assignation operator called" << RESET << std::endl;
	if (this not_eq &copy) {
		Animal::operator=(copy);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << BOLD_RED << "Dog destructor called" << RESET << std::endl;
}

void Dog::makeSound() const
{
	std::cout << BOLD_MAGENTA << this->type << " say WOOOUUUUFF" << RESET << std::endl;
}