#include "Animal.hpp"


// Constructor default
Animal::Animal() : type("default")
{
	std::cout << "Animal " << "default" << " constructor called" << std::endl;
}

// Constructor with type
Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal " << type << " constructor called" << std::endl;
}

// Copy Constructor
Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal " << type << " copy constructor called" << std::endl;
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
Animal::~Animal()
{
	std::cout << "Animal " << type << " destructor called" << std::endl;
}

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
