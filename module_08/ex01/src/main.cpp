#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>

void generate(std::vector<int>& vec, int min, int max) {
	for (size_t i = 0; i < vec.size(); ++i) {
		vec[i] = min + std::rand() % (max - min + 1);
	}
}

int	main(int ac, char **av) {
	if (ac not_eq 2) {
		std::cout << BOLD_RED << "Usage: ./span [number]" << RESET << std::endl;
		return 1;
	}
	int n = std::atoi(av[1]);
	if (n < 0) {
		std::cout << BOLD_RED << "Invalid number" << RESET << std::endl;
		return 1;
	}
	std::srand(std::time(0));
	Span sp = Span(n);
	std::vector<int> vec(n);
	generate(vec, 0, n);
	sp.addNumberIterator(vec.begin(), vec.end());
	std::cout << BOLD_GREEN << "Shortest span: " << RESET << sp.shortestSpan() << std::endl;
	std::cout << BOLD_BLUE << "Longest span: " << RESET << sp.longestSpan() << std::endl;
	std::cout << BOLD_YELLOW << "Writing numbers to output.txt and sorted numbers to Sortoutput.txt" << RESET << std::endl;
	std::ofstream outFile("output.txt");
	if (outFile.is_open()) {
		std::vector<int> numb = sp.getNumbers();
		for (size_t i = 0; i < numb.size(); ++i) {
			outFile << numb[i] << std::endl;
		}
		outFile.close();
	} else {
		std::cout << BOLD_RED << "Unable to open file for writing." << RESET << std::endl;
	}
	std::ofstream outFileSort("Sortoutput.txt");
	if (outFileSort.is_open()) {
		std::vector<int> sorted = sp.getSortedNumbers();
		for (size_t i = 0; i < sorted.size(); ++i) {
			outFileSort << sorted[i] << std::endl;
		}
		outFileSort.close();
	} else {
		std::cout << BOLD_RED << "Unable to open file for writing." << RESET << std::endl;
	}
	std::cout << BOLD_GREEN << "Done!" << RESET << std::endl;

	return 0;
}
