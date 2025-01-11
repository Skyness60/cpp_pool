#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
}

// Constructor with type
Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Dog" << type << " constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	if (this != &copy) {
		this->type = copy.type;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << this->type << " say WOOOUUUUFF" << std::endl;
}