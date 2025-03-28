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

static void checkSpan(std::vector<int> &numbers)
{
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers");
}

int Span::shortestSpan() {
	// Vérifier que le conteneur contient au moins deux éléments
	checkSpan(numbers);

	// Créer une copie du conteneur et trier les éléments
	std::vector<int> sorted = numbers;
	std::sort(sorted.begin(), sorted.end());

	// Initialiser l'écart minimal à une valeur très élevée
	unsigned int minSpan = 4294967295;

	// Parcourir la liste triée et calculer les écarts entre chaque paire adjacente
	for (size_t i = 1; i < sorted.size(); ++i) {
		unsigned int span = sorted[i] - sorted[i - 1];
		if (span < minSpan) {
			minSpan = span;
		}
	}

	return minSpan;
}


int Span::longestSpan()
{
	checkSpan(numbers);
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
