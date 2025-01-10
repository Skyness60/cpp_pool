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

// Zombie class declaration
class Zombie {
	// Zombie class attributes
	private:
		std::string name;
	// Zombie class methods
	public:
		// Zombie class constructor
		Zombie(std::string name);
		// Zombie class destructor
		~Zombie();
		// Zombie class announce method
		void announce( void );
};
// Function prototypes
Zombie* newZombie(std::string name);
void randomChump(std::string name);

