#include "Form.hpp"

// constructor
Form::Form(const std::string name, int gradeSign, int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec), isSigned(false) {
    std::cout << BOLD_GREEN "constructor Form " << this->name << " created" RESET << std::endl;
    if (gradeSign < MAX_GRADE or gradeExec < MAX_GRADE)
        throw Form::GradeTooHighException();
    else if (gradeSign > MIN_GRADE or gradeExec > MIN_GRADE)
        throw Form::GradeTooLowException();
}

// copy constructor
Form::Form(const Form &copy) : name(copy.name), gradeSign(copy.gradeSign), gradeExec(copy.gradeExec), isSigned(copy.isSigned)
{
    std::cout << BOLD_GREEN "copy constructor Form " << this->name << " created" RESET << std::endl;
}

// destructor
Form::~Form()
{
    std::cout << BOLD_RED "destructor Form " << this->name << " destroyed" RESET << std::endl;
}

// assignation operator
Form &Form::operator=(const Form &copy) {
    std::cout << BOLD_GREEN "assignation operator Form " << this->name << " created" RESET << std::endl;
    if (this not_eq &copy) {
        this->isSigned = copy.isSigned;
    }
    return *this;
}

// get name method
const std::string Form::getName(void) const {
    return this->name;
}

// get grade sign method
int Form::getGradeSign(void) const {
    return this->gradeSign;
}

// get grade exec method
int Form::getGradeExec(void) const {
    return this->gradeExec;
}

// get signed method
bool Form::getSigned(void) const {
    return this->isSigned;
}

// beSigned method
void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->gradeSign)
        throw Form::GradeTooLowException();
    else if (this->isSigned == true)
        std::cout << BOLD_RED << bureaucrat.getName() << " cannot sign " << this->name << " because it is already signed" << RESET << std::endl;
    else {
        std::cout << BOLD_GREEN << bureaucrat.getName() << " signed " << this->name << RESET << std::endl;
        this->isSigned = true;
    }
}

// what method
const char *Form::GradeTooHighException::what() const throw() {
    return BOLD_RED "Grade too high" RESET;
}

// what method
const char *Form::GradeTooLowException::what() const throw() {
    return BOLD_RED "Grade too low" RESET;
}

// output stream operator overload
std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << BOLD_BLUE "Form " << form.getName() << " is signed: " << form.getSigned() << " with grade to sign: " << form.getGradeSign() << " and grade to execute: " << form.getGradeExec() << RESET;
    return out;
}
