#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>
#include <sys/stat.h>
#include <cstdlib>
#include <iomanip>
#include <stdexcept>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"

// Namespace
namespace Module01
{
	class FileReplacer
	{
		private:
			std::string filename;
			std::string s1;
			std::string s2;
		public:
			FileReplacer(std::string filename, std::string s1, std::string s2);
			~FileReplacer();
			std::string readFile();
			std::string replaceOccurrences(const std::string& contentFile);
			void writeFile(const std::string& newContent);
	};
}
#endif // !FILEREPLACER_HPP