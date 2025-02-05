#include "Cure.hpp"

Cure::Cure() : AMateria("cure") 
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy) 
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &copy)
{
	std::cout << "Cure assignment operator called" << std::endl;
	if (this not_eq &copy)
	{
		this->type = copy.type;
	}
	return (*this);
}

Cure::~Cure() 
{
	std::cout << "Cure destructor called" << std::endl;
}

AMateria *Cure::clone() const
{
	std::cout << "Cure clone method called" << std::endl;
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "Cure use method called" << std::endl;
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
