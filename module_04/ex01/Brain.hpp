#ifndef BRAIN_HPP
#define BRAIN_HPP
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

// Brain class
class Brain {
	// private attributes
	private:
		std::string ideas[100];
	// public methods
	public:
		// default constructor
		Brain();
		// copy constructor
		Brain(const Brain &copy);
		// destructor
		~Brain();
		// assignation operator
		Brain &operator=(const Brain &copy);
		// get idea method
		const std::string getIdea(int index) const;
		// get ideas method
		const std::string	*getIdeas(void) const;
		// set idea method
		void setIdea(std::string idea, int index);
		// set ideas method
		void setIdeas(const std::string *ideas);
};
#endif