#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	try {
		if (ac != 2)
			throw std::invalid_argument("Usage: ./bitcoin [filename]");

		std::ifstream database("data.csv");
		if (!database.is_open())
			throw std::runtime_error("Could not open database file");

		std::ifstream file(av[1]);
		if (!file.is_open())
			throw std::runtime_error("Could not open input file");

		std::map<std::string, double> bitcoinData;
		std::map<std::string, double> inputData;

		BitcoinDatabase bitcoinDatabase(file, bitcoinData);
		std::cout << BOLD_GREEN << "Bitcoin Database:" << RESET << std::endl;
		bitcoinDatabase.openFile(database, bitcoinData);
		bitcoinDatabase.printData(bitcoinData, DATABASE);

		InputDatabase inputDatabase(file, inputData);
		std::cout << BOLD_GREEN << "Input Database:" << RESET << std::endl;
		inputDatabase.openFile(file, inputData);
		inputDatabase.printData(inputData, FILENAME);

		BitcoinExchange bitcoinExchange(bitcoinData, inputData);
		std::cout << BOLD_GREEN << "Bitcoin Exchange:" << RESET << std::endl;
		bitcoinExchange.processData();

	}
	catch (std::exception &e) {
		std::cout << BOLD_RED << "Error: " << BOLD_YELLOW << e.what() << RESET << std::endl;
		return 1;
	}

	return 0;
}