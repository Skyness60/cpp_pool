#include "FileReplacer.hpp"
#include <iostream>
#include <fstream>

// Constructor
Module01::FileReplacer::FileReplacer(std::string filename, std::string s1, std::string s2)
{
	this->filename = filename;
	this->s1 = s1;
	this->s2 = s2;
	std::cout << "FileReplacer object created." << std::endl;
}

// Destructor
Module01::FileReplacer::~FileReplacer()
{
	std::cout << "FileReplacer object destroyed." << std::endl;
}

// Read file
std::string Module01::FileReplacer::readFile()
{
	std::ifstream file(this->filename.c_str());
	std::string contentFile;
	std::string line;

	if (file.is_open())
	{
		std::cout << "Reading file: " << this->filename << std::endl;
		while (std::getline(file, line))
			contentFile += line + "\n";
		file.close();
		std::cout << "File read successfully." << std::endl;
	}
	else
	{
		std::cout << "Failed to open file: " << this->filename << std::endl;
	}
	return contentFile;
}

// Replace occurrences
std::string Module01::FileReplacer::replaceOccurrences(const std::string& contentFile)
{
	std::string newContent;
	std::string::size_type pos = 0, prevPos = 0;

	std::cout << "Replacing occurrences of \"" << this->s1 << "\" with \"" << this->s2 << "\"." << std::endl;
	while ((pos = contentFile.find(this->s1, pos)) != std::string::npos)
	{
		newContent.append(contentFile, prevPos, pos - prevPos);
		newContent.append(this->s2);
		pos += this->s1.length();
		prevPos = pos;
	}
	newContent.append(contentFile, prevPos, std::string::npos);
	std::cout << "Occurrences replaced successfully." << std::endl;
	return newContent;
}

// Write file
void Module01::FileReplacer::writeFile(const std::string& newContent)
{
	std::ofstream file((this->filename + ".replace").c_str());

	if (file.is_open())
	{
		std::cout << "Writing to file: " << this->filename + ".replace" << std::endl;
		file << newContent;
		file.close();
		std::cout << "File written successfully." << std::endl;
	}
	else
	{
		std::cout << "Failed to open file for writing: " << this->filename + ".replace" << std::endl;
	}
}
