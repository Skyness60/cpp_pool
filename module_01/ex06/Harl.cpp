#include "Harl.hpp"
// private methods
void Harl::debug() {
    std::cout << WHITE_BOLD << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl << "I really do!" << RESET << std::endl;
}

void Harl::info() {
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl << "You didn’t put enough bacon in my burger!" << RESET << std::endl;
}

void Harl::warning() {
    std::cout << WHITE_BOLD << "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming for years!" << RESET << std::endl;
}

void Harl::error() {
    std::cout << WHITE_BOLD << "This is unacceptable, I want to speak to the manager now." << RESET << std::endl;
}

// GetLevel function static
static LogLevel getLevel(const std::string& level) {
	std::pair<std::string, LogLevel> levels[] = {
		std::make_pair("DEBUG", DEBUG),
		std::make_pair("INFO", INFO),
		std::make_pair("WARNING", WARNING),
		std::make_pair("ERROR", ERROR)
	};
	for (int i = 0; i < 4; ++i) {
		while (levels[i].first.compare(level) == 0)
			return levels[i].second;
	}
	return INVALID;
}
// public method
void Harl::complain(std::string level) {
	switch (getLevel(level)) {
		case DEBUG:
			std::cout << BLUE_BOLD << "[ DEBUG ]" << RESET << std::endl;
			this->debug();
			break;
		case INFO:
			std::cout << GREEN_BOLD << "[ INFO ]" << RESET << std::endl;
			this->info();
			break;
		case WARNING:
			std::cout << YELLOW_BOLD << "[ WARNING ]" << RESET << std::endl;
			this->warning();
			break;
		case ERROR:
			std::cout << RED_BOLD << "[ ERROR ]" << RESET << std::endl;
			this->error();
			break;
		default:
			std::cout << MAGENTA_BOLD << "[ Probably complaining about insignificant problems ]" << RESET << std::endl;
			break;
	}
}
