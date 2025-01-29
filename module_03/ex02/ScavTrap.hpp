#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
// include <iostream>
#include <iostream>

// include "ClapTrap.hpp" for inheritance
#include "ClapTrap.hpp"

// class ScavTrap inherit from ClapTrap
class ScavTrap : public ClapTrap {
	// public methods
	public:
		// constructor with name
		ScavTrap(std::string name);
		// copy constructor
		ScavTrap(const ScavTrap &other);
		// operator overload
		ScavTrap &operator=(const ScavTrap &copy);
		// virtual destructor
		virtual ~ScavTrap();
		// attack method redefined
		void	attack(const std::string& target);
		// guard gate method only for ScavTrap
		void	guardGate();
};

#endif // !SCAVTRAP_HPP