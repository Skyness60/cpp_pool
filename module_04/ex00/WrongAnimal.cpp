#include "WrongAnimal.hpp"

// Constructor default
WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {}

// Constructor with type
WrongAnimal::WrongAnimal(std::string type) : type(type) {}

// Copy Constructor
WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	*this = copy;
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
WrongAnimal::~WrongAnimal() {}

// Make sound method
void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal say nothing" << std::endl;
}
