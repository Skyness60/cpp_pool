#include "Ice.hpp"


Ice::Ice() : AMateria("ice") {
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy) {
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &copy)
{
	std::cout << "Ice assignment operator called" << std::endl;
	if (this not_eq &copy)
	{
		this->type = copy.type;
	}
	return (*this);
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

AMateria *Ice::clone() const
{
	std::cout << "Ice clone method called" << std::endl;
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
