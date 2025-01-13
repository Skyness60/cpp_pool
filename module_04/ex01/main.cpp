
#include <iostream>
#include <string>
#include <string.h>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void	tests_pointers(void)
{
	// Test Brain deep copy
	Brain	*hector = new Brain();

	{
		Brain	*laura = new Brain();
		laura->setIdea("great idea", 0);
		// With assignement
		*hector = *laura;
		laura->setIdea("another great idea", 0);
		// With copy constructor
		Brain	*thimote = new Brain(*laura);
		laura->setIdea("bad idea", 0);
		std::cout << "Laura 1st idea: " << laura->getIdeas()[0] << std::endl;
		delete laura;
		std::cout << "Thimote 1st idea: " << thimote->getIdeas()[0] << std::endl;
		delete thimote;
	}
	std::cout << "Hector 1st idea: " << hector->getIdeas()[0] << std::endl;
	delete hector;
	std::cout << std::endl << std::endl;

	// Test Cat deep copy
	Cat	*leo = new Cat();

	{
		Cat	*milo = new Cat();
		milo->getBrain()->setIdea("great idea", 0);
		// With assignement
		*leo = *milo;
		milo->getBrain()->setIdea("another great idea", 0);
		// With copy constructor
		Cat	*simba = new Cat(*milo);
		milo->getBrain()->setIdea("bad idea", 0);
		std::cout << "Milo 1st idea: " << milo->getBrain()->getIdeas()[0] << std::endl;
		delete milo;
		std::cout << "Simba 1st idea: " << simba->getBrain()->getIdeas()[0] << std::endl;
		delete simba;
	}
	std::cout << "Leo 1st idea: " << leo->getBrain()->getIdeas()[0] << std::endl;
	delete leo;
	std::cout << std::endl << std::endl;

	// Test Dog deep copy
	Dog	*tom = new Dog();

	{
		Dog	*sumi = new Dog();
		sumi->getBrain()->setIdea("great idea", 0);
		// With assignement
		*tom = *sumi;
		sumi->getBrain()->setIdea("another great idea", 0);
		// With copy constructor
		Dog	*rod = new Dog(*sumi);
		sumi->getBrain()->setIdea("bad idea", 0);
		std::cout << "Sumi 1st idea: " << sumi->getBrain()->getIdeas()[0] << std::endl;
		delete sumi;
		std::cout << "Rod 1st idea: " << rod->getBrain()->getIdeas()[0] << std::endl;
		delete rod;
	}
	std::cout << "Tom 1st idea: " << tom->getBrain()->getIdeas()[0] << std::endl;
	delete tom;
}
void	tests(void)
{
	// Test Brain deep copy
	Brain	hector = Brain();

	{
		Brain	laura = Brain();
		laura.setIdea("great idea", 0);
		// With assignement
		hector = laura;
		laura.setIdea("another great idea", 0);
		// With copy constructor
		Brain	thimote = Brain(laura);
		laura.setIdea("bad idea", 0);
		std::cout << "Laura 1st idea: " << laura.getIdeas()[0] << std::endl;
		std::cout << "Thimote 1st idea: " << thimote.getIdeas()[0] << std::endl;
	}
	std::cout << "Hector 1st idea: " << hector.getIdeas()[0] << std::endl;
	std::cout << std::endl << std::endl;

	// Test Cat deep copy
	Cat	leo = Cat();

	{
		Cat	milo = Cat();
		milo.getBrain()->setIdea("great idea", 0);
		// With assignement
		leo = milo;
		milo.getBrain()->setIdea("another great idea", 0);
		// With copy constructor
		Cat	simba = Cat(milo);
		milo.getBrain()->setIdea("bad idea", 0);
		std::cout << "Milo 1st idea: " << milo.getBrain()->getIdeas()[0] << std::endl;
		std::cout << "Simba 1st idea: " << simba.getBrain()->getIdeas()[0] << std::endl;
	}
	std::cout << "Leo 1st idea: " << leo.getBrain()->getIdeas()[0] << std::endl;
	std::cout << std::endl << std::endl;

	// Test Dog deep copy
	Dog	tom = Dog();

	{
		Dog	sumi = Dog();
		sumi.getBrain()->setIdea("great idea", 0);
		// With assignement
		tom = sumi;
		sumi.getBrain()->setIdea("another great idea", 0);
		// With copy constructor
		Dog	rod = Dog(sumi);
		sumi.getBrain()->setIdea("bad idea", 0);
		std::cout << "Sumi 1st idea: " << sumi.getBrain()->getIdeas()[0] << std::endl;
		std::cout << "Rod 1st idea: " << rod.getBrain()->getIdeas()[0] << std::endl;
	}
	std::cout << "Tom 1st idea: " << tom.getBrain()->getIdeas()[0] << std::endl;
}

int	main(int argc, char *argv[])
{
	if (argc == 2 && !strcmp(argv[1], "tests"))
	{
		std::cout << "RUN TESTS" << std::endl;
		tests();
		std::cout << std::endl << std::endl;
		tests_pointers();
		return 0;
	}
	
	std::cout << "RUN PROGRAM" << std::endl << std::endl;

	#define ANIMAL_NUM 5
	Animal *animals[ANIMAL_NUM];

	// Construct
	for (int cur = 0; cur < ANIMAL_NUM; cur++)
	{
		if (cur % 2)
			animals[cur] = new Cat();
		else
			animals[cur] = new Dog();

		animals[cur]->makeSound();
		animals[cur]->getBrain()->setIdea("Don't know...", 0);
		std::cout << "Idea: " << animals[cur]->getBrain()->getIdeas()[0] << std::endl << std::endl;
	}

	std::cout << std::endl;
	
	// Destruct
	for (int cur = 0; cur < ANIMAL_NUM; cur++)
		delete animals[cur];

	return 0;
}

