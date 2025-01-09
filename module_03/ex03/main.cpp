#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <streambuf>
#include <sstream>

int	main_claptrap()
{
	std::cout << "======================================" << std::endl;
	std::cout << "\t Test ClapTrap" << std::endl;
	std::cout << "======================================" << std::endl;
	std::endl(std::cout);
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

int	main_scavtrap()
{
	std::cout << "======================================" << std::endl;
	std::cout << "\t Test ScavTrap" << std::endl;
	std::cout << "======================================" << std::endl;
	std::endl(std::cout);
	ScavTrap	titi("titi");
	ScavTrap	tutu("tutu");
	std::cout << "===================" << std::endl;
	std::cout << "Test attack" << std::endl;
	titi.attack("tutu");
	std::cout << "===================" << std::endl;
	std::cout << "Test takeDamage" << std::endl;
	tutu.takeDamage(5);
	std::cout << "===================" << std::endl;
	std::cout << "Test beRepaired" << std::endl;
	tutu.beRepaired(5);
	std::cout << "===================" << std::endl;
	std::cout << "Test kill titi" << std::endl;
	titi.takeDamage(100);
	std::cout << "===================" << std::endl;
	std::cout << "Test takeDamage titi dead" << std::endl;
	titi.takeDamage(100);
	std::cout << "===================" << std::endl;
	std::cout << "Test attack tutu with titi dead" << std::endl;
	titi.attack("tutu");
	std::cout << "===================" << std::endl;
	std::cout << "Test titi berepaired dead" << std::endl;
	titi.beRepaired(5);
	std::cout << "===================" << std::endl;
	std::cout << "Test tutu berepaired full life" << std::endl;
	tutu.beRepaired(5);
	std::cout << "===================" << std::endl;
	std::cout << "Test tutu berepaired amount > life" << std::endl;
	tutu.takeDamage(5);
	tutu.beRepaired(100);
	std::cout << "===================" << std::endl;
	std::cout << "Test tutu attacks to no energy" << std::endl;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::ostringstream dummyStream;
    std::cout.rdbuf(dummyStream.rdbuf());
	for (int i = 0; i <= 50; i++)
		tutu.attack("titi");
	std::cout.rdbuf(originalBuffer);
	tutu.attack("titi");
	std::cout << "===================" << std::endl;
	std::cout << "Test tutu gardGate" << std::endl;
	tutu.guardGate();
	std::cout << "===================" << std::endl;
	return 0;
}

int	main_fragtrap()
{
	std::cout << "======================================" << std::endl;
	std::cout << "\t Test FragTrap" << std::endl;
	std::cout << "======================================" << std::endl;
	std::endl(std::cout);
	FragTrap	tete("tete");
	FragTrap	tyty("tyty");
	std::cout << "===================" << std::endl;
	std::cout << "Test attack" << std::endl;
	tete.attack("tyty");
	std::cout << "===================" << std::endl;
	std::cout << "Test takeDamage" << std::endl;
	tyty.takeDamage(5);
	std::cout << "===================" << std::endl;
	std::cout << "Test beRepaired" << std::endl;
	tyty.beRepaired(5);
	std::cout << "===================" << std::endl;
	std::cout << "Test kill tete" << std::endl;
	tete.takeDamage(100);
	std::cout << "===================" << std::endl;
	std::cout << "Test takeDamage tete dead" << std::endl;
	tete.takeDamage(100);
	std::cout << "===================" << std::endl;
	std::cout << "Test attack tyty with tete dead" << std::endl;
	tete.attack("tyty");
	std::cout << "===================" << std::endl;
	std::cout << "Test tete berepaired dead" << std::endl;
	tete.beRepaired(5);
	std::cout << "===================" << std::endl;
	std::cout << "Test tyty berepaired full life" << std::endl;
	tyty.beRepaired(5);
	std::cout << "===================" << std::endl;
	std::cout << "Test tyty berepaired amount > life" << std::endl;
	tyty.takeDamage(5);
	tyty.beRepaired(100);
	std::cout << "===================" << std::endl;
	std::cout << "Test tyty attacks to no energy" << std::endl;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::ostringstream dummyStream;
    std::cout.rdbuf(dummyStream.rdbuf());
	for (int i = 0; i <= 100; i++)
		tyty.attack("tete");
	std::cout.rdbuf(originalBuffer);
	tyty.attack("tete");
	std::cout << "===================" << std::endl;
	std::cout << "Test tyty high five" << std::endl;
	tyty.highFivesGuys();
	std::cout << "===================" << std::endl;
	return 0;
}

int	main()
{
	std::cout << "\033[H\033[J";
	main_claptrap();
	main_scavtrap();
	main_fragtrap();
	std::cout << "======================================" << std::endl;
	std::cout << "\t Test DiamondTrap" << std::endl;
	std::cout << "======================================" << std::endl;
	std::endl(std::cout);
	DiamondTrap	monster("monster");
	DiamondTrap	munch("munch");
	std::cout << "===================" << std::endl;
	std::cout << "Test attack" << std::endl;
	monster.attack("munch");
	std::cout << "===================" << std::endl;
	std::cout << "Test takeDamage" << std::endl;
	munch.takeDamage(5);
	std::cout << "===================" << std::endl;
	std::cout << "Test beRepaired" << std::endl;
	munch.beRepaired(5);
	std::cout << "===================" << std::endl;
	std::cout << "Test kill monster" << std::endl;
	monster.takeDamage(100);
	std::cout << "===================" << std::endl;
	std::cout << "Test takeDamage monster dead" << std::endl;
	monster.takeDamage(100);
	std::cout << "===================" << std::endl;
	std::cout << "Test attack munch with monster dead" << std::endl;
	monster.attack("munch");
	std::cout << "===================" << std::endl;
	std::cout << "Test monster berepaired dead" << std::endl;
	monster.beRepaired(5);
	std::cout << "===================" << std::endl;
	std::cout << "Test munch berepaired full life" << std::endl;
	munch.beRepaired(5);
	std::cout << "===================" << std::endl;
	std::cout << "Test munch berepaired amount > life" << std::endl;
	munch.takeDamage(5);
	munch.beRepaired(100);
	std::cout << "===================" << std::endl;
	std::cout << "Test munch attacks to no energy" << std::endl;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::ostringstream dummyStream;
    std::cout.rdbuf(dummyStream.rdbuf());
	for (int i = 0; i <= 50; i++)
		munch.attack("monster");
	std::cout.rdbuf(originalBuffer);
	munch.attack("monster");
	std::cout << "===================" << std::endl;
	std::cout << "Test munch high five" << std::endl;
	munch.highFivesGuys();
	std::cout << "===================" << std::endl;
	std::cout << "Test munch gardGate" << std::endl;
	munch.guardGate();
	std::cout << "===================" << std::endl;
	std::cout << "Test munch whoIam" << std::endl;
	munch.whoAmI();
	std::cout << "===================" << std::endl;
	return 0;
}