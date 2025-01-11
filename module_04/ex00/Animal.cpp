#include "Animal.hpp"


// Constructor default
Animal::Animal() : type("default")
{
	std::cout << "Animal " << "default" << " constructor called" << std::endl;
}

// Constructor with type
Animal::Animal(std::string type) : type(type) {}

// Copy Constructor
Animal::Animal(const Animal &other)
{
	*this = other;
}

// Assignation operator
Animal &Animal::operator=(const Animal &copy)
{
	if (this not_eq &copy)
	{
		this->type = copy.type;
	}
	return (*this);
}

// Destructor
Animal::~Animal() {}

// Getters
std::string Animal::getType() const
{
	return this->type;
}

// Make sound method
void Animal::makeSound(void) const
{
	std::cout << "Animal" << this->type << " make a sound" << std::endl;
}
