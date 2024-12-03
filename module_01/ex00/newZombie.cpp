#include "Zombie.hpp"

// Function to create a new Zombie in the heap
Zombie* newZombie(std::string name) {
    return new Zombie(name);
}
