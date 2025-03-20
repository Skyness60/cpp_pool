#include "Bureaucrat.hpp"

// constructor
Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade) {
    std::cout << BOLD_GREEN "constructor Bureaucrat " << this->name << " created" RESET << std::endl;
    if (grade < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
}

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade)
{
    std::cout << BOLD_GREEN "copy constructor Bureaucrat " << this->name << " created" RESET << std::endl;
}

// destructor
Bureaucrat::~Bureaucrat()
{
    std::cout << BOLD_RED "destructor Bureaucrat " << this->name << " destroyed" RESET << std::endl;
}

// assignation operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
    std::cout << BOLD_GREEN "assignation operator Bureaucrat " << this->name << " created" RESET << std::endl;
    if (this not_eq &copy) {
        this->grade = copy.grade;
    }
    return *this;
}

// get name method
const std::string Bureaucrat::getName(void) const {
    return this->name;
}

// get grade method
int Bureaucrat::getGrade(void) const {
    return this->grade;
}

// increment grade method
void Bureaucrat::incrementGrade(void) {
    if (this->grade + 1 > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

// decrement grade method
void Bureaucrat::decrementGrade(void) {
    if (this->grade - 1 < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

// what method
const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return BOLD_RED "Grade too high" RESET;
}

// what method
const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return BOLD_RED "Grade too low" RESET;
}

// overload << operator
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << BOLD_BLUE << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << RESET;
    return out;
}

// sign form method
void Bureaucrat::signForm(Form &form) {
    form.beSigned(*this);
}