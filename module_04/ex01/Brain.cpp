#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &copy) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy) {
	std::cout << "Brain assignation operator called" << std::endl;
	if (this not_eq &copy)
		*this->ideas = *copy.ideas;
	return *this;
}

const std::string Brain::getIdea(int index) const {
	if (index >= 0 and index < 100)
	{
		if (not this->ideas[index].empty())
			return this->ideas[index];
	}
	return "No idea";
}

const std::string	*Brain::getIdeas(void) const
{
	const std::string	*p_ideas = this->ideas;
	return p_ideas;
}


void Brain::setIdea(std::string idea, int index) {
	if (index >= 0 and index < 100)
		this->ideas[index] = idea;
}

void Brain::setIdeas(const std::string *ideas) {
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ideas[i];
}
