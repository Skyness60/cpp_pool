#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

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
#endif // !ZOMBIE_HPP