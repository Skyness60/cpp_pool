#ifndef CAT_HPP
#define CAT_HPP
// include <iostream>
#include <iostream>

// include <string>
#include <string>

// include "Animal.hpp" for inheritance
#include "Animal.hpp"

// class Cat inherit from Animal
class Cat : public Animal {
	// public methods
	public:
		// constructor default
		Cat();
		// constructor with type
		Cat(std::string type);
		// copy constructor
		Cat(const Cat &other);
		// operator overload
		Cat &operator=(const Cat &copy);
		// destructor
		virtual ~Cat();
		// make sound method polymorph
		virtual void makeSound() const;
};
#endif // !CAT_HPP
