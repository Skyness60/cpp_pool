#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : target(target) {
    std::cout << BOLD_GREEN "constructor ShrubberyCreationForm " << this->name << " created" RESET << std::endl;
}