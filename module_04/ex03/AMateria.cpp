#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
}

AMateria &AMateria::operator=(const AMateria &copy)
{
	if (this not_eq &copy)
	{
		this->type = copy.type;
	}
	return (*this);
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}

AMateria *AMateria::clone() const
{
	return nullptr;
}
