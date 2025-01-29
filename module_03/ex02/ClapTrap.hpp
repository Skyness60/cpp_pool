#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

// include <iostream>
#include <iostream>

// color for the output
#define RESET  "\033[0m"
#define BOLD_RED  "\033[1m\033[31m"      /* Bold Red */
#define BOLD_GREEN  "\033[1m\033[32m"    /* Bold Green */
#define BOLD_YELLOW  "\033[1m\033[33m"   /* Bold Yellow */
#define BOLD_BLUE  "\033[1m\033[34m"     /* Bold Blue */
#define BOLD_MAGENTA  "\033[1m\033[35m"  /* Bold Magenta */
#define BOLD_CYAN  "\033[1m\033[36m"     /* Bold Cyan */
#define BOLD_WHITE  "\033[1m\033[37m"    /* Bold White */

// class ClapTrap
class ClapTrap
{
	// protected attributes
	/*
	* les protected attributs c'est pour que les classes enfants puissent y acceder
	*/
	protected:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackPoints;
	// public methods
	public:
		// constructor with name
		ClapTrap(std::string name);
		// copy constructor
		ClapTrap(const ClapTrap &other);
		// operator overload
		ClapTrap &operator=(const ClapTrap &copy);
		// virtual destructor
		virtual ~ClapTrap();
		// attack method
		void	attack(const std::string& target);
		// take damage method
		void	takeDamage(unsigned int amount);
		// be repaired method
		void	beRepaired(unsigned int amount);
};

#endif // !CLAPTRAP_HPP