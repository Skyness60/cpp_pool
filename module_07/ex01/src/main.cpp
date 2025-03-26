#include "iter.hpp"

void	printInt(int const &i) {
	std::cout << i << std::endl;
}

int	main()
{
	int tab[] = { 0, 1, 2, 3, 4 };
	::iter(tab, 2, printInt);
	return 0;
}