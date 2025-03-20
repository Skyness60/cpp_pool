#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
// #include <iomanip>

// int stringToInt(const char* str) {
//     int result = 0;
//     int sign = 1;

//     if (*str == '-') {
//         sign = -1;
//         str++;
//     }

//     while (*str != '\0') {
//         if (*str < '0' || *str > '9') {
//             return 0;
//         }
//         result = result * 10 + (*str - '0');
//         str++;
//     }

//     return sign * result;
// }

// std::string	intToString(int n) {
// 	std::string str;
// 	std::string result;
// 	int sign = 1;

// 	if (n < 0) {
// 		sign = -1;
// 		n = -n;
// 	}
// 	while (n > 0) {
// 		str += n % 10 + '0';
// 		n /= 10;
// 	}
// 	if (sign == -1)
// 		str += '-';
// 	for (int i = str.size() - 1; i >= 0; i--)
// 		result += str[i];
// 	return (result);
// }

// void	clearScreen() {
// 	std::cout << "\033[2J\033[H";
// 	std::cout << "\033[3J";
// 	std::cout.flush();
// }

// std::string truncate(std::string str)
// {
// 	if (str.size() >= 10)
// 		return (str.substr(0, 7) + ".");
// 	return (str);
// }



// int main() {
//     clearScreen();
//     bool isRunning = true;
//     std::string input;
//     int countB = 0;
// 	int	ii = 0;
// 	int countF = 0;
//     std::cout << BOLD_BLUE "Welcome to the Bureaucrat program!" RESET << std::endl;
//     std::pair<std::string, int> dataB[100] = {};
// 	Bureaucrat* bureaucrats[] = {};
//     std::pair<std::string, bool> dataF[100] = {
//         std::make_pair("Form 1", true),
//         std::make_pair("Form 2", false),
//     };
// 	Form* forms[100] = {};
//     while (isRunning)
//     {
//         std::cout << "\033[1;36m" << "╔════════════════════════════════╗" << "\033[0m" << std::endl;
//         std::cout << "\033[1;36m" << "║        Bureaucrat Manager      ║" << "\033[0m" << std::endl;
//         std::cout << "\033[1;36m" << "╠════════════════════════════════╣" << "\033[0m" << std::endl;
//         std::cout << "\033[1;36m" << "║       Status Bureaucrat :      ║" << "\033[0m" << std::endl;
//         std::cout << "\033[1;36m" << "║┌──────────────┬───────────────┐║" << std::endl;
// 		std::cout << "\033[1;36m" << "║|" << std::setw(9) << "Name" << std::setw(6) << "|" << std::setw(10) << "Grade" << "     |║" << "\033[0m" << std::endl;
//         std::cout << "\033[1;36m" << "║├──────────────┼───────────────┤║" << std::endl;
//         for (int i = 0; i < countB; i++) {
//             std::cout << "\033[1;36m" << "║|" << std::setw(10) << truncate(dataB[i].first) << std::setw(5) << "|" << std::setw(8) << dataB[i].second << std::setw(11) << "|║" << "\033[0m" << std::endl;
//             if (i < countB - 1)
//                 std::cout << "\033[1;36m" << "║├──────────────┼───────────────├║" << "\033[0m" << std::endl;
//         }
//         std::cout << "\033[1;36m" << "║└──────────────┴───────────────┘║" << "\033[0m" << std::endl;
//         std::cout << "\033[1;36m" << "║                                ║" << "\033[0m" << std::endl;
//         std::cout << "\033[1;36m" << "║          Status Form :         ║" << "\033[0m" << std::endl;
//         std::cout << "\033[1;36m" << "║┌──────────────┬───────────────┐║" << std::endl;
//         std::cout << "\033[1;36m" << "║|" << std::setw(9) << "Name" << std::setw(6) << "|" << std::setw(10) << "Sign" << "     |║" << "\033[0m" << std::endl;
//         std::cout << "\033[1;36m" << "║├──────────────┼───────────────┤║" << std::endl;
//         for (int i = 0; i < countF; i++) {
//             std::cout << "\033[1;36m" << "║|" << std::setw(10) << truncate(dataF[i].first) << std::setw(5) << "|" << std::setw(8);
//             if (dataF[i].second)
//                 std::cout << "\033[1;36m" << std::setw(8) << "✅"  << std::setw(11) << "|║" << std::endl;
//             else
//                 std::cout << "\033[1;36m" << std::setw(8)  << "❌" << std::setw(11) << "|║" << std::endl;
//             if (i < countF - 1)
//                 std::cout << "\033[1;36m" << "║├──────────────┼───────────────├║" << "\033[0m" << std::endl;
//         }
//         std::cout << "\033[1;36m" << "║└──────────────┴───────────────┘║" << "\033[0m" << std::endl;
//         std::cout << "\033[1;36m" << "╠════════════════════════════════╣" << "\033[0m" << std::endl;
//         std::cout << "\033[1;36m" << "║ \033[1;32m1\033[1;36m    - Create a Bureaucrat     ║" << "\033[0m" << std::endl;
//         std::cout << "\033[1;36m" << "║ \033[1;33m2\033[1;36m    - Create a Form           ║" << "\033[0m" << std::endl;
//         std::cout << "\033[1;36m" << "║ \033[1;34m3\033[1;36m    - Sign a Form             ║" << "\033[0m" << std::endl;
//         std::cout << "\033[1;36m" << "║ \033[1;31m4\033[1;36m    - Exit                    ║" << "\033[0m" << std::endl;
//         std::cout << "\033[1;36m" << "╚════════════════════════════════╝" << "\033[0m" << std::endl;
//         std::cout << "\033[1;36m" << "Enter your choice: " << "\033[0m";
//         getline(std::cin, input);
//         if (std::cin.eof())
//         {
//             isRunning = false;
//             break;
//         }
//         if (input == "1")
//         {
// 			while (true)
// 			{
// 				if (countB >= 100)
// 				{
// 					std::cout << "You have reached the maximum number of bureaucrats" << std::endl;
// 					break ;
// 				}
// 				std::string name;
// 				std::string grade;
// 				std::cout << BOLD_BLUE << "Enter the name of the bureaucrat: " << BOLD_WHITE;
// 				getline(std::cin, name);
// 				if (std::cin.eof())
// 				{
// 					isRunning = false;
// 					break;
// 				}
// 				if (name.empty())
// 				{
// 					std::cout << BOLD_RED << "Name cannot be empty" << RESET << std::endl;
// 					continue ;
// 				}
// 				std::cout << BOLD_BLUE << "Enter the grade of the bureaucrat: " << BOLD_WHITE;
// 				getline(std::cin, grade);
// 				if (grade.empty())
// 				{
// 					std::cout << BOLD_RED << "Grade cannot be empty" << RESET << std::endl;
// 					continue ;
// 				}
// 				grade = grade.substr(0, 3);
// 				if (stringToInt(grade.c_str()) == 0)
// 				{
// 					std::cout << BOLD_RED << "Grade must be a number" << RESET << std::endl;
// 					continue ;
// 				}
// 				try {
// 					bureaucrats[countB] = new Bureaucrat(name, stringToInt(grade.c_str()));
// 					if (!bureaucrats[countB])
// 					{
// 						std::cout << BOLD_RED << "Error creating bureaucrat" << RESET << std::endl;
// 						isRunning = false;
// 						break;
// 					}
// 					dataB[countB].first = bureaucrats[countB]->getName();
// 					dataB[countB].second = bureaucrats[countB]->getGrade();
// 					countB++;
// 					clearScreen();
// 					break;
// 				}
// 				catch (std::exception &e) {
// 					std::cout << BOLD_RED << "Finally Bureaucrat is not created because : " << RESET << std::endl;
// 					std::cout << BOLD_RED << e.what() << RESET << std::endl;
// 				}

// 			}
// 		}
// 		else if (input == "2")
// 		{
// 			while (true)
// 			{
// 				if (countF >= 100)
// 				{
// 					std::cout << "You have reached the maximum number of forms" << std::endl;
// 					break ;
// 				}
// 				std::string name;
// 				std::string grade_sign;
// 				std::string grade_exec;
// 				std::cout << BOLD_BLUE << "Enter the name of the Form: " << BOLD_WHITE;
// 				getline(std::cin, name);
// 				if (std::cin.eof())
// 				{
// 					isRunning = false;
// 					break;
// 				}
// 				if (name.empty())
// 				{
// 					std::cout << BOLD_RED << "Name cannot be empty" << RESET << std::endl;
// 					continue ;
// 				}
// 				std::cout << BOLD_BLUE << "Enter the grade for sign of the Form: " << BOLD_WHITE;
// 				getline(std::cin, grade_sign);
// 				if (grade_sign.empty())
// 				{
// 					std::cout << BOLD_RED << "Grade sign cannot be empty" << RESET << std::endl;
// 					continue ;
// 				}
// 				grade_sign = grade_sign.substr(0, 3);
// 				if (stringToInt(grade_sign.c_str()) == 0)
// 				{
// 					std::cout << BOLD_RED << "Grade sign must be a number" << RESET << std::endl;
// 					continue ;
// 				}
// 				std::cout << BOLD_BLUE << "Enter the grade for exec of the Form: " << BOLD_WHITE;
// 				getline(std::cin, grade_exec);
// 				if (grade_exec.empty())
// 				{
// 					std::cout << BOLD_RED << "Grade exec cannot be empty" << RESET << std::endl;
// 					continue ;
// 				}
// 				grade_exec = grade_exec.substr(0, 3);
// 				if (stringToInt(grade_exec.c_str()) == 0)
// 				{
// 					std::cout << BOLD_RED << "Grade exec must be a number" << RESET << std::endl;
// 					continue ;
// 				}
// 				try {
// 					forms[countF] = new Form(name, stringToInt(grade_sign.c_str()), stringToInt(grade_exec.c_str()));
// 					if (!forms[countF])
// 					{
// 						std::cout << BOLD_RED << "Error creating form" << RESET << std::endl;
// 						isRunning = false;
// 						break;
// 					}
// 					dataF[countF].first = forms[countF]->getName();
// 					dataF[countF].second = false;
// 					countF++;
// 					clearScreen();
// 					break;
// 				}
// 				catch (std::exception &e) {
// 					std::cout << BOLD_RED << "Finally Form is not created because : " << RESET << std::endl;
// 					std::cout << BOLD_RED << e.what() << RESET << std::endl;
// 				}

// 			}
// 		}
//         else if (input == "3")
//         {
// 			clearScreen();
// 			bool isRunningChoiceBureaucrat = true;
// 			if (countB == 0 || countF == 0)
// 			{
// 				std::cout << BOLD_RED << "You need to create at least one bureaucrat and one form" << RESET << std::endl;
// 				continue ;
// 			}
// 			while (isRunningChoiceBureaucrat)
// 			{
// 				std::string index;
// 				int	count = 1;
// 				std::cout << "\033[1;36m" << "╔════════════════════════════════╗" << "\033[0m" << std::endl;
// 				std::cout << "\033[1;36m" << "║       Status Bureaucrat :      ║" << "\033[0m" << std::endl;
// 				std::cout << "\033[1;36m" << "║┌──────────────┬───────────────┐║" << std::endl;
// 				std::cout << "\033[1;36m" << "║|" << std::setw(9) << "Name" << std::setw(6) << "|" << std::setw(10) << "Grade" << "     |║" << "\033[0m" << std::endl;
// 				std::cout << "\033[1;36m" << "║├──────────────┼───────────────┤║" << std::endl;
// 				while (ii < countB) {
// 					std::cout << "\033[1;36m" << "║|" << std::setw(10) << truncate(intToString(count) + " : " + dataB[ii].first) << std::setw(5) << "|" << std::setw(8) << dataB[ii].second << std::setw(11) << "|║" << "\033[0m" << std::endl;
// 					if (ii < countB - 1)
// 						std::cout << "\033[1;36m" << "║├──────────────┼───────────────├║" << "\033[0m" << std::endl;
// 					count++;
// 					ii++;
// 				}
// 				ii = 0;
// 				std::cout << "\033[1;36m" << "║└──────────────┴───────────────┘║" << "\033[0m" << std::endl;
// 				std::cout << "\033[1;36m" << "╠════════════════════════════════╣" << "\033[0m" << std::endl;
// 				std::cout << "\033[1;36m" << "║ \033[1;31mBack\033[1;36m    - Exit                 ║" << "\033[0m" << std::endl;
// 				std::cout << "\033[1;36m" << "╚════════════════════════════════╝" << "\033[0m" << std::endl;

// 				std::cout << "\033[1;36m" << "Enter the index of the bureaucrat you want to sign the form: " << "\033[0m";
// 				getline(std::cin, index);
// 				if (std::cin.eof())
// 				{
// 					clearScreen();
// 					isRunning = false;
// 					isRunningChoiceBureaucrat = false;
// 					break;
// 				}
// 				if (index.empty())
// 				{
// 					clearScreen();
// 					std::cout << BOLD_RED << "Index cannot be empty" << RESET << std::endl;
// 					continue ;
// 				}
// 				if (index == "Back" || index == "back" || index == "BACK")
// 				{
// 					clearScreen();
// 					isRunningChoiceBureaucrat = false;
// 					break ;
// 				}
// 				if (stringToInt(index.c_str()) == 0)
// 				{
// 					clearScreen();
// 					std::cout << BOLD_RED << "Index must be a number" << RESET << std::endl;
// 					continue ;
// 				}
// 				int	indexstring = stringToInt(index.c_str());
// 				if (indexstring < 0 || indexstring > countB)
// 				{
// 					clearScreen();
// 					std::cout << BOLD_RED << "Index out of range" << RESET << std::endl;
// 					continue ;
// 				}
// 				if (indexstring <= countB)
// 				{
// 					clearScreen();
// 					bool isRunningChoiceForm = true;
// 					std::string indexForm;
// 					while (isRunningChoiceForm)
// 					{
// 						int	count = 1;
// 						std::cout << "\033[1;36m" << "╔════════════════════════════════╗" << "\033[0m" << std::endl;
// 						std::cout << "\033[1;36m" << "║          Status Form :         ║" << "\033[0m" << std::endl;
// 						std::cout << "\033[1;36m" << "║┌──────────────┬───────────────┐║" << std::endl;
// 						std::cout << "\033[1;36m" << "║|" << std::setw(9) << "Name" << std::setw(6) << "|" << std::setw(10) << "Sign" << "     |║" << "\033[0m" << std::endl;
// 						std::cout << "\033[1;36m" << "║├──────────────┼───────────────┤║" << std::endl;
// 						for (int i = 0; i < countF; i++) {
// 							if (!dataF[i].second)
// 							{
// 								std::cout << "\033[1;36m" << "║|" << std::setw(10) << truncate(intToString(count) + " : " + dataF[i].first) << std::setw(5) << "|" << std::setw(8);
// 								if (!dataF[i].second)
// 									std::cout << "\033[1;36m" << std::setw(8) << forms[i]->getGradeSign() << std::setw(10) << "|║" << std::endl;
// 								if (i < countF - 1)
// 									std::cout << "\033[1;36m" << "║├──────────────┼───────────────├║" << "\033[0m" << std::endl;
// 							}
// 							count++;
// 						}
// 						std::cout << "\033[1;36m" << "║└──────────────┴───────────────┘║" << "\033[0m" << std::endl;
// 						std::cout << "\033[1;36m" << "╠════════════════════════════════╣" << "\033[0m" << std::endl;
// 						std::cout << "\033[1;36m" << "║ \033[1;31mBack\033[1;36m    - Exit                 ║" << "\033[0m" << std::endl;
// 						std::cout << "\033[1;36m" << "╚════════════════════════════════╝" << "\033[0m" << std::endl;
// 						std::cout << "\033[1;36m" << "Enter the index of the form for sign: " << "\033[0m";
// 						getline(std::cin, indexForm);
// 						if (std::cin.eof())
// 						{
// 							clearScreen();
// 							isRunning = false;
// 							isRunningChoiceBureaucrat = false;
// 							break;
// 						}
// 						if (indexForm.empty())
// 						{
// 							clearScreen();
// 							std::cout << BOLD_RED << "Index cannot be empty" << RESET << std::endl;
// 							continue;
// 						}
// 						if (indexForm == "Back" || indexForm == "back" || indexForm == "BACK")
// 						{
// 							clearScreen();
// 							isRunningChoiceForm = false;
// 							break ;
// 						}
// 						if (stringToInt(indexForm.c_str()) == 0)
// 						{
// 							clearScreen();
// 							std::cout << BOLD_RED << "Index must be a number" << RESET << std::endl;
// 							continue ;
// 						}
// 						int	indexstringF = stringToInt(indexForm.c_str());
// 						if (indexstringF < 0 || indexstringF > countF)
// 						{
// 							clearScreen();
// 							std::cout << BOLD_RED << "Index out of range" << RESET << std::endl;
// 							continue;
// 						}
// 						if (indexstringF <= countF)
// 						{
// 							clearScreen();
// 							try {
// 								bureaucrats[indexstring - 1]->signForm(*forms[indexstringF - 1]);
// 								dataF[indexstringF - 1].second = true;
// 								std::cout << BOLD_GREEN << "Form signed successfully" << RESET << std::endl;
// 								isRunningChoiceForm = false;
// 								break;
// 							}
// 							catch (std::exception &e) {
// 								clearScreen();
// 								std::cout << BOLD_RED << "Finally Form is not signed because : " << RESET << std::endl;
// 								std::cout << BOLD_RED << e.what() << RESET << std::endl;
// 							}
// 						}
// 					}
// 				}
// 			}
//         }
//         else if (input == "4")
//         {
//             clearScreen();
//             isRunning = false;
//             std::cout << BOLD_BLUE "Exiting Bureaucrat. Goodbye!" RESET << std::endl;
//         }
//         else
//             clearScreen();
//     }
// 	for (int i = 0; i < countB; i++)
// 		if (bureaucrats[i])
// 			delete bureaucrats[i];
// 	for (int i = 0; i < countF; i++)
// 		if (forms[i])
// 			delete forms[i];
//     return (0);
// }


int	main()
{
	Bureaucrat b1("b1", 1);
	ShrubberyCreationForm f1("f1");

	b1.signForm(f1);
	b1.executeForm(f1);
	return 0;
}