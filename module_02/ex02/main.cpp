#include "Fixed.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <iomanip>

Fixed stringToFixed(const std::string& str) {
	std::istringstream iss(str);
	float value;
	if (iss >> value) {
		return Fixed(value);
	}
	throw std::invalid_argument("Invalid input for Fixed");
}

int precedence(char op) {
	if (op == '+' or op == '-') return 1;
	if (op == '*' or op == '/') return 2;
	return 0;
}

Fixed applyOp(Fixed a, Fixed b, const std::string& op) {
	if (op == "+") return a + b;
	if (op == "-") return a - b;
	if (op == "*") return a * b;
	if (op == "/") {
		if (b == 0) { throw std::invalid_argument("Division by zero is undefined"); }
		return a / b;
	}
	if (op == ">") return a > b ? Fixed(1) : Fixed(0);
	if (op == "<") return a < b ? Fixed(1) : Fixed(0);
	if (op == "==") return a == b ? Fixed(1) : Fixed(0);
	if (op == "!=") return a != b ? Fixed(1) : Fixed(0);
	if (op == "<=") return a <= b ? Fixed(1) : Fixed(0);
	if (op == ">=") return a >= b ? Fixed(1) : Fixed(0);
	
	throw std::invalid_argument("Invalid operator");
}

Fixed evaluateExpression(const std::string& expr) {
	Fixed values[100];
	std::string ops[100];
	int valuesIndex = 0, opsIndex = 0;

	size_t i = 0;
	while (i < expr.length()) {
		if (expr[i] == ' ') {
			++i;
			continue;
		}
		if (expr[i] == '(') {
			ops[opsIndex++] = "(";
		} else if (expr[i] == ')') {
			while (opsIndex > 0 and ops[opsIndex - 1] not_eq "(") {
				Fixed val2 = values[--valuesIndex];
				Fixed val1 = values[--valuesIndex];
				std::string op = ops[--opsIndex];
				values[valuesIndex++] = applyOp(val1, val2, op);
			}
			if (opsIndex == 0) throw std::invalid_argument("Invalid expression: unmatched parentheses");
			--opsIndex;
		} else if (isdigit(expr[i]) or expr[i] == '.') {
			std::string val = "";
			while (i < expr.length() and (isdigit(expr[i]) or expr[i] == '.')) {
				val += expr[i++];
			}
			values[valuesIndex++] = stringToFixed(val);
			continue;
		} else if (expr[i] == '+' or expr[i] == '-' or expr[i] == '*' or expr[i] == '/') {
			std::string op(1, expr[i]);
			while (opsIndex > 0 and precedence(ops[opsIndex - 1][0]) >= precedence(expr[i])) {
				Fixed val2 = values[--valuesIndex];
				Fixed val1 = values[--valuesIndex];
				std::string prevOp = ops[--opsIndex];
				values[valuesIndex++] = applyOp(val1, val2, prevOp);
			}
			ops[opsIndex++] = op;
		} else if (expr.substr(i, 2) == "<=" or expr.substr(i, 2) == ">=" or expr[i] == '>' or expr[i] == '<' or expr.substr(i, 2) == "==" or expr.substr(i, 2) == "not_eq") {
			std::string op;
			if ((expr[i] == '>' and expr[i + 1] not_eq '=') or (expr[i] == '<' and expr[i + 1] not_eq '=') or expr[i] == '=' or expr[i] == '!') {
				op = expr[i];
			} else {
				op = expr.substr(i, 2);
				i++;
			}

			while (opsIndex > 0 and precedence(ops[opsIndex - 1][0]) >= precedence(op[0])) {
				Fixed val2 = values[--valuesIndex];
				Fixed val1 = values[--valuesIndex];
				std::string prevOp = ops[--opsIndex];
				values[valuesIndex++] = applyOp(val1, val2, prevOp);
			}
			ops[opsIndex++] = op;
		}
		++i;
	}

	while (opsIndex > 0) {
		Fixed val2 = values[--valuesIndex];
		Fixed val1 = values[--valuesIndex];
		std::string op = ops[--opsIndex];
		values[valuesIndex++] = applyOp(val1, val2, op);
	}

	if (valuesIndex not_eq 1) throw std::invalid_argument("Invalid expression: too many values");

	return values[0];
}

int main() {
	while (true) {
		std::string input;
		std::cout << "Enter expression (e.g., '42 + 2 * (3 + 5)') or 'exit' to quit: ";
		std::getline(std::cin, input);

		if (input == "exit" or std::cin.eof()) {
			std::cout << "Exiting program." << std::endl;
			break;
		}

		try {
			Fixed result = evaluateExpression(input);
			std::cout << "Result: " << std::fixed << std::setprecision(2) << result.toFloat() << std::endl;

			if (input.find("==") not_eq std::string::npos or input.find("not_eq") not_eq std::string::npos or
				input.find(">") not_eq std::string::npos or input.find("<") not_eq std::string::npos) {
				std::cout << "Comparison result: ";
				if (result.toFloat() == 1) {
					std::cout << "OK" << std::endl;
				} else {
					std::cout << "KO" << std::endl;
				}
			}

		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}

	return 0;
}
// int	main()
// {
// 	std::cout << "===================" << std::endl;
// 	std::cout << "Original main" << std::endl;
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }