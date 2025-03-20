#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) {
    std::cout << BOLD_GREEN "constructor ShrubberyCreationForm " << this->name << " created" RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy)
{
    std::cout << BOLD_GREEN "constructor copy ShrubberyCreationForm " << this->name << " created" RESET << std::endl;
}

// ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm copy)
// {
//     std::cout << BOLD_GREEN "assignation operator ShrubberyCreationForm " << this->name << " created" RESET << std::endl;
// 	if (this not_eq &copy)
// 	{
// 		this->name = copy.name;
// 	}
// }