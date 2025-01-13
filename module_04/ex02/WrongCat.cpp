#include "WrongCat.hpp"

// Constructor default
WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {}

// Constructor with type
WrongCat::WrongCat(std::string type) : WrongAnimal(type) {}

// Copy constructor
WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {}

// Assignment operator
WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	if (this not_eq &copy)
	{
		this->type = copy.type;
	}
	return (*this);
}

// Destructor
WrongCat::~WrongCat() {}

// Make sound method
void WrongCat::makeSound() const
{
	std::cout << this->type << " say Miaouuuuuuuuuu wrong" << std::endl;
}