#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *inventory[4];
	public:
		Character();
		Character(std::string name);
		Character(const Character &other);
		Character &operator=(const Character &copy);
		virtual ~Character();
		std::string const & getName() const;
		AMateria* getMateria(int index) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
#endif