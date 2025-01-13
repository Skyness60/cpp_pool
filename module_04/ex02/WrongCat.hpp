#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(std::string type);
		WrongCat(const WrongCat &copy);
		WrongCat &operator=(const WrongCat &copy);
		virtual ~WrongCat();
		void makeSound() const;
};
#endif // !WRONGCAT_HPP