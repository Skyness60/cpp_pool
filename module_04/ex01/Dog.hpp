#ifndef DOG_HPP
#define DOG_HPP
// include necessary libraries
#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

// class Dog that inherits from Animal
class Dog : public Animal {
	// private attributes
	private:
		Brain* dogbrain;
	// public methods
	public:
		// default constructor
		Dog();
		// parameterized constructor
		Dog(std::string type);
		// copy constructor
		Dog(const Dog &other);
		// assignation operator
		Dog &operator=(const Dog &copy);
		// destructor
		virtual ~Dog();
		// makesound method
		virtual void makeSound() const;
		// get brain method
		Brain *getBrain() const;
};
#endif // !DOG_HPP