#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>
#include <string>
#define BLACK_BOLD "\033[1;30m"
#define RED_BOLD "\033[1;31m"
#define GREEN_BOLD "\033[1;32m"
#define YELLOW_BOLD "\033[1;33m"
#define BLUE_BOLD "\033[1;34m"
#define MAGENTA_BOLD "\033[1;35m"
#define CYAN_BOLD "\033[1;36m"
#define WHITE_BOLD "\033[1;37m"
#define RESET "\033[0m"

// class Harl
class Harl {
	// private methods
	private:
		void debug(void);
		void info(void);	
		void warning(void);
		void error(void);
	// public methods
	public:	
		void complain(std::string level);
};
#endif // !HARL_HPP