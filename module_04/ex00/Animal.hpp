#ifndef ANIMAL_HPP
#define ANIMAL_HPP
// include <iostream>
#include <iostream>

// include <string>
#include <string>

// color for the output
#define RESET  "\033[0m"
#define BOLD_RED  "\033[1m\033[31m"      /* Bold Red */
#define BOLD_GREEN  "\033[1m\033[32m"    /* Bold Green */
#define BOLD_YELLOW  "\033[1m\033[33m"   /* Bold Yellow */
#define BOLD_BLUE  "\033[1m\033[34m"     /* Bold Blue */
#define BOLD_MAGENTA  "\033[1m\033[35m"  /* Bold Magenta */
#define BOLD_CYAN  "\033[1m\033[36m"     /* Bold Cyan */
#define BOLD_WHITE  "\033[1m\033[37m"    /* Bold White */

// Class Animal
class Animal {
	// protected attributes
	protected:
		std::string type;
	// public methods
	public:
		// constructor default
		Animal(void);
		// constructor with type
		Animal(std::string type);
		// copy constructor
		Animal(const Animal &other);
		// operator overload
		Animal &operator=(const Animal &copy);
		// destructor
		virtual ~Animal();
		// make sound virtual method
		virtual void makeSound() const;
		// get type method
		std::string getType() const;
};
#endif // !ANIMAL_HPP
