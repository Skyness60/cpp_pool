#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>

// int main()
// {
// 	Span sp = Span(5);

// 	sp.addNumber(5);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
// 	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

// 	return 0;
// }

void generate(std::vector<int>& vec, int min, int max) {
	for (size_t i = 0; i < vec.size(); ++i) {
		vec[i] = min + std::rand() % (max - min + 1);
	}
}

int	main()
{
	std::srand(std::time(0));
	Span sp = Span(1000000);
	std::vector<int> vec(1000000);
	generate(vec, 0, 1000000);
	sp.addNumberIterator(vec.begin(), vec.end());
	std::ofstream outFile("output.txt");
	if (outFile.is_open()) {
		std::vector<int> numb = sp.getNumbers();
		for (size_t i = 0; i < numb.size(); ++i) {
			outFile << numb[i] << std::endl;
		}
		outFile.close();
	} else {
		std::cerr << "Unable to open file for writing." << std::endl;
	}
	std::ofstream outFileSort("Sortoutput.txt");
	if (outFileSort.is_open()) {
		std::vector<int> sorted = sp.getSortedNumbers();
		for (size_t i = 0; i < sorted.size(); ++i) {
			outFileSort << sorted[i] << std::endl;
		}
		outFileSort.close();
	} else {
		std::cerr << "Unable to open file for writing." << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	return 0;
}