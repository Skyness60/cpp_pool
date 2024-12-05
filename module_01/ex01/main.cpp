#include "Zombie.hpp"

void testZombieHorde(int n, const std::string& name) {
	std::cout << YELLOW_BOLD << "===== Testing ZombieHorde with " << n << " zombies named " << name << " =====" << RESET << std::endl;
	Zombie* horde = zombieHorde(n, name);
	for (int i = 0; i < n; i++)
	{
		std::cout << CYAN_BOLD << i + 1 << " : " << RESET;
		horde[i].announce();
	}
	delete[] horde;
	std::cout << RED_BOLD<< "===== Finished testing ZombieHorde with " << n << " zombies named " << name << " =====" << RESET << std::endl << std::endl;
}

int main() {
	testZombieHorde(5, "Walker");
	testZombieHorde(3, "Runner");
	testZombieHorde(10, "");
	return 0;
}