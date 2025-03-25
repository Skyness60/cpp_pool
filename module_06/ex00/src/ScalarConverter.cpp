#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static void		charConvert(std::string param) {
	std::cout << BOLD_CYAN << "char: '" << param[0] << "'" << RESET << std::endl;
	std::cout << BOLD_GREEN << "int: " << static_cast<int>(param[0]) << RESET << std::endl;
	std::cout << BOLD_YELLOW << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(param[0]) << "f" << RESET << std::endl;
	std::cout << BOLD_MAGENTA << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(param[0]) << RESET << std::endl;
}

static void		intConvert(std::string param) {
	int	n = atoi(param.c_str());

	if (n < 0 || n > 127)
		std::cout << BOLD_RED << "char: impossible" << RESET << std::endl;
	else if (n < 32 || n == 127)
		std::cout << BOLD_RED << "char: non-displayable" << RESET << std::endl;
	else
		std::cout << BOLD_CYAN << "char: '" << static_cast<char>(n) << "'" << RESET << std::endl;
	std::cout << BOLD_GREEN << "int: " << n << RESET << std::endl;
	std::cout << BOLD_YELLOW << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << RESET << std::endl;
	std::cout << BOLD_MAGENTA << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << RESET << std::endl;
}

static void		floatConvert(std::string param) {
	float	n = atof(param.c_str());

	if (n < 0 || n > 127)
		std::cout << BOLD_RED << "char: impossible" << RESET << std::endl;
	else if (n < 32 || n == 127)
		std::cout << BOLD_RED << "char: non-displayable" << RESET << std::endl;
	else
		std::cout << BOLD_CYAN << "char: '" << static_cast<char>(n) << "'" << RESET << std::endl;
	std::cout << BOLD_GREEN << "int: " << static_cast<int>(n) << RESET << std::endl;
	std::cout << BOLD_YELLOW << "float: " << std::fixed << std::setprecision(1) << n << "f" << RESET << std::endl;
	std::cout << BOLD_MAGENTA << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << RESET << std::endl;
}

static void		doubleConvert(std::string param) {
	double	n = atof(param.c_str());

	if (n < 0 || n > 127)
		std::cout << BOLD_RED << "char: impossible" << RESET << std::endl;
	else if (n < 32 || n == 127)
		std::cout << BOLD_RED << "char: non-displayable" << RESET << std::endl;
	else
		std::cout << BOLD_CYAN << "char: '" << static_cast<char>(n) << "'" << RESET << std::endl;
	std::cout << BOLD_GREEN << "int: " << static_cast<int>(n) << RESET << std::endl;
	std::cout << BOLD_YELLOW << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << RESET << std::endl;
	std::cout << BOLD_MAGENTA << "double: " << std::fixed << std::setprecision(1) << n << RESET << std::endl;
}

static void		minInfConvert() {
	std::cout << BOLD_RED << "char: impossible" << RESET << std::endl;
	std::cout << BOLD_GREEN << "int: impossible" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "float: " << NegativeInfinityFloat << RESET << std::endl;
	std::cout << BOLD_MAGENTA << "double: " << NegativeInfinity << RESET << std::endl;
}

static void		maxInfConvert() {
	std::cout << BOLD_RED << "char: impossible" << RESET << std::endl;
	std::cout << BOLD_RED << "int: impossible" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "float: " << PositiveInfinityFloat << RESET << std::endl;
	std::cout << BOLD_MAGENTA << "double: " << PositiveInfinity << RESET << std::endl;
}

static void		nanConvert() {
	std::cout << BOLD_RED << "char: impossible" << RESET << std::endl;
	std::cout << BOLD_RED << "int: impossible" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "float: " << NotaNumberFloat << RESET << std::endl;
	std::cout << BOLD_MAGENTA << "double: " << NotaNumber << RESET << std::endl;
}

static void		error() {
	std::cout << BOLD_RED << "char: impossible" << RESET << std::endl;
	std::cout << BOLD_RED << "int: impossible" << RESET << std::endl;
	std::cout << BOLD_RED << "float: impossible" << RESET << std::endl;
	std::cout << BOLD_RED << "double: impossible" << RESET << std::endl;
}

static void		checkInput(std::string param) {
	if (std::isprint(param[0]) && !std::isdigit(param[0])) {
		if (param.length() == 1)
			charConvert(param);
		else if (param == "-inf" || param == "-inff")
			minInfConvert();
		else if (param == "+inf" || param == "+inff")
			maxInfConvert();
		else if (param == "nan" || param == "nanf")
			nanConvert();
		else
			error();
	}
	else if (param[param.length() - 1] == 'f') {
		long unsigned int	i = 0;
		while (i < param.length() - 1 && (std::isdigit(param[i]) || param[i] == '.'))
			i++;
		if (i == param.length() - 1)
			floatConvert(param);
		else
			error();
	}
	else if (param.find('.') != std::string::npos) {
		long unsigned int	i = 0;
		while (std::isdigit(param[i]) || param[i] == '.')
			i++;
		if (i == param.length())
			doubleConvert(param);
		else
			error();
	}
	else if (std::isdigit(param[0])) {
		long unsigned int	i = 0;
		while (std::isdigit(param[i]))
			i++;
		if (i == param.length())
			intConvert(param);
		else
			error();
	}
	else
		error();
}

void	ScalarConverter::convert(std::string param) {
	checkInput(param);
}
