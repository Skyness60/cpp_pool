#include "Intern.hpp"

static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

// constructor
Intern::Intern() {
	std::cout << BOLD_GREEN << "constructor Intern created" << RESET << std::endl;
}

// copy constructor
Intern::Intern(const Intern &copy) {
	std::cout << BOLD_GREEN << "copy constructor Intern created" << RESET << std::endl;
	*this = copy;
}

// destructor
Intern::~Intern() {
	std::cout << BOLD_RED << "destructor Intern destroyed" << RESET << std::endl;
}

// assignation operator
Intern &Intern::operator=(const Intern &copy) {
	std::cout << BOLD_GREEN << "assignation operator Intern created" << RESET << std::endl;
	if (this not_eq &copy) {
	}
	return *this;
}

// make form method
AForm *Intern::makeForm(std::string formName, std::string target) {
    std::pair<std::string, AForm* (*)(const std::string&)> formTypes[] = {
        std::pair<std::string, AForm* (*)(const std::string&)>("shrubbery creation", createShrubbery),
        std::pair<std::string, AForm* (*)(const std::string&)>("robotomy request", createRobotomy),
        std::pair<std::string, AForm* (*)(const std::string&)>("presidential pardon", createPresidential)
    };

    for (size_t i = 0; i < 3; i++) {
        if (formTypes[i].first == formName) {
            std::cout << BOLD_GREEN << "Intern creates " << formName << RESET << std::endl;
            return formTypes[i].second(target);
        }
    }

    std::cerr << BOLD_RED << "Error: Form \"" << formName << "\" does not exist." << RESET << std::endl;
    return NULL;
}
