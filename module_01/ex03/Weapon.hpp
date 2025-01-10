#pragma once
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

// class
class Weapon {
	// Attributes
	private:
		std::string type;
	public:
		// Constructor
		Weapon(std::string type);
		// Deconstructor
		~Weapon();
		// Getters
		std::string getType(void);
		// Setters
		void setType(std::string type);
};
