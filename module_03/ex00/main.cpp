#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	toto("toto");
	ClapTrap	tata("tata");
	std::cout << "===================" << std::endl;
	std::cout << "Test attack" << std::endl;
	toto.attack("tata");
	std::cout << "===================" << std::endl;
	std::cout << "Test takeDamage" << std::endl;
	tata.takeDamage(5);
	std::cout << "===================" << std::endl;
	std::cout << "Test beRepaired" << std::endl;
	tata.beRepaired(5);
	std::cout << "===================" << std::endl;
	std::cout << "Test kill toto" << std::endl;
	toto.takeDamage(100);
	std::cout << "===================" << std::endl;
	std::cout << "Test takeDamage toto dead" << std::endl;
	toto.takeDamage(100);
	std::cout << "===================" << std::endl;
	std::cout << "Test attack tata with toto dead" << std::endl;
	toto.attack("tata");
	std::cout << "===================" << std::endl;
	std::cout << "Test toto berepaired dead" << std::endl;
	toto.beRepaired(5);
	std::cout << "===================" << std::endl;
	std::cout << "Test tata berepaired full life" << std::endl;
	tata.beRepaired(5);
	std::cout << "===================" << std::endl;
	std::cout << "Test tata berepaired amount > life" << std::endl;
	tata.takeDamage(5);
	tata.beRepaired(100);
	std::cout << "===================" << std::endl;
	std::cout << "Test tata attacks to no energy" << std::endl;
	tata.attack("toto");
	tata.attack("toto");
	tata.attack("toto");
	tata.attack("toto");
	tata.attack("toto");
	tata.attack("toto");
	tata.attack("toto");
	tata.attack("toto");
	tata.attack("toto");
	tata.attack("toto");
	tata.attack("toto");
	std::cout << "===================" << std::endl;
	return 0;
}