#include "Cat.hpp"

// Constructor 
Cat::Cat() : AAnimal("Cat"), catbrain(new Brain())
{
	std::cout << "Cat constructor called" << std::endl;
}

// Constructor with type
Cat::Cat(std::string type) : AAnimal(type), catbrain(new Brain())
{
	std::cout << "Cat" << type << " constructor called" << std::endl;
}

// Copy Constructor
Cat::Cat(const Cat &other) : AAnimal(other), catbrain(new Brain(*other.catbrain))
{
	std::cout << "Cat" << type << " copy constructor called" << std::endl;
}

// Assignation operator
Cat &Cat::operator=(const Cat &copy)
{
	if (this not_eq &copy)
	{
		this->type = copy.type;
		this->catbrain->setIdeas(copy.catbrain->getIdeas());
	}
	return (*this);
}

// Destructor
Cat::~Cat()
{
	std::cout << "Cat" << type << " destructor called" << std::endl;
	delete this->catbrain;
}

// Make sound method
void Cat::makeSound() const
{
	std::cout << this->type << " say Miaouuuuuuuuuu" << std::endl;
}

// Get brain method
Brain	*Cat::getBrain(void) const
{
	return this->catbrain;
}
