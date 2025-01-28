#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	toto("toto");
	ClapTrap	tata("tata");
	std::cout << BOLD_WHITE << "===================" << RESET << std::endl;
	std::cout << BOLD_BLUE << "Test attack" << RESET << std::endl;
	toto.attack("tata");
	std::cout << BOLD_WHITE << "===================" << RESET << std::endl;
	std::cout << BOLD_BLUE << "Test takeDamage" << RESET << std::endl;
	tata.takeDamage(5);
	std::cout << BOLD_WHITE << "===================" << RESET << std::endl;
	std::cout << BOLD_BLUE << "Test beRepaired" << RESET << std::endl;
	tata.beRepaired(5);
	std::cout << BOLD_WHITE << "===================" << RESET << std::endl;
	std::cout << BOLD_BLUE << "Test kill toto" << RESET << std::endl;
	toto.takeDamage(100);
	std::cout << BOLD_WHITE << "===================" << RESET << std::endl;
	std::cout << BOLD_BLUE << "Test takeDamage toto dead" << RESET << std::endl;
	toto.takeDamage(100);
	std::cout << BOLD_WHITE << "===================" << RESET << std::endl;
	std::cout << BOLD_BLUE << "Test attack tata with toto dead" << RESET << std::endl;
	toto.attack("tata");
	std::cout << BOLD_WHITE << "===================" << RESET << std::endl;
	std::cout << BOLD_BLUE << "Test toto berepaired dead" << RESET << std::endl;
	std::cout << BOLD_WHITE << "===================" << RESET << std::endl;
	toto.beRepaired(5);
	std::cout << BOLD_WHITE << "===================" << RESET << std::endl;
	std::cout << BOLD_BLUE << "Test tata berepaired full life" << RESET << std::endl;
	tata.beRepaired(5);
	std::cout << BOLD_WHITE << "===================" << RESET << std::endl;
	std::cout << BOLD_BLUE << "Test tata berepaired amount > life" << RESET << std::endl;
	tata.takeDamage(5);
	tata.beRepaired(100);
	std::cout << BOLD_WHITE << "===================" << RESET << std::endl;
	std::cout << BOLD_BLUE << "Test tata attacks to no energy" << RESET << std::endl;
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
	std::cout << BOLD_WHITE << "===================" << RESET << std::endl;
	return 0;
}