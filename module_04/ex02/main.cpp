
#include <iostream>
#include <string>
#include <string.h>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"


int	main()
{
	// Dosen't work, because Animal is abstract
	//AAnimal	ani = AAnimal();
	//ani.makeSound();

	AAnimal	*cat = new Cat();
	cat->makeSound();

	// Dosen't work, because Animal is abstract
	//AAnimal	dog = Dog();
	//dog.makeSound();

	delete cat;

	return 0;
}
