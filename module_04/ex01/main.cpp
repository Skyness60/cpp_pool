
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "###  Animal Init ###" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
	Animal* animals[10];
	
	// Create 5 Cats and 5 Dogs
	for (int i = 0; i < 10; i++)
	{
		if (i >= 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	// Set ideas for the first Cat
	for (int i = 0; i < 100; i++)
		((Cat *)animals[0])->getBrain()->setIdea("Idea toto", i);

	// Copy the first Cat
	std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "###  Copy Cat Test ###" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
	Cat copy(*(Cat *)animals[0]);

	std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "###  Animal Test ###" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
	// Display ideas of the copied Cat and the original Cat
	std::cout << BOLD_CYAN << "Ideas of the copied Cat and the original Cat:" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << BOLD_RED << "Copy Cat Idea " << i << ": " << copy.getBrain()->getIdea(i) << RESET << std::endl;
		std::cout << BOLD_MAGENTA << "Original Cat Idea " << i << ": " << ((Cat *)animals[0])->getBrain()->getIdea(i) << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "###  Destructor  ###" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
	// Clean up
	for (int i = 0; i < 10; i++)
		delete animals[i];

	return 0;
}