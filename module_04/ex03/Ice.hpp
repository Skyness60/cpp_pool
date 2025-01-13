#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &other);
		Ice &operator=(const Ice &copy);
		virtual ~Ice();
		AMateria* clone() const;
		void use(ICharacter& target);
};
#endif