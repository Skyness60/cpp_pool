#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <cstdlib>
#include <string>

// define color for the output
# define RESET  "\033[0m" /* Reset */
# define BOLD_RED  "\033[1m\033[31m"      /* Bold Red */
# define BOLD_GREEN  "\033[1m\033[32m"    /* Bold Green */
# define BOLD_YELLOW  "\033[1m\033[33m"   /* Bold Yellow */
# define BOLD_BLUE  "\033[1m\033[34m"     /* Bold Blue */
# define BOLD_MAGENTA  "\033[1m\033[35m"  /* Bold Magenta */
# define BOLD_CYAN  "\033[1m\033[36m"     /* Bold Cyan */
# define BOLD_WHITE  "\033[1m\033[37m"    /* Bold White */

class ErrorEOF : public std::exception 
{
public:
    const char* what() const throw() {
        return BOLD_RED "Error: CTRL + D" RESET;
    }
};


class DivisionByZeroException : public std::exception 
{
public:
    const char* what() const throw() {
        return BOLD_RED "Error: division by zero" RESET;
    }
};

class TooMuchNumbersException : public std::exception 
{
public:
    const char* what() const throw() {
        return BOLD_YELLOW "Error: too many operands in expression" RESET;
    }
};

class NotEnoughNumbersException : public std::exception 
{
public:
    const char* what() const throw() {
        return BOLD_YELLOW "Error: not enough operands on stack" RESET;
    }
};

class WrongInputException : public std::exception 
{
public:
    const char* what() const throw() {
        return BOLD_MAGENTA "Error: invalid input; only single-digit numbers and operators +-*/% allowed" RESET;
    }
};

class RPN 
{
    private:
        std::stack<int> stack;
        int result;

    public:
		RPN();
		RPN( RPN const & other) ;
		RPN & operator=( RPN const & other );
		~RPN();
        void performOperation(char op, int firstNB, int secondNB);
        bool isOperator(char c) const;
        void processInput(std::string input);
        void calculate(std::string input);
        void displayStack() const;
        int getResult() const;
};