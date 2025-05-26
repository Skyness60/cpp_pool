#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

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

// Utility functions
bool isValidDate(const std::string &date);
void trimCell(std::string &cell);

class ADataSource {

	protected:
		std::map<std::string, double> data;
		char delimiter;
		std::string expectedHeader1;
		std::string expectedHeader2;
		
		void parseLine(const std::string &line);
		
	public:
		ADataSource(char delim, const std::string &header1, const std::string &header2);
		ADataSource(const ADataSource &copy);
		ADataSource &operator=(const ADataSource &copy);
		virtual ~ADataSource();
		
		bool checkHeader(const std::string &header) const;
		void openFile(const std::string &filename);
		const std::map<std::string, double> &getData() const;
};

class BitcoinDatabase : public ADataSource {
	public:
		BitcoinDatabase();
		BitcoinDatabase(const BitcoinDatabase &copy);
		BitcoinDatabase &operator=(const BitcoinDatabase &copy);
		virtual ~BitcoinDatabase();
};

class InputDatabase : public ADataSource {
	public:
		InputDatabase();
		InputDatabase(const InputDatabase &copy);
		InputDatabase &operator=(const InputDatabase &copy);
		virtual ~InputDatabase();
};

class BitcoinExchange {
	private:
		const std::map<std::string, double> &bitcoinData;
				
		struct ValidationResult {
			bool isValid;
			std::string errorMessage;
			std::string date;
			double value;
			
			ValidationResult() : isValid(false), errorMessage(""), date(""), value(0.0) {}
			ValidationResult(bool valid, const std::string &error, const std::string &d, double v)
				: isValid(valid), errorMessage(error), date(d), value(v) {}
		};
		
		ValidationResult validateLine(const std::string &line) const;
		double findExchangeRate(const std::string &date) const;
		
	public:
		BitcoinExchange(const std::map<std::string, double> &bitcoinData);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		virtual ~BitcoinExchange();
		
		void processData(const std::string& inputFilePath) const;
};

#endif
