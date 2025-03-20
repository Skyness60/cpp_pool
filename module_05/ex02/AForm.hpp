#ifndef AFORM_HPP
#define AFORM_HPP

// include <iostream>
#include <iostream>

// include <stdexcept>
#include <stdexcept>

// include <string>
#include <string>

// include "Bureaucrat.hpp"
#include "Bureaucrat.hpp"

// include fstream
#include <fstream> 

// Class Bureaucrat
class Bureaucrat;

// class AForm
class AForm {
    protected:
        const std::string	name;
        std::string			target;
        const int			gradeSign;
        const int			gradeExec;
        bool				isSigned;
    public:
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

        // constructor
        AForm(const std::string name, std::string target, int gradeSign, int gradeExec);
        // copy constructor
        AForm(const AForm &copy);
        // destructor
        virtual ~AForm();
        // assignation operator
        AForm &operator=(const AForm &copy);
        // get name method
        const std::string getName(void) const;
        // get grade sign method
        int getGradeSign(void) const;
        // get grade exec method
        int getGradeExec(void) const;
        // get signed method
        bool getSigned(void) const;
		// get target method
		std::string getTarget(void) const;
        // beSigned method
        void beSigned(const Bureaucrat &bureaucrat);
        // execute method
        virtual void execute(Bureaucrat const & executor) const = 0;
};
#endif