#include "RPN.hpp"

RPN::RPN() : stack(), result(0) {}

RPN::RPN(RPN const & other) : stack(other.stack), result(other.result) {}

RPN & RPN::operator=(RPN const & other) {
    if (this != &other) {
        stack = other.stack;
        result = other.result;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::getResult() const {
    return this->result;
}

void RPN::performOperation(char op, int firstNB, int secondNB) {
    switch (op) {
        case '+':
            result = firstNB + secondNB;
            break;
        case '-':
            result = firstNB - secondNB;
            break;
        case '*':
            result = firstNB * secondNB;
            break;
        case '/':
            if (secondNB == 0)
                throw DivisionByZeroException();
            result = firstNB / secondNB;
            break;
        case '%':
            if (secondNB == 0)
                throw DivisionByZeroException();
            result = firstNB % secondNB;
            break;
        default:
            throw WrongInputException();
    }
    std::stack<int> tmp = stack;
    std::stack<int> rev;
    while (!tmp.empty()) { rev.push(tmp.top()); tmp.pop(); }
        std::cout << BOLD_BLUE << "Stack: ";
    while (!rev.empty()) { std::cout << BOLD_WHITE << rev.top() << ' '; rev.pop(); }
    std::cout << BOLD_WHITE << firstNB << ' ' << secondNB << ' ' << op << std::endl;
    std::cout << BOLD_WHITE << "Press Enter to continue..." << std::endl;
    std::string dummy;
    std::getline(std::cin, dummy);
    if (std::cin.eof())
        throw ErrorEOF();
    this->stack.push(result);
    while (!rev.empty()) { std::cout << BOLD_WHITE << rev.top() << ' '; rev.pop(); }
    std::cout << BOLD_MAGENTA << firstNB << ' ' << op << ' ' << secondNB
              << " = " << this->result << std::endl;
}

bool RPN::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

void RPN::processInput(std::string input) {
	for (int i = 0; i < (int)input.size(); i++) {
		if (input[i] > 9)
				throw(NumberSuperiorToNineException());
		else if (input[i] < 0)
				throw(NumberInferiorToZeroException());
		if (isdigit(input[i]) == 0 && isOperator(input[i]) == false && input[i] != ' ')
			throw(WrongInputException());

		if (isdigit(input[i]) != 0 && input[i + 1] && input[i + 1] != ' ')
			throw(WrongInputException());

		if (isOperator(input[i]) && input[i + 1] && input[i + 1] != ' ')
			throw(WrongInputException());
	}
}

void RPN::displayStack() const {
    std::stack<int> tmp = stack;
    std::stack<int> rev;
    while (!tmp.empty()) { rev.push(tmp.top()); tmp.pop(); }
    std::cout << BOLD_BLUE << "Stack: ";
    while (!rev.empty()) { std::cout << BOLD_WHITE << rev.top() << ' '; rev.pop(); }
    std::cout << std::endl;
}

void RPN::calculate(std::string input) {
    for (int i = 0; i < (int)input.size(); i++) {
        while (input[i] && input[i] == ' ')
            i++;

        if (isdigit(input[i]) != 0) {
            int nb = input[i] - '0';
            this->stack.push(nb);
            displayStack();
            std::cout << "Press Enter to continue..." << std::endl;
            std::string dummy;
            std::getline(std::cin, dummy);
            if (std::cin.eof())
                throw ErrorEOF();

        }
        else if (isOperator(input[i])) {
            if (this->stack.size() < 2)
                throw(NotEnoughNumbersException());

            int secondNb = this->stack.top(); this->stack.pop();
            int firstNb  = this->stack.top(); this->stack.pop();
            performOperation(input[i], firstNb, secondNb);
            displayStack();
            std::cout << "Press Enter to continue..." << std::endl;
            std::string dummy;
            std::getline(std::cin, dummy);
            if (std::cin.eof())
                throw ErrorEOF();
        }
    }
    this->result = this->stack.top();
    this->stack.pop();

    if (this->stack.size() != 0)
        throw TooMuchNumbersException();

    std::cout << BOLD_GREEN << "Result: " << this->result << std::endl;
}
