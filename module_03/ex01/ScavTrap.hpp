#ifndef SCAVTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &copy);
		~ScavTrap();
		void	attack(const std::string& target);
		void	guardGate();
};

#endif // !SCAVTRAP_HPP