#include "BitcoinExchange.hpp"

void trimCell(std::string &cell) {
    size_t start = cell.find_first_not_of(" \t");
    size_t end = cell.find_last_not_of(" \t");
    if (start == std::string::npos)
        cell = "";
    else
        cell = cell.substr(start, end - start + 1);    
}

bool isValidDate(const std::string &date) {
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	
	for (size_t i = 0; i < date.length(); ++i) {
		if (i != 4 && i != 7 && !std::isdigit(date[i]))
			return false;
	}
	
	int year, month, day;
	year  = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day   = std::atoi(date.substr(8, 2).c_str());
	
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	
	if (month == 2) {
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (isLeap ? 29 : 28))
			return false;
	} else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		return false;
	}
	return true;
}

// ADataSource
ADataSource::ADataSource(char delim, const std::string &header1, const std::string &header2) 
	: delimiter(delim), expectedHeader1(header1), expectedHeader2(header2) {}

ADataSource::ADataSource(const ADataSource &copy)
	: data(copy.data),
	  delimiter(copy.delimiter),
	  expectedHeader1(copy.expectedHeader1),
	  expectedHeader2(copy.expectedHeader2) {}

ADataSource &ADataSource::operator=(const ADataSource &copy) {
	if (this != &copy) {
		delimiter = copy.delimiter;
		expectedHeader1 = copy.expectedHeader1;
		expectedHeader2 = copy.expectedHeader2;
		data = copy.data;
	}
	return *this;
}

ADataSource::~ADataSource() {}

bool ADataSource::checkHeader(const std::string &header) const {
	if (std::count(header.begin(), header.end(), delimiter) != 1)
		return false;
	
	std::string header1 = header.substr(0, header.find(delimiter));
	std::string header2 = header.substr(header.find(delimiter) + 1);
	trimCell(header1);
	trimCell(header2);
	
	return header1 == expectedHeader1 && header2 == expectedHeader2;
}

void ADataSource::parseLine(const std::string &line) {
	size_t delimPos = line.find(delimiter);
	if (delimPos == std::string::npos)
		return;
	
	std::string key = line.substr(0, delimPos);
	std::string valueStr = line.substr(delimPos + 1);
	trimCell(key);
	trimCell(valueStr);
	
	if (!isValidDate(key))
		return;
	
	double value;
	std::stringstream ss(valueStr);
	if (ss >> value && ss.rdbuf()->in_avail() == 0) {
		data[key] = value;
	}
}

void ADataSource::openFile(const std::string &filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Could not open file: " + filename);
	
	std::string line;
	std::getline(file, line);
	if (!checkHeader(line))
		throw std::runtime_error("Invalid header format in file: " + filename);
	
	while (std::getline(file, line)) {
		if (!line.empty()) {
			parseLine(line);
		}
	}
}

const std::map<std::string, double> &ADataSource::getData() const {
	return data;
}

// BitcoinDatabase
BitcoinDatabase::BitcoinDatabase() : ADataSource(',', "date", "exchange_rate") {}

BitcoinDatabase::BitcoinDatabase(const BitcoinDatabase &copy) 
	: ADataSource(copy.delimiter, copy.expectedHeader1, copy.expectedHeader2) {}

BitcoinDatabase &BitcoinDatabase::operator=(const BitcoinDatabase &copy) {
	if (this != &copy) {
		delimiter = copy.delimiter;
		expectedHeader1 = copy.expectedHeader1;
		expectedHeader2 = copy.expectedHeader2;
		data = copy.data;
	}
	return *this;
}

BitcoinDatabase::~BitcoinDatabase() {}

// InputDatabase
InputDatabase::InputDatabase() : ADataSource('|', "date", "value") {}

InputDatabase::InputDatabase(const InputDatabase &copy) 
	: ADataSource(copy.delimiter, copy.expectedHeader1, copy.expectedHeader2) {}

InputDatabase &InputDatabase::operator=(const InputDatabase &copy) {
	if (this != &copy) {
		delimiter = copy.delimiter;
		expectedHeader1 = copy.expectedHeader1;
		expectedHeader2 = copy.expectedHeader2;
		data = copy.data;
	}
	return *this;
}

InputDatabase::~InputDatabase() {}

// BitcoinExchange
BitcoinExchange::BitcoinExchange(const std::map<std::string, double> &bitcoinData) 
	: bitcoinData(bitcoinData) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
	: bitcoinData(copy.bitcoinData) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
	(void)copy;  // suppress unused-parameter warning
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::ValidationResult BitcoinExchange::validateLine(const std::string &line) const {
	ValidationResult result;
	
	size_t pipe = line.find('|');
	if (pipe == std::string::npos) {
		result.errorMessage = "bad input => " + line;
		return result;
	}
	
	std::string date = line.substr(0, pipe);
	std::string valueStr = line.substr(pipe + 1);
	trimCell(date);
	trimCell(valueStr);
	
	if (!isValidDate(date)) {
		result.errorMessage = "bad input => " + line;
		return result;
	}
	
	double value;
	std::stringstream ssVal(valueStr);
	if (!(ssVal >> value) || ssVal.rdbuf()->in_avail() != 0) {
		result.errorMessage = "not a valid number.";
		return result;
	}
	
	if (value < 0) {
		result.errorMessage = "not a positive number.";
		return result;
	}
	
	if (value > 1000) {
		result.errorMessage = "too large a number.";
		return result;
	}
	
	result.isValid = true;
	result.date = date;
	result.value = value;
	return result;
}

double BitcoinExchange::findExchangeRate(const std::string &date) const {
	std::map<std::string, double>::const_iterator it = bitcoinData.lower_bound(date);
	if (it != bitcoinData.end() && it->first == date) {
		return it->second;
	} else if (it != bitcoinData.begin()) {
		--it;
		return it->second;
	}
	throw std::runtime_error("no data available for date: " + date);
}

void BitcoinExchange::processData(const std::string& inputFilePath) const {
	std::ifstream inputFile(inputFilePath.c_str());
	if (!inputFile.is_open()) {
		std::cout << BOLD_RED << "Error: could not open file." << RESET << std::endl;
		return;
	}
	
	std::string line;
	std::getline(inputFile, line);
	
	InputDatabase inputValidator;
	if (!inputValidator.checkHeader(line)) {
		std::cout << BOLD_RED << "Error: Invalid header format in input file." << RESET << std::endl;
		return;
	}
	
	while (std::getline(inputFile, line)) {
		if (line.empty())
			continue;
		
		ValidationResult validation = validateLine(line);
		if (!validation.isValid) {
			std::cout << BOLD_YELLOW << "Error: " << validation.errorMessage << RESET << std::endl;
			continue;
		}
		
		try {
			double exchangeRate = findExchangeRate(validation.date);
			double result = validation.value * exchangeRate;
			
			std::cout << BOLD_GREEN << validation.date << " => " << validation.value 
					  << " = " << result << RESET << std::endl;
		} catch (const std::exception &e) {
			std::cout << BOLD_YELLOW << "Error: " << e.what() << RESET << std::endl;
		}
	}
}
