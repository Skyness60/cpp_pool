#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), dogbrain(new Brain())
{
	std::cout << BOLD_GREEN << "Dog constructor called" << RESET << std::endl;
}

// Constructor with type
Dog::Dog(std::string type) : Animal(type), dogbrain(new Brain())
{
	std::cout << BOLD_GREEN << "Dog" << type << " constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), dogbrain(new Brain(*other.dogbrain))
{
	std::cout << BOLD_CYAN << "Dog" << other.type << " copy constructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << BOLD_CYAN << "Dog" << copy.type << " assignation operator called" << RESET << std::endl;
	if (this not_eq &copy) {
		this->type = copy.type;
		delete this->dogbrain;
		this->dogbrain = new Brain(*copy.dogbrain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << BOLD_RED << "Dog destructor called" << RESET << std::endl;
	delete this->dogbrain;
}

void Dog::makeSound() const
{
	std::cout << BOLD_MAGENTA << this->type << " say WOOOUUUUFF" << RESET << std::endl;
}

Brain *Dog::getBrain() const
{
	return (this->dogbrain);
}