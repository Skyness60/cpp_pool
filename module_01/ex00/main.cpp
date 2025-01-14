#include "Zombie.hpp"

int main() {
	// Create a Zombie in the heap
    Zombie* heapZombie = newZombie("HeapZombie");
	// Announce the Zombie in the heap
    heapZombie->announce();
	// Delete the Zombie in the heap
    delete heapZombie;
	// Create a Zombie in the stack
    randomChump("StackZombie");
    return 0;
}
