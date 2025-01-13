#ifndef AANIMAL_HPP
#define AANIMAL_HPP
#include <iostream>
#include <string>
#include "Brain.hpp"

class AAnimal {
	protected:
		std::string type;
	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(const AAnimal &other);
		AAnimal &operator=(const AAnimal &copy);
		virtual ~AAnimal(); // virtual destructor 
		virtual void makeSound() const = 0;
		std::string getType() const;
};
#endif // !ANIMAL_HPP
