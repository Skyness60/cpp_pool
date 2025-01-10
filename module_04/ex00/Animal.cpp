#include "Animal.hpp"

// Constructor
Animal::Animal(std::string type = "Animal") : type(type) {}

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
void Animal::makeSound() const
{
	std::cout << "Animal" << this->type << " make a sound" << std::endl;
}
