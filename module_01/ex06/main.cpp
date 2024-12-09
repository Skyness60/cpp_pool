#include "Harl.hpp"

int main(int ac, char **av) {
	Harl harl;
	std::system("clear");
	if (ac != 2)
	{
		harl.complain("INVALID");
		return 1;
	}
	std::string level = av[1];
	harl.complain(level);
	return 0;
}