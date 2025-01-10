#pragma once
#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string		name;
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap &operator=(const DiamondTrap &copy);
		~DiamondTrap();
		using ScavTrap::attack;
		void	whoAmI();

};
