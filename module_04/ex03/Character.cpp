#include "Character.hpp"

Character::Character() : name("default")
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = nullptr;
}

Character::Character(std::string name) : name(name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = nullptr;
}

Character::Character(const Character &other) : name(other.name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = nullptr;
	}
}

Character &Character::operator=(const Character &copy)
{
	if (this not_eq &copy)
	{
		this->name = copy.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			if (copy.inventory[i])
				this->inventory[i] = copy.inventory[i]->clone();
			else
				this->inventory[i] = nullptr;
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (not this->inventory[i])
		{
			this->inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 and idx < 4)
		this->inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 and idx < 4 and this->inventory[idx])
		this->inventory[idx]->use(target);
}
