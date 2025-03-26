#include "Array.hpp"

int	main()
{
	Array<int> array(5);
	for (unsigned int i = 0; i < array.size(); i++)
		array[i] = i;
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << array[i] << std::endl;
	try {
		array[5] = 42;
	} catch (std::exception &e) {
		std::cerr << BOLD_RED << e.what() << RESET << std::endl;
	}
	return 0;
}