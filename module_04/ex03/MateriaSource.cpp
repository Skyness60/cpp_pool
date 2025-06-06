#include "MateriaSource.hpp"

#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : count(0)
{
	std::cout << "MateriaSource constructeur appelé" << std::endl;
	for (int i = 0; i < 4; i++)
		this->materia[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this not_eq &copy)
	{
		this->count = copy.count;
		for (int i = 0; i < 4; i++)
			this->materia[i] = copy.materia[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i] not_eq nullptr)
			delete this->materia[i];
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	std::cout << "learnMateria called" << std::endl;
	if (this->count < 4 and m not_eq nullptr)
	{
		this->materia[this->count] = m;
		this->count++;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	std::cout << "createMateria called with type: " << type << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i] not_eq NULL and this->materia[i]->getType() == type)
			return this->materia[i]->clone();
	}
	return 0;
}
