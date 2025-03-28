#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span {
	private:
		unsigned int n;
		std::vector<int> numbers;
	public:
		Span(unsigned int n);
		~Span();
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		void addNumber(int number);
		void addNumberIterator(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		std::vector<int> getNumbers();
		std::vector<int> getSortedNumbers();
		int longestSpan();
};


// define color for the output
# define RESET  "\033[0m" /* Reset */
# define BOLD_RED  "\033[1m\033[31m"      /* Bold Red */
# define BOLD_GREEN  "\033[1m\033[32m"    /* Bold Green */
# define BOLD_YELLOW  "\033[1m\033[33m"   /* Bold Yellow */
# define BOLD_BLUE  "\033[1m\033[34m"     /* Bold Blue */
# define BOLD_MAGENTA  "\033[1m\033[35m"  /* Bold Magenta */
# define BOLD_CYAN  "\033[1m\033[36m"     /* Bold Cyan */
# define BOLD_WHITE  "\033[1m\033[37m"    /* Bold White */
