#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "###  Animal Test ###" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "####################" << RESET << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << BOLD_WHITE << "The type : " << j->getType() << " " << RESET << std::endl;
	std::cout << BOLD_WHITE << "The type : " << i->getType() << " " << RESET << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	std::cout << BOLD_YELLOW << "##########################" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "###  Wrong Animal Test ###" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "##########################" << RESET << std::endl;
	const WrongAnimal* metawrong = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	const WrongAnimal* l = new WrongCat("Random cat");
	metawrong->makeSound();
	k->makeSound();
	l->makeSound();

	delete meta;
	delete metawrong;
	delete j;
	delete i;
	delete k;
	delete l;
	return (0);
}