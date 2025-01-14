#include "Harl.hpp"

int main(int ac, char **av) {
	Harl harl;
	std::cout << "\033[H\033[J";
	if (ac != 2)
	{
		harl.complain("INVALID");
		return 1;
	}
	std::string level = av[1];
	harl.complain(level);
	return 0;
}