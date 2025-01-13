#ifndef CAT_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"
#include "Animal.hpp"

/**
 * @class Cat
 * @brief Classe représentant un chat.
 *
 * La classe Cat est une classe dérivée de la classe Animal. Elle contient
 * un constructeur prenant un type d'animal et une méthode pour produire un
 * son spécifique à un chat.
 */

class Cat : public Animal {
	private:
		Brain *catbrain;
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &other);
		Cat &operator=(const Cat &copy);
		virtual ~Cat();
		virtual void makeSound() const;
		Brain *getBrain() const;
};
#endif // !CAT_HPP
