#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

// include necessary libraries
#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

// WrongCat class
class WrongCat : public WrongAnimal
{
	// public methods
	public:
		// default constructor
		WrongCat(void);
		// parameterized constructor
		WrongCat(std::string type);
		// copy constructor
		WrongCat(const WrongCat &copy);
		// assignation operator
		WrongCat &operator=(const WrongCat &copy);
		// destructor
		virtual ~WrongCat();
		// makesound method
		void makeSound() const;
};
#endif // !WRONGCAT_HPP