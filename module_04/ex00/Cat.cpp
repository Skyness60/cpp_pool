#include "Cat.hpp"

// Constructor 
Cat::Cat() : Animal("Cat")
{
	std::cout << BOLD_GREEN << "Cat constructor called" << RESET << std::endl;
}

// Constructor with type
Cat::Cat(std::string type) : Animal(type)
{
	std::cout << BOLD_GREEN << "Cat" << type << " constructor called" << RESET << std::endl;
}

// Copy Constructor
Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << BOLD_CYAN << "Cat" << type << " copy constructor called" << RESET << std::endl;
}

// Assignation operator
Cat &Cat::operator=(const Cat &copy)
{
	std::cout << BOLD_YELLOW << "Cat" << type << " assignation operator called" << RESET << std::endl;
	if (this not_eq &copy)
	{
		this->type = copy.type;
	}
	return (*this);
}

// Destructor
Cat::~Cat()
{
	std::cout << BOLD_RED << "Cat" << type << " destructor called" << RESET << std::endl;
}

// Make sound method polymorph
void Cat::makeSound() const
{
	std::cout << BOLD_MAGENTA << this->type << " say Miaouuuuuuuuuu" << RESET << std::endl;
}
