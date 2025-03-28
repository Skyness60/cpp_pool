#include "BitcoinExchange.hpp" 

static void trimCell(std::string &cell) {
    size_t start = cell.find_first_not_of(" \t");
    size_t end = cell.find_last_not_of(" \t");
    if (start == std::string::npos)
        cell = "";
    else
        cell = cell.substr(start, end - start + 1);    
}

static bool checkHeader(std::string header, file_type type) {
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
	// Check if the columns have the right names
	if (header1 != column1 || header2 != column2)
		return false;
	return true;
}

static void loadDatabase(std::ifstream &database, std::map<std::string, double> &data) {
	std::string line;
	std::getline(database, line);
	if (checkHeader(line, DATABASE) == false)
		throw std::runtime_error("Invalid database file format");
	while (std::getline(database, line)) {
		
		std::string key = line.substr(0, line.find(','));
		std::stringstream ss(line.substr(line.find(',') + 1));
		double value;
		ss >> value;
		data[key] = value;
	}
}

BitcoinExchange::BitcoinExchange(std::ifstream &filename, std::ifstream &dataBase) : filename(filename), dataBase(dataBase) {
    loadDatabase(this->dataBase, this->data);
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : filename(copy.filename), dataBase(copy.dataBase), data(copy.data) {
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
	if (this == &copy)
		return *this;
	this->data = copy.data;
	return *this;
}

std::map<std::string, double> BitcoinExchange::getData() const {
	return this->data;
}