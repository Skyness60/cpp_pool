#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << BOLD_RED << "Error: " << BOLD_YELLOW << "Usage: ./bitcoin [filename]" << RESET << std::endl;
		return 1;
	}

	try {
		BitcoinDatabase bitcoinDatabase;
		bitcoinDatabase.openFile("data.csv");
		
		BitcoinExchange bitcoinExchange(bitcoinDatabase.getData());
		bitcoinExchange.processData(av[1]);
	}
	catch (const std::exception &e) {
		std::cout << BOLD_RED << "Error: " << BOLD_YELLOW << e.what() << RESET << std::endl;
		return 1;
	}

	return 0;
}