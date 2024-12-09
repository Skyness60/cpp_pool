#include "FileReplacer.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./FileReplacer <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	Module01::FileReplacer fileReplacer(av[1], av[2], av[3]);
	std::string contentFile = fileReplacer.readFile();
	std::string newContent = fileReplacer.replaceOccurrences(contentFile);
	fileReplacer.writeFile(newContent);
	return (0);
}