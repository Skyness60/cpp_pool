#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

// include <iostream>
#include <iostream>

// include "ScavTrap.hpp" for inheritance
#include "ScavTrap.hpp"

// include "FragTrap.hpp" for inheritance
#include "FragTrap.hpp"

// class DiamondTrap inherit from ScavTrap and FragTrap
class DiamondTrap : public ScavTrap, public FragTrap {
	// private attributes
	private:
		std::string		name;
	public:
		// constructor with name
		DiamondTrap(std::string name);
		// copy constructor
		DiamondTrap(const DiamondTrap &other);
		// operator overload
		DiamondTrap &operator=(const DiamondTrap &copy);
		// virtual destructor
		virtual ~DiamondTrap();
		// use attack method from ScavTrap
		using ScavTrap::attack;
		// whoAmI method only for DiamondTrap
		void	whoAmI();

};

#endif // !DIAMONDTRAP_HPP