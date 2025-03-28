#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <string>
#include <sstream>
#include <stdexcept>

// define color for the output
# define RESET  "\033[0m" /* Reset */
# define BOLD_RED  "\033[1m\033[31m"      /* Bold Red */
# define BOLD_GREEN  "\033[1m\033[32m"    /* Bold Green */
# define BOLD_YELLOW  "\033[1m\033[33m"   /* Bold Yellow */
# define BOLD_BLUE  "\033[1m\033[34m"     /* Bold Blue */
# define BOLD_MAGENTA  "\033[1m\033[35m"  /* Bold Magenta */
# define BOLD_CYAN  "\033[1m\033[36m"     /* Bold Cyan */
# define BOLD_WHITE  "\033[1m\033[37m"    /* Bold White */

enum file_type {
	DATABASE,
	FILENAME
};

class BitcoinExchange {
	private:
		std::ifstream &filename;
		std::ifstream &dataBase;
		std::map<std::string, double> data;
	public:
		BitcoinExchange(std::ifstream &filename, std::ifstream &dataBase);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		std::map<std::string, double> getData() const;
		



};