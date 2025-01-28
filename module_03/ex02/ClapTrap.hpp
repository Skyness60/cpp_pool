#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
#define RESET  "\033[0m"
#define BOLD_RED  "\033[1m\033[31m"      /* Bold Red */
#define BOLD_GREEN  "\033[1m\033[32m"    /* Bold Green */
#define BOLD_YELLOW  "\033[1m\033[33m"   /* Bold Yellow */
#define BOLD_BLUE  "\033[1m\033[34m"     /* Bold Blue */
#define BOLD_MAGENTA  "\033[1m\033[35m"  /* Bold Magenta */
#define BOLD_CYAN  "\033[1m\033[36m"     /* Bold Cyan */
#define BOLD_WHITE  "\033[1m\033[37m"    /* Bold White */
class ClapTrap
{
	protected:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackPoints;
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &copy);
		virtual ~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif // !CLAPTRAP_HPP