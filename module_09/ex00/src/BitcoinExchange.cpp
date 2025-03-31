#include "BitcoinExchange.hpp"

// ADataSource
ADataSource::ADataSource(std::ifstream &file, std::map<std::string, double> &data) : file(file), data(data) {}
ADataSource::ADataSource(const ADataSource &copy) : file(copy.file), data(copy.data) {}
ADataSource &ADataSource::operator=(const ADataSource &copy) {
	if (this != &copy) {
		this->data = copy.data;
	}
	return *this;
}
ADataSource::~ADataSource() {
	if (this->file.is_open())
		this->file.close();
}

static void trimCell(std::string &cell) {
    size_t start = cell.find_first_not_of(" \t");
    size_t end = cell.find_last_not_of(" \t");
    if (start == std::string::npos)
        cell = "";
    else
        cell = cell.substr(start, end - start + 1);    
}


bool ADataSource::checkHeader(std::string header, file_type type) {
	char delimiter;
	std::string column1 = "date";
	std::string column2;

	if (type == DATABASE) {
		delimiter = ',';
		column2 = "exchange_rate";
	} else {
		delimiter = '|';
		column2 = "value";
	}

	// Check if the columns are separated by the right character
	if (std::count(header.begin(), header.end(), delimiter) != 1)
		return false;
	std::string header1 = header.substr(0, header.find(delimiter));
	std::string header2 = header.substr(header.find(delimiter) + 1);
	trimCell(header1);
	trimCell(header2);
	trimCell(column1);
	trimCell(column2);
	if (header1 != column1 || header2 != column2)
		return false;
	return true;
}

std::map<std::string, double> ADataSource::getData() const {
	return this->data;
}

void ADataSource::printData(std::map<std::string, double> &data, file_type type) {
	std::ofstream logFile;
	if (type == DATABASE) {
		logFile.open("logDatabase.txt");
	} else {
		logFile.open("logInput.txt");
	}
	if (!logFile.is_open()) {
		throw std::runtime_error("Failed to open log file");
	}
	for (std::map<std::string, double>::const_iterator it = data.begin(); it != data.end(); ++it) {
		logFile << it->first << ": " << it->second << std::endl;
	}
	logFile.close();
}

// BitcoinDatabase
BitcoinDatabase::BitcoinDatabase(std::ifstream &file, std::map<std::string, double> &data) : ADataSource(file, data) {}
BitcoinDatabase::BitcoinDatabase(const BitcoinDatabase &copy) : ADataSource(copy) {}
BitcoinDatabase &BitcoinDatabase::operator=(const BitcoinDatabase &copy) {
	if (this != &copy) {
		ADataSource::operator=(copy);
	}
	return *this;
}
BitcoinDatabase::~BitcoinDatabase() {
	if (this->file.is_open())
		this->file.close();
}
void BitcoinDatabase::openFile(std::ifstream &database, std::map<std::string, double> &data) {
	std::string line;
	std::getline(database, line);
	if (checkHeader(line, DATABASE) == false)
		throw std::runtime_error("Invalid header format in database file");
	while (std::getline(database, line)) {
		std::string key = line.substr(0, line.find(','));
		std::stringstream ss(line.substr(line.find(',') + 1));
		double value;
		ss >> value;
		data[key] = value;
	}
}

// InputDatabase
InputDatabase::InputDatabase(std::ifstream &file, std::map<std::string, double> &data) : ADataSource(file, data) {}

InputDatabase::InputDatabase(const InputDatabase &copy) : ADataSource(copy) {}

InputDatabase &InputDatabase::operator=(const InputDatabase &copy) {
	if (this != &copy) {
		ADataSource::operator=(copy);
	}
	return *this;
}

InputDatabase::~InputDatabase() {
	if (this->file.is_open())
		this->file.close();
}
void InputDatabase::openFile(std::ifstream &database, std::map<std::string, double> &data) {
	std::string line;
	std::getline(database, line);
	if (checkHeader(line, FILENAME) == false)
		throw std::runtime_error("Invalid header format in input file");
	while (std::getline(database, line)) {
		std::string key = line.substr(0, line.find('|'));
		std::stringstream ss(line.substr(line.find('|') + 1));
		double value;
		ss >> value;
		data[key] = value;
	}
}

// BitcoinExchange
BitcoinExchange::BitcoinExchange(std::map<std::string, double> &bitcoinData, std::map<std::string, double> &inputData): inputData(inputData), bitcoinData(bitcoinData) {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : inputData(copy.inputData), bitcoinData(copy.bitcoinData) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
	if (this != &copy) {
		this->inputData = copy.inputData;
		this->bitcoinData = copy.bitcoinData;
	}
	return *this;
}
BitcoinExchange::~BitcoinExchange() {
	// Destructor
	if (this->inputData.size() > 0)
		this->inputData.clear();
	if (this->bitcoinData.size() > 0)
		this->bitcoinData.clear();
}

void BitcoinExchange::processData() {
	for (std::map<std::string, double>::iterator it = this->inputData.begin(); it != this->inputData.end(); ++it) {
		std::string date = it->first;
		double value = it->second;
		std::map<std::string, double>::iterator itBitcoin = this->bitcoinData.lower_bound(date);
		if (itBitcoin != this->bitcoinData.end() && itBitcoin->first == date) {
			double bitcoinValue = itBitcoin->second;
			std::cout << date << " => " << value << " * " << bitcoinValue << " = " << value * bitcoinValue << std::endl;
		} else if (itBitcoin != this->bitcoinData.begin()) {
			--itBitcoin; // Move to the closest previous date
			double bitcoinValue = itBitcoin->second;
			std::cout << date << " => " << value << " * " << bitcoinValue << " = " << value * bitcoinValue << std::endl;
		} else {
			std::cout << date << " => " << value << " * 0.0 = 0.0" << std::endl;
		}
	}
}