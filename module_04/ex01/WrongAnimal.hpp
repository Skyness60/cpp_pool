#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal &operator=(const WrongAnimal &copy);
		virtual ~WrongAnimal();
		void makeSound() const;
};
#endif // !WRONGANIMAL_HPP