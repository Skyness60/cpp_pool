#include "Form.hpp"

// constructor
Form::Form(const std::string name, int gradeSign, int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec), issigned(false) {
    std::cout << BOLD_GREEN "constructor Form " << this->name << " created" RESET << std::endl;
    if (gradeSign < 1 or gradeExec < 1)
        throw Form::GradeTooLowException();
    else if (gradeSign > 150 or gradeExec > 150)
        throw Form::GradeTooHighException();
}

// copy constructor
Form::Form(const Form &copy) : name(copy.name), gradeSign(copy.gradeSign), gradeExec(copy.gradeExec), issigned(copy.issigned)
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
        this->issigned = copy.issigned;
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
    return this->issigned;
}

// beSigned method
void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->gradeSign)
        throw Form::GradeTooLowException();
    this->issigned = true;
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
