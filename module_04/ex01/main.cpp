
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		if (std::string(av[1]) == "1")
		{
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "###  Animal Init ###" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
			Animal* animals[2];
			
			// Create 5 Cats and 5 Dogs
			for (int i = 0; i < 2; i++)
			{
				if (i == 0)
					animals[i] = new Dog();
				else
					animals[i] = new Cat();
			}

			// Set ideas for the first Cat
			for (int i = 0; i < 100; i++)
				((Dog *)animals[0])->getBrain()->setIdea("Idea toto dog waf", i);

			for (int i = 0; i < 100; i++)
				((Cat *)animals[1])->getBrain()->setIdea("Idea toto cat miaou", i);
			// test
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "###  Animal Test ###" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
			// Display ideas of the copied Cat and the original Cat
			std::cout << BOLD_CYAN << "Ideas of the Dog:" << RESET << std::endl;
			for (int i = 0; i < 100; i++)
			{
				std::cout << BOLD_MAGENTA << "Dog Idea " << i << ": " << ((Dog *)animals[0])->getBrain()->getIdea(i) << RESET << std::endl;
			}
			std::cout << std::endl;
			std::cout << BOLD_CYAN << "Ideas of the Cat:" << RESET << std::endl;
			for (int i = 0; i < 100; i++)
				std::cout << BOLD_MAGENTA << "Original Cat Idea " << i << ": " << ((Cat *)animals[1])->getBrain()->getIdea(i) << RESET << std::endl;
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "###  Destructor  ###" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;

			// Clean up
			delete animals[0];
			delete animals[1];
		}
		else if (std::string(av[1]) == "2")
		{
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "###  Animal Init ###" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
			Animal* animals[2];
			
			// Create 5 Cats and 5 Dogs
			for (int i = 0; i < 2; i++)
			{
				if (i == 0)
					animals[i] = new Dog();
				else
					animals[i] = new Cat();
			}

			// Set ideas for the first Cat
			for (int i = 0; i < 100; i++)
				((Dog *)animals[0])->getBrain()->setIdea("Idea toto dog waf", i);

			for (int i = 0; i < 100; i++)
				((Cat *)animals[1])->getBrain()->setIdea("Idea toto cat miaou", i);
			// Copy the first Dog
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "###  Copy Dog Test ###" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
			Dog copydog(*(Dog *)animals[0]);

			// Copy the first Cat
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "###  Copy Cat Test ###" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
			Cat copycat(*(Cat *)animals[1]);
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "###  Animal Test ###" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
			// Display ideas of the copied Cat and the original Cat
			std::cout << BOLD_CYAN << "Ideas of the copied Dog and the original Dog:" << RESET << std::endl;
			for (int i = 0; i < 100; i++)
			{
				std::cout << BOLD_RED << "Copy Dog Idea " << i << ": " << copydog.getBrain()->getIdea(i) << RESET << std::endl;
				std::cout << BOLD_MAGENTA << "Original Dog Idea " << i << ": " << ((Dog *)animals[0])->getBrain()->getIdea(i) << RESET << std::endl;
			}
			std::cout << std::endl;
			std::cout << BOLD_CYAN << "Ideas of the copied Cat and the original Cat:" << RESET << std::endl;
			for (int i = 0; i < 100; i++)
			{
				std::cout << BOLD_RED << "Copy Cat Idea " << i << ": " << copycat.getBrain()->getIdea(i) << RESET << std::endl;
				std::cout << BOLD_MAGENTA << "Original Cat Idea " << i << ": " << ((Cat *)animals[1])->getBrain()->getIdea(i) << RESET << std::endl;
			}
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "###  Destructor  ###" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;

			// Clean up
			delete animals[0];
			delete animals[1];
		}
		else if (std::string(av[1]) == "3")
		{
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "###  Animal Init ###" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
			Animal* animals[2];
			
			// Create 5 Cats and 5 Dogs
			for (int i = 0; i < 2; i++)
			{
				if (i == 0)
					animals[i] = new Dog();
				else
					animals[i] = new Cat();
			}

			// Set ideas for the first Cat
			for (int i = 0; i < 100; i++)
				((Dog *)animals[0])->getBrain()->setIdea("Idea toto dog waf", i);

			for (int i = 0; i < 100; i++)
				((Cat *)animals[1])->getBrain()->setIdea("Idea toto cat miaou", i);
			// Copy the first Dog
			std::cout << BOLD_YELLOW << "##############################" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "###  init copy Animal Test ###" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "##############################" << RESET << std::endl;
			Animal* copyanimals[2];
			copyanimals[0] = new Dog();
			copyanimals[1] = new Cat();

			// Copy the first Dog
			std::cout << BOLD_YELLOW << "#######################" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "###  asign Dog Test ###" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "#######################" << RESET << std::endl;
			*copyanimals[0] = *animals[0];

			// Copy the first Cat
			std::cout << BOLD_YELLOW << "#######################" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "###  asign Cat Test ###" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "#######################" << RESET << std::endl;
			*copyanimals[1] = *animals[1];


			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "###  Animal Test ###" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
			// Display ideas of the copied Cat and the original Cat
			std::cout << BOLD_CYAN << "Ideas of the copied Dog and the original Dog:" << RESET << std::endl;
			for (int i = 0; i < 100; i++)
			{
				std::cout << BOLD_MAGENTA << "Copy asignation Dog Idea " << i << ": " << ((Dog *)copyanimals[0])->getBrain()->getIdea(i) << RESET << std::endl;
				std::cout << BOLD_MAGENTA << "Original Dog Idea " << i << ": " << ((Dog *)animals[0])->getBrain()->getIdea(i) << RESET << std::endl;
			}
			std::cout << std::endl;
			std::cout << BOLD_CYAN << "Ideas of the copied Cat and the original Cat:" << RESET << std::endl;
			for (int i = 0; i < 100; i++)
			{
				std::cout << BOLD_MAGENTA << "Copy asignation Idea " << i << ": " << ((Cat *)copyanimals[1])->getBrain()->getIdea(i) << RESET << std::endl;
				std::cout << BOLD_MAGENTA << "Original Cat Idea " << i << ": " << ((Cat *)animals[1])->getBrain()->getIdea(i) << RESET << std::endl;
			}
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "###  Destructor  ###" << RESET << std::endl;
			std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;

			// Clean up
			delete animals[0];
			delete copyanimals[0];
			delete animals[1];
			delete copyanimals[1];
		}
		else
		{
			std::cout << BOLD_RED << "Error: Invalid argument" << RESET << std::endl;
		}
	}
	else
	{
		std::cout << BOLD_RED << "Error: Invalid number of arguments" << RESET << std::endl;
	}


	return 0;
}