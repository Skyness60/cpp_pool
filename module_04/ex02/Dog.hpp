#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* dogbrain;

	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &other);
		Dog &operator=(const Dog &copy);
		virtual ~Dog();
		virtual void makeSound() const;
		Brain *getBrain() const;
};
#endif // !DOG_HPP