#include "FileReplacer.hpp"

// Constructor
Module01::FileReplacer::FileReplacer(std::string filename, std::string s1, std::string s2)
{
	this->filename = filename;
	this->s1 = s1;
	this->s2 = s2;
	std::cout << GREEN << BOLD << "FileReplacer object created." << RESET << std::endl;
}

// Destructor
Module01::FileReplacer::~FileReplacer()
{
	std::cout << RED << BOLD << "FileReplacer object destroyed." << RESET << std::endl;
}

// Read file
std::string Module01::FileReplacer::readFile()
{
	std::clock_t start = std::clock();
	std::ifstream file(this->filename.c_str());
	std::string contentFile;
	std::string line;

	if (file.is_open())
	{
		std::cout << BLUE << BOLD << "Reading file: " << this->filename << RESET << std::endl;
		while (std::getline(file, line))
			contentFile += line + "\n";
		file.close();
		std::cout << GREEN << BOLD << "File read successfully." << RESET << std::endl;
	}
	else
	{
		std::cout << RED << BOLD << "Failed to open file: " << this->filename << RESET << std::endl;
	}
	std::clock_t end = std::clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << YELLOW << BOLD << "Time taken to read file: " << duration << " seconds." << RESET << std::endl;
	return contentFile;
}

// Replace occurrences
std::string Module01::FileReplacer::replaceOccurrences(const std::string& contentFile)
{
	std::clock_t start = std::clock();
	std::string newContent;
	std::string::size_type pos = 0, prevPos = 0;

	std::cout << BLUE << BOLD << "Replacing occurrences of \"" << this->s1 << "\" with \"" << this->s2 << "\"." << RESET << std::endl;
	while ((pos = contentFile.find(this->s1, pos)) != std::string::npos)
	{
		newContent.append(contentFile, prevPos, pos - prevPos);
		newContent.append(this->s2);
		pos += this->s1.length();
		prevPos = pos;
	}
	newContent.append(contentFile, prevPos, std::string::npos);
	std::cout << GREEN << BOLD << "Occurrences replaced successfully." << RESET << std::endl;
	std::clock_t end = std::clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << YELLOW << BOLD << "Time taken to replace occurrences: " << duration << " seconds." << RESET << std::endl;
	return newContent;
}

// Write file
void Module01::FileReplacer::writeFile(const std::string& newContent)
{
	std::clock_t start = std::clock();
	std::ofstream file((this->filename + ".replace").c_str());

	if (file.is_open())
	{
		std::cout << BLUE << BOLD << "Writing to file: " << this->filename + ".replace" << RESET << std::endl;
		file << newContent;
		file.close();
		std::cout << GREEN << BOLD << "File written successfully." << RESET << std::endl;
	}
	else
	{
		std::cout << RED << BOLD << "Failed to open file for writing: " << this->filename + ".replace" << RESET << std::endl;
	}
	std::clock_t end = std::clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << YELLOW << BOLD << "Time taken to write file: " << duration << " seconds." << RESET << std::endl;
}