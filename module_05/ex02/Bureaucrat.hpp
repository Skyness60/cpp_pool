#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

// include <iostream>
#include <iostream>

// include <stdexcept>
#include <stdexcept>

// include <string>
#include <string>

// include AForm.hpp
#include "AForm.hpp"

// include ShrubberyCreationForm.hpp
#include "ShrubberyCreationForm.hpp"

// include RobotomyRequestForm.hpp
#include "RobotomyRequestForm.hpp"

// include PresidentialPardonForm.hpp
#include "PresidentialPardonForm.hpp"

// define color for the output
# define RESET  "\033[0m" /* Reset */
# define BOLD_RED  "\033[1m\033[31m"      /* Bold Red */
# define BOLD_GREEN  "\033[1m\033[32m"    /* Bold Green */
# define BOLD_YELLOW  "\033[1m\033[33m"   /* Bold Yellow */
# define BOLD_BLUE  "\033[1m\033[34m"     /* Bold Blue */
# define BOLD_MAGENTA  "\033[1m\033[35m"  /* Bold Magenta */
# define BOLD_CYAN  "\033[1m\033[36m"     /* Bold Cyan */
# define BOLD_WHITE  "\033[1m\033[37m"    /* Bold White */

// Maximum grade
#define MAX_GRADE 1
// Minimum grade
#define MIN_GRADE 150

// AForm class
class AForm;

// Bureaucrat class
class Bureaucrat {
    // private attributes
    private:
        const std::string name;
        int grade;
    // public methods
    public:
        // constructor
        Bureaucrat(const std::string name, int grade);
        // copy constructor
        Bureaucrat(const Bureaucrat &copy);
        // destructor
        ~Bureaucrat();
        // assignation operator
        Bureaucrat &operator=(const Bureaucrat &copy);
        // get name method
        const std::string getName(void) const;
        // get grade method
        int getGrade(void) const;
        // increment grade method
        void incrementGrade(void);
        // decrement grade method
        void decrementGrade(void);
        // sign form method
        void signForm(AForm &form);
		// execute form method
		void executeForm(const AForm &form);
        // GradeTooHighException class herited from std::exception
        class GradeTooHighException : public std::exception {
            // public methods
            public:
                // what method
                const char *what() const throw();
        };

        // GradeTooLowException class herited from std::exception
        class GradeTooLowException : public std::exception {
            // public methods
            public:
                // what method
                const char *what() const throw();
        };
};

// output stream operator overload
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
#endif