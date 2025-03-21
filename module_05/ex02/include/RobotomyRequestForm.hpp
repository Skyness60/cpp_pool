#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP
#include "AForm.hpp"
#include <iostream>

class Bureaucrat;

class RobotomyRequestForm : public AForm 
{
    public:
		RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &copy);
        virtual ~RobotomyRequestForm(void);
        RobotomyRequestForm   &operator=(RobotomyRequestForm const &copy);
        virtual void    execute(Bureaucrat const &executor) const;
};

#endif