#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
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
		Zombie();
		// Zombie class destructor
		~Zombie();
		// Zombie class announce method
		void announce( void );
		// Setter for the name attribute && default name is "default_name"
		void setName(const std::string& name);
};

// Function prototypes
Zombie* zombieHorde( int N, std::string name );

#endif // !ZOMBIE_HPP