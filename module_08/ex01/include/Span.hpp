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