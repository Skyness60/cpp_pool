#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm 
{
    public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
        virtual ~PresidentialPardonForm(void);
        PresidentialPardonForm   &operator=(PresidentialPardonForm const &copy);

        virtual void    execute(Bureaucrat const &executor) const;
};

#endif