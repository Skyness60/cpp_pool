#ifndef AMAETERIA_HPP
#define AMAETERIA_HPP

#include <iostream>

class AMateria {
	protected:

	public:
		AMateria();
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &copy);
		virtual ~AMateria();
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
#endif