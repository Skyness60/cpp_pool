#include "WrongAnimal.hpp"

// Constructor default
WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

// Constructor with type
WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "WrongAnimal " << type << " constructor called" << std::endl;
}

// Copy Constructor
WrongAnimal::WrongAnimal(const WrongAnimal &copy) : type(copy.type)
{
	std::cout << "WrongAnimal " << type << " copy constructor called" << std::endl;
}

// Assignation operator
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	if (this not_eq &copy)
	{
		this->type = copy.type;
	}
	return (*this);
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal " << type << " destructor called" << std::endl;
}

// Make sound method
void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal say nothing" << std::endl;
}
