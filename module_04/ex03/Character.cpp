#include "Character.hpp"

#include <iostream>
#include "Character.hpp"

Character::Character() : name("default")
{
	std::cout << "Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = nullptr;
}

Character::Character(std::string name) : name(name)
{
	std::cout << "Parameterized constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = nullptr;
}

Character::Character(const Character &other) : name(other.name)
{
	std::cout << "Copy constructor called" << std::endl;
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
	std::cout << "Assignment operator called" << std::endl;
	if (this != &copy)
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
	std::cout << "Destructor called" << std::endl;
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
	std::cout << "Equip called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	std::cout << "Unequip called" << std::endl;
	if (idx >= 0 && idx < 4)
		this->inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target)
{
	std::cout << "Use called" << std::endl;
	if (idx >= 0 && idx < 4 && this->inventory[idx])
		this->inventory[idx]->use(target);
}
