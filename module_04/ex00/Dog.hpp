#ifndef DOG_HPP
#define DOG_HPP
// include <iostream>
#include <iostream>

// include <string>
#include <string>

// include "Animal.hpp" for inheritance
#include "Animal.hpp"

// class Dog inherit from Animal
class Dog : public Animal {
	// public methods
	public:
		// constructor default
		Dog();
		// constructor with type
		Dog(std::string type);
		// copy constructor
		Dog(const Dog &other);
		// operator overload
		Dog &operator=(const Dog &copy);
		// destructor
		virtual ~Dog();
		// make sound method polymorph
		virtual void makeSound() const;
};
#endif // !DOG_HPP