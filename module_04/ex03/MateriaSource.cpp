#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : count(0)
{
	for (int i = 0; i < 4; i++)
		this->materia[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
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
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i] not_eq nullptr)
			delete this->materia[i];
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (this->count < 4 and m not_eq nullptr)
	{
		this->materia[this->count] = m;
		this->count++;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i] not_eq nullptr and this->materia[i]->getType() == type)
			return this->materia[i]->clone();
	}
	return nullptr;
}
