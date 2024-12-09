#include <iostream>
#include <string>
#include <cstdlib>
#define BLACK_BOLD "\033[1;30m"
#define RED_BOLD "\033[1;31m"
#define GREEN_BOLD "\033[1;32m"
#define YELLOW_BOLD "\033[1;33m"
#define BLUE_BOLD "\033[1;34m"
#define MAGENTA_BOLD "\033[1;35m"
#define CYAN_BOLD "\033[1;36m"
#define WHITE_BOLD "\033[1;37m"
#define RESET "\033[0m"

int	main()
{
	std::system("clear");
	// Create a string
	std::string string = "HI THIS IS BRAIN";
	// Create a pointer to the string
	std::string *stringPTR = &string;
	// Create a reference to the string
	std::string &stringREF = string;
	// Adress
	std::cout << WHITE_BOLD << "Adress :" << RESET << std::endl;
	std::cout << YELLOW_BOLD << "String : " << &string << RESET << std::endl;
	std::cout << BLUE_BOLD << "Pointer of String : " << stringPTR << RESET << std::endl;
	std::cout << GREEN_BOLD << "Reference of String : " << &stringREF << RESET << std::endl;
	// Value
	std::cout << WHITE_BOLD << "Value :" << RESET << std::endl;
	std::cout << YELLOW_BOLD << "String : " <<  string << RESET << std::endl;
	std::cout << BLUE_BOLD << "Pointer of String : " << *stringPTR << RESET << std::endl;
	std::cout << GREEN_BOLD << "Reference of String : " << stringREF << RESET << std::endl;
	return (0);
}