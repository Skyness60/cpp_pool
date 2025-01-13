#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include <string>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &copy);
		~Brain();
		Brain &operator=(const Brain &copy);
		const std::string getIdea(int index) const;
		const std::string	*getIdeas(void) const;
		void setIdea(std::string idea, int index);
		void setIdeas(const std::string *ideas);
};
#endif