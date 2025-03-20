#include "AForm.hpp"

// constructor
AForm::AForm(const std::string name, std::string target, int gradeSign, int gradeExec) : name(name), target(target), gradeSign(gradeSign), gradeExec(gradeExec), isSigned(false) {
    std::cout << BOLD_GREEN "constructor AForm " << this->name << " created" RESET << std::endl;
    if (gradeSign < MAX_GRADE or gradeExec < MAX_GRADE)
        throw AForm::GradeTooHighException();
    else if (gradeSign > MIN_GRADE or gradeExec > MIN_GRADE)
        throw AForm::GradeTooLowException();
}

// copy constructor
AForm::AForm(const AForm &copy) : name(copy.name), gradeSign(copy.gradeSign), gradeExec(copy.gradeExec), isSigned(copy.isSigned)
{
    std::cout << BOLD_GREEN "copy constructor AForm " << this->name << " created" RESET << std::endl;
}

// destructor
AForm::~AForm()
{
    std::cout << BOLD_RED "destructor AForm " << this->name << " destroyed" RESET << std::endl;
}

// assignation operator
AForm &AForm::operator=(const AForm &copy) {
    std::cout << BOLD_GREEN "assignation operator AForm " << this->name << " created" RESET << std::endl;
    if (this not_eq &copy) {
        this->isSigned = copy.isSigned;
    }
    return *this;
}

// get name method
const std::string AForm::getName(void) const {
    return this->name;
}

// get grade sign method
int AForm::getGradeSign(void) const {
    return this->gradeSign;
}

// get grade exec method
int AForm::getGradeExec(void) const {
    return this->gradeExec;
}

// get signed method
bool AForm::getSigned(void) const {
    return this->isSigned;
}

// get target method
std::string AForm::getTarget(void) const {
	return this->target;
}

// beSigned method
void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->gradeSign)
        throw AForm::GradeTooLowException();
    else if (this->isSigned == true)
        std::cout << BOLD_RED << bureaucrat.getName() << " cannot sign " << this->name << " because it is already signed" << RESET << std::endl;
    else {
        std::cout << BOLD_GREEN << bureaucrat.getName() << " signed " << this->name << RESET << std::endl;
        this->isSigned = true;
    }
}

// what method
const char *AForm::GradeTooHighException::what() const throw() {
    return BOLD_RED "Grade too high" RESET;
}

// what method
const char *AForm::GradeTooLowException::what() const throw() {
    return BOLD_RED "Grade too low" RESET;
}

// output stream operator overload
std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << BOLD_BLUE "AForm " << form.getName() << " is signed: " << form.getSigned() << " with grade to sign: " << form.getGradeSign() << " and grade to execute: " << form.getGradeExec() << RESET;
    return out;
}
