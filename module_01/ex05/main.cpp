#include "Harl.hpp"

int main() {
	Harl harl;

	std::cout << BLUE_BOLD << "Complaining at DEBUG level:" << WHITE_BOLD << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	std::cout << GREEN_BOLD << "Complaining at INFO level:" << WHITE_BOLD << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	std::cout << YELLOW_BOLD << "Complaining at WARNING level:" << WHITE_BOLD << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	std::cout << RED_BOLD << "Complaining at ERROR level:" << WHITE_BOLD << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	std::cout << MAGENTA_BOLD << "Complaining at INVALID level:" << WHITE_BOLD << std::endl;
	harl.complain("INVALID");
	std::cout << RESET;
	return 0;
}