#ifndef AANIMAL_HPP
#define AANIMAL_HPP
// include <iostream>
#include <iostream>
// include <string>
#include <string>
// include Brain class
#include "Brain.hpp"

// color for the output
#define RESET  "\033[0m"
#define BOLD_RED  "\033[1m\033[31m"      /* Bold Red */
#define BOLD_GREEN  "\033[1m\033[32m"    /* Bold Green */
#define BOLD_YELLOW  "\033[1m\033[33m"   /* Bold Yellow */
#define BOLD_BLUE  "\033[1m\033[34m"     /* Bold Blue */
#define BOLD_MAGENTA  "\033[1m\033[35m"  /* Bold Magenta */
#define BOLD_CYAN  "\033[1m\033[36m"     /* Bold Cyan */
#define BOLD_WHITE  "\033[1m\033[37m"    /* Bold White */

// Class Abstract Animal
class AAnimal {
	// protected attributes
	protected:
		std::string type;
	// public methods
	public:
		// constructor default
		AAnimal(void);
		// constructor with type
		AAnimal(std::string type);
		// copy constructor
		AAnimal(const AAnimal &other);
		// operator overload
		AAnimal &operator=(const AAnimal &copy);
		// destructor
		virtual ~AAnimal(); // virtual destructor 
		// make sound virtual method
		virtual void makeSound() const = 0;
		// get type method
		std::string getType() const;
};
#endif // !ANIMAL_HPP
