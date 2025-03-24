#ifndef SHRUBBERYCREATIONFORM_HPP  
#define SHRUBBERYCREATIONFORM_HPP  
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm 
{
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &copy);
        virtual ~ShrubberyCreationForm(void);
        ShrubberyCreationForm   &operator=(ShrubberyCreationForm const &copy);

        virtual void    execute(Bureaucrat const &executor) const;
};
#endif