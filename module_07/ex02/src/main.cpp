#include "Array.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <cstdlib>

int main()
{
	srand(time(NULL));

	const int count = 5;

	Array<int> a(count);
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = rand() % 100 + 1;

	Array<std::string> c(count);
	c[0] = "John";
	c[1] = "Jim";
	c[2] = "Joe";
	c[3] = "Jack";
	c[4] = "James";

	Array<int> b(a);
	Array<std::string> d(c);

	std::cout << BOLD_CYAN << "+-------+-------+-------+-------+" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "|   a   |   b   |   c   |   d   |" << RESET << std::endl;
	std::cout << BOLD_CYAN << "+-------+-------+-------+-------+" << RESET << std::endl;
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << BOLD_CYAN << "| " << BOLD_GREEN << std::setw(5) << a[i] << RESET << BOLD_CYAN << " | "
				  << BOLD_BLUE << std::setw(5) << b[i] << RESET << BOLD_CYAN << " | "
				  << BOLD_MAGENTA << std::setw(5) << c[i] << RESET << BOLD_CYAN << " | "
				  << BOLD_RED << std::setw(5) << d[i] << RESET << BOLD_CYAN << " |" << std::endl;
	std::cout << BOLD_CYAN << "+-------+-------+-------+-------+" << RESET << std::endl;

	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = a[i] * 2;

	for (unsigned int i = 0; i < c.size(); i++)
		c[i] = c[i].append("_2").data();

	std::cout << std::endl
			  << BOLD_CYAN << "+-------+-------+-----------+-------+" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "|   a   |   b   |     c     |   d   |" << RESET << std::endl;
	std::cout << BOLD_CYAN << "+-------+-------+-----------+-------+" << RESET << std::endl;
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << BOLD_CYAN << "| " << BOLD_GREEN << std::setw(5) << a[i] << RESET << BOLD_CYAN << " | "
				  << BOLD_BLUE << std::setw(5) << b[i] << RESET << BOLD_CYAN << " | "
				  << BOLD_MAGENTA << std::setw(9) << c[i] << RESET << BOLD_CYAN << " | "
				  << BOLD_RED << std::setw(5) << d[i] << RESET << BOLD_CYAN << " |" << std::endl;
	std::cout << BOLD_CYAN << "+-------+-------+-----------+-------+" << RESET << std::endl;

	Array<int> e;

	try
	{
		std::cout << e[0] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << BOLD_RED << e.what() << RESET << std::endl;
	}
}