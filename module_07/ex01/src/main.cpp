#include "iter.hpp"

class ComplexType {
	public:
		int value;
	
		ComplexType(int v) : value(v) {}
	
		bool operator<(const ComplexType& other) const {
			return this->value < other.value;
		}
	
		bool operator>(const ComplexType& other) const {
			return this->value > other.value;
		}
	};
	
	std::ostream& operator<<(std::ostream& os, const ComplexType& obj) {
		os << obj.value;
		return os;
}

void	printInt(int const &i) {
	std::cout << BOLD_GREEN << i << RESET << std::endl;
}

void printString(std::string const &s) {
	std::cout << BOLD_GREEN << s << RESET << std::endl;
}

void printComplexType(ComplexType const &c) {
	std::cout << BOLD_GREEN << c.value << RESET << std::endl;
}

int	main()
{
	std::cout << BOLD_BLUE << "********** Test with int **********" << RESET << std::endl;
	int tab[] = { 0, 1, 2, 3, 4 };
	::iter(tab, 5, printInt);
	std::cout << BOLD_BLUE << "********** Test with char **********" << RESET << std::endl;
	std::string tab2[] = { "zero", "one", "two", "three", "four" };
	::iter(tab2, 5, printString);
	std::cout << BOLD_BLUE << "********** Test with ComplexType **********" << RESET << std::endl;
	ComplexType tab3[] = { ComplexType(0), ComplexType(1), ComplexType(2), ComplexType(3), ComplexType(4) };
	::iter(tab3, 5, printComplexType);
	return 0;
}