#ifndef CAT_HPP
#define CAT_HPP
// include necessary libraries
#include <iostream>
#include <string>
#include "Brain.hpp"
#include "Animal.hpp"

// class Cat that inherits from Animal
class Cat : public Animal {
	// private attributes
	private:
		Brain *catbrain;
	// public methods
	public:
		// default constructor
		Cat();
		// parameterized constructor
		Cat(std::string type);
		// copy constructor
		Cat(const Cat &other);
		// assignation operator
		Cat &operator=(const Cat &copy);
		// destructor
		virtual ~Cat();
		// makesound method
		virtual void makeSound() const;
		// get brain method
		Brain *getBrain() const;
};
#endif // !CAT_HPP
