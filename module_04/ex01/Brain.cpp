#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
	const	std::string ideas_exemple[] = {
		"I want to eat",
		"I want to sleep",
		"I want to play",
		"I want to work",
		"I want to learn",
		"I want to code",
		"I want to read",
		"I want to watch TV",
		"I want to listen to music",
		"I want to go out",
		"I want to stay home",
		"I want to travel",
		"I want to meet new people",
		"I want to be alone",
		"I want to be with my friends",
		"I want to be with my family",
		"I want to be with my partner",
		"I want to be with my pet",
		"I want to be with my plants",
		"I want to be with my books",
		"I want to be with my computer",
		"I want to be with my phone",
		"I want to be with my TV",
		"I want to be with my music",
		"I want to be with my bed",
		"I want to be with my sofa",
		"I want to be with my chair",
		"I want to be with my table",
		"I want to be with my kitchen",
		"I want to be with my bathroom",
		"I want to be with my living room",
		"I want to be with my bedroom"
	};
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = ideas_exemple[rand() % sizeof(ideas_exemple) / sizeof(std::string)];
	}
}

Brain::Brain(const Brain &copy) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = copy.ideas[i];
	}
	*this = copy;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy) {
	std::cout << "Brain assignation operator called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = copy.ideas[i];
	}
	return *this;
}

std::string Brain::getIdea(int index) const {
	return this->ideas[index];
}