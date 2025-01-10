#include "Cat.hpp"

// Constructor
Cat::Cat() : Animal("Cat") {}

// Copy Constructor
Cat::Cat(const Cat &other)
{
	*this = other;
}

// Assignation operator
Cat &Cat::operator=(const Cat &copy)
{
	if (this not_eq &copy)
	{
		this->type = copy.type;
	}
	return (*this);
}

// Destructor
Cat::~Cat() {}

// Make sound method
void Cat::makeSound() const
{
	std::cout << this->type << " say Miaouuuuuuuuuu" << std::endl;
}
