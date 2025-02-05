#ifndef CAT_HPP
#define CAT_HPP
// include <iostream>
#include <iostream>
// include <string>
#include <string>
// include Brain class
#include "Brain.hpp"
// include AAnimal class
#include "AAnimal.hpp"

// class Cat inherit from AAnimal abstract class
class Cat : public AAnimal {
	// private attributes
	private:
		Brain *catbrain;
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
		// make sound method
		virtual void makeSound() const;
		// get brain method
		Brain *getBrain() const;
};
#endif // !CAT_HPP
