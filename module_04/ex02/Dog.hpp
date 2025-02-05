#ifndef DOG_HPP
#define DOG_HPP
// include <iostream>
#include <iostream>
// include <string>
#include <string>
// include AAnimal class
#include "AAnimal.hpp"
// include Brain class
#include "Brain.hpp"

// class Dog inherit from AAnimal abstract class
class Dog : public AAnimal {
	// private attributes
	private:
		Brain* dogbrain;
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
		// make sound method
		virtual void makeSound() const;
		// get brain method
		Brain *getBrain() const;
};
#endif // !DOG_HPP