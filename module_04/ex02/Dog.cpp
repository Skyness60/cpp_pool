#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"), dogbrain(new Brain())
{
	std::cout << "Dog constructor called" << std::endl;
}

// Constructor with type
Dog::Dog(std::string type) : AAnimal(type), dogbrain(new Brain())
{
	std::cout << "Dog" << type << " constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other), dogbrain(new Brain())
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	if (this != &copy) {
		this->type = copy.type;
		this->dogbrain->setIdeas(copy.dogbrain->getIdeas());
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->dogbrain;
}

void Dog::makeSound() const
{
	std::cout << this->type << " say WOOOUUUUFF" << std::endl;
}

Brain *Dog::getBrain() const
{
	return (this->dogbrain);
}