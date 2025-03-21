#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Shrubbery", target, 25, 5) {
    std::cout << BOLD_GREEN "constructor PresidentialPardonForm " << this->name << " created" RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy)
{
    std::cout << BOLD_GREEN "constructor copy PresidentialPardonForm " << this->name << " created" RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    std::cout << BOLD_GREEN "assignation operator PresidentialPardonForm " << this->name << " created" RESET << std::endl;
	if (this not_eq &copy)
		this->target = copy.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << BOLD_RED "destructor PresidentialPardonForm " << this->name << " destroyed" RESET << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
	std::cout << BOLD_BLUE << this->target << " has been pardoned by Zafod Beeblebrox" RESET << std::endl;
}