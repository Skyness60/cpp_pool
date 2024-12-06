#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

void main2()
{
	std::cout << "main2 :" << std::endl;
	// HumanA
	{
		// Create a weapon
		Weapon pistolet = Weapon("Pistolet");
		// Create a human with the weapon
		HumanA toto("Toto", pistolet);
		// Attack
		toto.attack();
		// Change the weapon type
		pistolet.setType("AK-47");
		// Attack
		toto.attack();
	}
	// HumanB
	{
		// Create a weapon
		Weapon sabre = Weapon("Sabre");
		// Create a human
		HumanB titi("Titi");
		// Set the weapon
		titi.setWeapon(sabre);
		// Attack
		titi.attack();
		// Change the weapon type
		sabre.setType("Lance roquette");
		// Attack
		titi.attack();
	}
}

int main()
{
	// HumanA
	{
		// Create a weapon
		Weapon club = Weapon("crude spiked club");
		// Create a human with the weapon
		HumanA bob("Bob", club);
		// Attack
		bob.attack();
		// Change the weapon type
		club.setType("some other type of club");
		// Attack
		bob.attack();
	}
	// HumanB
	{
		// Create a weapon
		Weapon club = Weapon("crude spiked club");
		// Create a human
		HumanB jim("Jim");
		// Set the weapon
		jim.setWeapon(club);
		// Attack
		jim.attack();
		// Change the weapon type
		club.setType("some other type of club");
		// Attack
		jim.attack();
	}
	main2();
	return 0;
}
