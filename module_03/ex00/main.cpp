#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	toto("toto");
	ClapTrap	tata("tata");

	toto.attack("tata");
	tata.takeDamage(5);
	tata.beRepaired(5);
	tata.attack("toto");
	toto.takeDamage(100);
	toto.beRepaired(5);
	return 0;
}