#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &other);
		Dog &operator=(const Dog &copy);
		virtual ~Dog();
		virtual void makeSound() const;
};
#endif // !DOG_HPP