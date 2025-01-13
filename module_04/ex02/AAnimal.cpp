#include "AAnimal.hpp"

// Constructor default
AAnimal::AAnimal() : type("default")
{
	std::cout << "Animal " << "default" << " constructor called" << std::endl;
}

// Constructor with type
AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "Animal " << type << " constructor called" << std::endl;
}

// Copy Constructor
AAnimal::AAnimal(const AAnimal &other) : type(other.type)
{
	std::cout << "Animal " << type << " copy constructor called" << std::endl;
}

// Assignation operator
AAnimal &AAnimal::operator=(const AAnimal &copy)
{
	if (this not_eq &copy)
	{
		this->type = copy.type;
	}
	return (*this);
}

// Destructor
AAnimal::~AAnimal()
{
	std::cout << "Animal " << type << " destructor called" << std::endl;
}

// Getters
std::string AAnimal::getType() const
{
	return this->type;
}
