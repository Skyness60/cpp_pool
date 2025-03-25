#ifndef FORM_HPP
#define FORM_HPP

// include <iostream>
#include <iostream>

// include <stdexcept>
#include <stdexcept>

// include <string>
#include <string>

// include "Bureaucrat.hpp"
#include "Bureaucrat.hpp"

// Class Bureaucrat
class Bureaucrat;

// class Form
class Form {
    private:
        const std::string name;
        const int gradeSign;
        const int gradeExec;
        bool isSigned;
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
        Form(const std::string name, int gradeSign, int gradeExec);
        // copy constructor
        Form(const Form &copy);
        // destructor
        ~Form();
        // assignation operator
        Form &operator=(const Form &copy);
        // get name method
        const std::string getName(void) const;
        // get grade sign method
        int getGradeSign(void) const;
        // get grade exec method
        int getGradeExec(void) const;
        // get signed method
        bool getSigned(void) const;
        // beSigned method
        void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const Form &Form);
#endif