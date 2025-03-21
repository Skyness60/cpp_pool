#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", target, 72, 45) {
    std::cout << BOLD_GREEN "constructor RobotomyRequestForm " << this->name << " created" RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy)
{
    std::cout << BOLD_GREEN "constructor copy RobotomyRequestForm " << this->name << " created" RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    std::cout << BOLD_GREEN "assignation operator RobotomyRequestForm " << this->name << " created" RESET << std::endl;
	if (this not_eq &copy)
		this->target = copy.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << BOLD_RED "destructor RobotomyRequestForm " << this->name << " destroyed" RESET << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
	std::cout << BOLD_BLUE "🤖 Drilling... BZZZT! 🤖" RESET << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2 == 0)
		std::cout << BOLD_GREEN << this->target << " has been robotomized successfully" RESET << std::endl;
	else
		std::cout << BOLD_RED << this->target << " robotomization failed" RESET << std::endl;
}
