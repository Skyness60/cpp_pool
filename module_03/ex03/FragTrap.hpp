#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

// include <iostream>
#include <iostream>

// include "ClapTrap.hpp" for inheritance
#include "ClapTrap.hpp"

// class FragTrap inherit from ClapTrap
class FragTrap : virtual public ClapTrap {
	// public methods
	public:
		// constructor with name
		FragTrap(std::string name);
		// copy constructor
		FragTrap(const FragTrap &other);
		// operator overload
		FragTrap &operator=(const FragTrap &copy);
		// virtual destructor
		virtual ~FragTrap();
		// high fives guys method only for FragTrap and child
		void	highFivesGuys(void);
};

#endif // !FRAGTRAP_HPP