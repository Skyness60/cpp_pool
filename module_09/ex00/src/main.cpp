#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	try {
		if (ac != 2)
			throw std::invalid_argument("Usage: ./bitcoin [filename]");
		std::ifstream database("data.csv");
		if (!database.is_open())
			throw std::runtime_error("Unable to open the database file 'data.csv'");
		if (database.peek() == std::ifstream::traits_type::eof())
			throw std::runtime_error("The database file 'data.csv' is empty");
		if (database.fail())
			throw std::runtime_error("Failed to read the database file 'data.csv'");
		std::ifstream file(av[1]);
		if (!file.is_open())
			throw std::runtime_error("Unable to open the file '" + std::string(av[1]) + "'");
		if (file.peek() == std::ifstream::traits_type::eof())
			throw std::runtime_error("The file '" + std::string(av[1]) + "' is empty");
		if (file.fail())
			throw std::runtime_error("Failed to read the file '" + std::string(av[1]) + "'");
		BitcoinExchange exchange(file, database);
		std::map<std::string, double> data = exchange.getData();
		std::ofstream logFile("logData.csv");
		if (!logFile.is_open())
			throw std::runtime_error("Unable to open the log file 'logData.csv'");
		for (std::map<std::string, double>::const_iterator it = data.begin(); it != data.end(); ++it) {
			logFile << it->first << "," << it->second << std::endl;
		}
		logFile.close();
		database.close();
		file.close();
	}
	catch (std::exception &e) {
		std::cout << BOLD_RED << "Error: " << BOLD_YELLOW << e.what() << RESET << std::endl;
		return 1;
	}

	return 0;
}