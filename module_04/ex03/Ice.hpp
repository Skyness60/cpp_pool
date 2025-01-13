#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

class Ice {
	private:

	public:
		Ice();
		Ice(const Ice &other);
		Ice &operator=(const Ice &copy);
		virtual ~Ice();
		
};
#endif