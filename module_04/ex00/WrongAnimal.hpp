#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

// include necessary libraries
#include <iostream>
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

// WrongAnimal class
class WrongAnimal
{
	// protected attributes
	protected:
		std::string type;
	// public methods
	public:
		// default constructor
		WrongAnimal(void);
		// parameterized constructor
		WrongAnimal(std::string type);
		// copy constructor
		WrongAnimal(const WrongAnimal &copy);
		// assignation operator
		WrongAnimal &operator=(const WrongAnimal &copy);
		// destructor
		virtual ~WrongAnimal();
		// makesound method
		void makeSound() const;
};
#endif // !WRONGANIMAL_HPP