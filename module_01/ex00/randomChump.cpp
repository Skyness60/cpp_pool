#include "Zombie.hpp"

// Function to create a new Zombie in the stack
void randomChump(std::string name) {
    Zombie temp(name);
    temp.announce();
}
