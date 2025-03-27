#include "Span.hpp"

Span::Span(unsigned int n) : n(n) {}

Span::~Span() {}

Span::Span(const Span &copy) : n(copy.n), numbers(copy.numbers) {}

Span &Span::operator=(const Span &copy)
{
	if (this not_eq &copy)
	{
		n = copy.n;
		numbers = copy.numbers;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (numbers.size() >= n)
		throw std::runtime_error("Container is full");
	numbers.push_back(number);
}

void Span::addNumberIterator(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	size_t count = std::distance(begin, end);
	if (numbers.size() + count > n)
		throw std::runtime_error("Container is full");

	numbers.reserve(n);
	numbers.insert(numbers.end(), begin, end);
}

int Span::shortestSpan()
{
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers");

	std::vector<int> sorted(numbers); // Copie nécessaire pour trier
	std::sort(sorted.begin(), sorted.end());

	int shortest = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++)
		shortest = std::min(shortest, sorted[i] - sorted[i - 1]);
	return shortest;
}

int Span::longestSpan()
{
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers");

	int minVal = *std::min_element(numbers.begin(), numbers.end());
	int maxVal = *std::max_element(numbers.begin(), numbers.end());

	return maxVal - minVal;
}

std::vector<int> Span::getNumbers()
{
	return numbers;
}

std::vector<int> Span::getSortedNumbers()
{
	std::vector<int> sorted(numbers);
	std::sort(sorted.begin(), sorted.end());
	return sorted;
}