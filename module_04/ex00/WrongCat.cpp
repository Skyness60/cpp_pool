#include "WrongCat.hpp"

// Constructor default
WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << BOLD_GREEN << "WrongCat constructor called" << RESET << std::endl;
}

// Constructor with type
WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << BOLD_GREEN << "WrongCat " << type << " constructor called" << RESET << std::endl;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << BOLD_CYAN << "WrongCat " << copy.type << " copy constructor called" << RESET << std::endl;
}

// Assignment operator
WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	std::cout << BOLD_CYAN << "WrongCat " << copy.type << " assignation operator called" << RESET << std::endl;
	if (this not_eq &copy)
	{
		this->type = copy.type;
	}
	return (*this);
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << BOLD_RED << "WrongCat destructor called" << RESET << std::endl;
}

// Make sound method
void WrongCat::makeSound() const
{
	std::cout << BOLD_MAGENTA << this->type << " say Miaouuuuuuuuuu wrong" << RESET << std::endl;
}