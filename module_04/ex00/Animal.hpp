#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>
/**
 * @class Animal
 * @brief Classe de base abstraite représentant un animal.
 *
 * La classe Animal sert de classe de base pour d'autres classes d'animaux.
 * Elle contient un type d'animal et des méthodes pour obtenir ce type et 
 * produire un son spécifique à l'animal.
 *
 * @note La méthode makeSound() est virtuelle pure, ce qui signifie que 
 * toute classe dérivée doit la définir. Le destructeur est virtuel pour 
 * garantir que le destructeur de la classe dérivée est appelé correctement.
 * en gros c'est une classe abstraite. (pas d'objet de cette classe)
 */
class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &other);
		Animal &operator=(const Animal &copy);
		virtual ~Animal(); // virtual destructor 
		virtual void makeSound() const = 0;
		std::string getType() const;
};
#endif // !ANIMAL_HPP
