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

class ADataSource {
	protected:
		std::ifstream		&file;
		std::map<std::string, double> &data;
		bool checkHeader(std::string header, file_type type);
	public:
		ADataSource(std::ifstream &file, std::map<std::string, double> &data);
		ADataSource(const ADataSource &copy);
		ADataSource &operator=(const ADataSource &copy);
		virtual ~ADataSource();
		virtual void openFile(std::ifstream &database, std::map<std::string, double> &data) = 0;
		std::map<std::string, double> getData() const;
		void printData(std::map<std::string, double> &data, file_type type);
};

class BitcoinDatabase : public ADataSource {
	public:
		BitcoinDatabase(std::ifstream &file, std::map<std::string, double> &data);
		BitcoinDatabase(const BitcoinDatabase &copy);
		BitcoinDatabase &operator=(const BitcoinDatabase &copy);
		virtual ~BitcoinDatabase();
		void openFile(std::ifstream &database, std::map<std::string, double> &data);
};

class InputDatabase : public ADataSource {
	public:
		InputDatabase(std::ifstream &file, std::map<std::string, double> &data);
		InputDatabase(const InputDatabase &copy);
		InputDatabase &operator=(const InputDatabase &copy);
		virtual ~InputDatabase();
		void openFile(std::ifstream &database, std::map<std::string, double> &data);
};

class BitcoinExchange {
	private:
		std::map<std::string, double> &inputData;
		std::map<std::string, double> &bitcoinData;
	public:
		BitcoinExchange(std::map<std::string, double> &bitcoinData, std::map<std::string, double> &inputData);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		virtual ~BitcoinExchange();
		BitcoinExchange(std::ifstream &file, std::ifstream &database);
		void processData();
};
