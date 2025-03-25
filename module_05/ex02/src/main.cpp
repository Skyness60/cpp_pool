#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iomanip>

int stringToInt(const char* str) {
    int result = 0;
    int sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    }

    while (*str != '\0') {
        if (*str < '0' || *str > '9') {
            return 0;
        }
        result = result * 10 + (*str - '0');
        str++;
    }

    return sign * result;
}

std::string	intToString(int n) {
	std::string str;
	std::string result;
	int sign = 1;

	if (n < 0) {
		sign = -1;
		n = -n;
	}
	while (n > 0) {
		str += n % 10 + '0';
		n /= 10;
	}
	if (sign == -1)
		str += '-';
	for (int i = str.size() - 1; i >= 0; i--)
		result += str[i];
	return (result);
}

void	clearScreen() {
	std::cout << "\033[2J\033[H";
	std::cout << "\033[3J";
	std::cout.flush();
}

std::string truncate(std::string str)
{
	if (str.size() >= 10)
		return (str.substr(0, 7) + ".");
	return (str);
}



int main() {
    clearScreen();
    bool isRunning = true;
    std::string input;
    int countB = 0;
	int	ii = 0;
	int countF = 0;
    std::cout << BOLD_BLUE "Welcome to the Bureaucrat program!" RESET << std::endl;
    std::pair<std::string, int> dataB[100] = {};
	Bureaucrat* bureaucrats[100] = {};
    std::pair<std::string, bool> dataF[100] = {};
	AForm* forms[100] = {};
    while (isRunning)
    {
        std::cout << "\033[1;36m" << "╔════════════════════════════════╗" << "\033[0m" << std::endl;
        std::cout << "\033[1;36m" << "║        Bureaucrat Manager      ║" << "\033[0m" << std::endl;
        std::cout << "\033[1;36m" << "╠════════════════════════════════╣" << "\033[0m" << std::endl;
        std::cout << "\033[1;36m" << "║       Status Bureaucrat :      ║" << "\033[0m" << std::endl;
        std::cout << "\033[1;36m" << "║┌──────────────┬───────────────┐║" << std::endl;
		std::cout << "\033[1;36m" << "║|" << std::setw(9) << "Name" << std::setw(6) << "|" << std::setw(10) << "Grade" << "     |║" << "\033[0m" << std::endl;
        std::cout << "\033[1;36m" << "║├──────────────┼───────────────┤║" << std::endl;
        for (int i = 0; i < countB; i++) {
            std::cout << "\033[1;36m" << "║|" << std::setw(10) << truncate(dataB[i].first) << std::setw(5) << "|" << std::setw(8) << dataB[i].second << std::setw(11) << "|║" << "\033[0m" << std::endl;
            if (i < countB - 1)
                std::cout << "\033[1;36m" << "║├──────────────┼───────────────├║" << "\033[0m" << std::endl;
        }
        std::cout << "\033[1;36m" << "║└──────────────┴───────────────┘║" << "\033[0m" << std::endl;
        std::cout << "\033[1;36m" << "║                                ║" << "\033[0m" << std::endl;
        std::cout << "\033[1;36m" << "║          Status Form :         ║" << "\033[0m" << std::endl;
        std::cout << "\033[1;36m" << "║┌──────────────┬───────────────┐║" << std::endl;
        std::cout << "\033[1;36m" << "║|" << std::setw(9) << "Name" << std::setw(6) << "|" << std::setw(10) << "Sign" << "     |║" << "\033[0m" << std::endl;
        std::cout << "\033[1;36m" << "║├──────────────┼───────────────┤║" << std::endl;
        for (int i = 0; i < countF; i++) {
            std::cout << "\033[1;36m" << "║|" << std::setw(10) << truncate(dataF[i].first) << std::setw(5) << "|" << std::setw(8);
            if (dataF[i].second)
                std::cout << "\033[1;36m" << std::setw(8) << "✅"  << std::setw(11) << "|║" << std::endl;
            else
                std::cout << "\033[1;36m" << std::setw(8)  << "❌" << std::setw(11) << "|║" << std::endl;
            if (i < countF - 1)
                std::cout << "\033[1;36m" << "║├──────────────┼───────────────├║" << "\033[0m" << std::endl;
        }
        std::cout << "\033[1;36m" << "║└──────────────┴───────────────┘║" << "\033[0m" << std::endl;
        std::cout << "\033[1;36m" << "╠════════════════════════════════╣" << "\033[0m" << std::endl;
        std::cout << "\033[1;36m" << "║ \033[1;32m1\033[1;36m    - Create a Bureaucrat     ║" << "\033[0m" << std::endl;
        std::cout << "\033[1;36m" << "║ \033[1;33m2\033[1;36m    - Create a Form           ║" << "\033[0m" << std::endl;
        std::cout << "\033[1;36m" << "║ \033[1;34m3\033[1;36m    - Sign a Form             ║" << "\033[0m" << std::endl;
        std::cout << "\033[1;36m" << "║ \033[1;31m4\033[1;36m    - Exec a Form             ║" << "\033[0m" << std::endl;
        std::cout << "\033[1;36m" << "║ \033[1;31m5\033[1;36m    - Exit                    ║" << "\033[0m" << std::endl;
        std::cout << "\033[1;36m" << "╚════════════════════════════════╝" << "\033[0m" << std::endl;
        std::cout << "\033[1;36m" << "Enter your choice: " << "\033[0m";
        getline(std::cin, input);
        if (std::cin.eof())
        {
            isRunning = false;
            break;
        }
        if (input == "1")
        {
			while (true)
			{
				if (countB >= 100)
				{
					std::cout << "You have reached the maximum number of bureaucrats" << std::endl;
					break ;
				}
				std::string name;
				std::string grade;
				std::cout << BOLD_BLUE << "Enter the name of the bureaucrat: " << BOLD_WHITE;
				getline(std::cin, name);
				if (std::cin.eof())
				{
					isRunning = false;
					break;
				}
				if (name.empty())
				{
					std::cout << BOLD_RED << "Name cannot be empty" << RESET << std::endl;
					continue ;
				}
				std::cout << BOLD_BLUE << "Enter the grade of the bureaucrat: " << BOLD_WHITE;
				getline(std::cin, grade);
				if (grade.empty())
				{
					std::cout << BOLD_RED << "Grade cannot be empty" << RESET << std::endl;
					continue ;
				}
				grade = grade.substr(0, 3);
				if (stringToInt(grade.c_str()) == 0)
				{
					std::cout << BOLD_RED << "Grade must be a number" << RESET << std::endl;
					continue ;
				}
				try {
					bureaucrats[countB] = new Bureaucrat(name, stringToInt(grade.c_str()));
					if (!bureaucrats[countB])
					{
						std::cout << BOLD_RED << "Error creating bureaucrat" << RESET << std::endl;
						isRunning = false;
						break;
					}
					dataB[countB].first = bureaucrats[countB]->getName();
					dataB[countB].second = bureaucrats[countB]->getGrade();
					countB++;
					clearScreen();
					break;
				}
				catch (std::exception &e) {
					std::cerr << BOLD_RED << "Finally Bureaucrat is not created because : " << RESET << std::endl;
					std::cerr << BOLD_RED << e.what() << RESET << std::endl;
				}

			}
		}
		else if (input == "2")
		{
			while (true)
			{
				if (countF >= 100)
				{
					std::cout << "You have reached the maximum number of forms" << std::endl;
					break ;
				}
				std::string target;
				std::string type;
				std::cout << BOLD_BLUE << "Enter the target of the Form: " << BOLD_WHITE;
				getline(std::cin, target);
				if (std::cin.eof())
				{
					isRunning = false;
					break;
				}
				if (target.empty())
				{
					std::cout << BOLD_RED << "Target cannot be empty" << RESET << std::endl;
					continue ;
				}
				std::cout << BOLD_BLUE << "Enter the type of the Form (1: ShrubberyCreation, 2: RobotomyRequest, 3: PresidentialPardon): " << BOLD_WHITE;
				getline(std::cin, type);
				if (type.empty())
				{
					std::cout << BOLD_RED << "Type cannot be empty" << RESET << std::endl;
					continue ;
				}
				if (stringToInt(type.c_str()) == 0 || (stringToInt(type.c_str()) < 1 || stringToInt(type.c_str()) > 3))
				{
					std::cout << BOLD_RED << "Invalid type. Please enter 1, 2, or 3." << RESET << std::endl;
					continue ;
				}
				try {
					if (type == "1")
						forms[countF] = new ShrubberyCreationForm(target);
					else if (type == "2")
						forms[countF] = new RobotomyRequestForm(target);
					else if (type == "3")
						forms[countF] = new PresidentialPardonForm(target);

					if (!forms[countF])
					{
						std::cout << BOLD_RED << "Error creating form" << RESET << std::endl;
						isRunning = false;
						break;
					}
					dataF[countF].first = forms[countF]->getName();
					dataF[countF].second = false;
					countF++;
					clearScreen();
					break;
				}
				catch (std::exception &e) {
					std::cerr << BOLD_RED << "Finally Form is not created because : " << RESET << std::endl;
					std::cerr << BOLD_RED << e.what() << RESET << std::endl;
				}

			}
		}
		else if (input == "3")
		{
			clearScreen();
			bool isRunningChoiceBureaucrat = true;
			if (countB == 0 || countF == 0)
			{
				std::cout << BOLD_RED << "You need to create at least one bureaucrat and one form" << RESET << std::endl;
				continue ;
			}
			while (isRunningChoiceBureaucrat)
			{
				std::string index;
				int	count = 1;
				std::cout << "\033[1;36m" << "╔════════════════════════════════╗" << "\033[0m" << std::endl;
				std::cout << "\033[1;36m" << "║       Status Bureaucrat :      ║" << "\033[0m" << std::endl;
				std::cout << "\033[1;36m" << "║┌──────────────┬───────────────┐║" << std::endl;
				std::cout << "\033[1;36m" << "║|" << std::setw(9) << "Name" << std::setw(6) << "|" << std::setw(10) << "Grade" << "     |║" << "\033[0m" << std::endl;
				std::cout << "\033[1;36m" << "║├──────────────┼───────────────┤║" << std::endl;
				while (ii < countB) {
					std::cout << "\033[1;36m" << "║|" << std::setw(10) << truncate(intToString(count) + " : " + dataB[ii].first) << std::setw(5) << "|" << std::setw(8) << dataB[ii].second << std::setw(11) << "|║" << "\033[0m" << std::endl;
					if (ii < countB - 1)
						std::cout << "\033[1;36m" << "║├──────────────┼───────────────├║" << "\033[0m" << std::endl;
					count++;
					ii++;
				}
				ii = 0;
				std::cout << "\033[1;36m" << "║└──────────────┴───────────────┘║" << "\033[0m" << std::endl;
				std::cout << "\033[1;36m" << "╠════════════════════════════════╣" << "\033[0m" << std::endl;
				std::cout << "\033[1;36m" << "║ \033[1;31mBack\033[1;36m    - Exit                 ║" << "\033[0m" << std::endl;
				std::cout << "\033[1;36m" << "╚════════════════════════════════╝" << "\033[0m" << std::endl;

				std::cout << "\033[1;36m" << "Enter the index of the bureaucrat you want to sign the form: " << "\033[0m";
				getline(std::cin, index);
				if (std::cin.eof())
				{
					clearScreen();
					isRunning = false;
					isRunningChoiceBureaucrat = false;
					break;
				}
				if (index.empty())
				{
					clearScreen();
					std::cout << BOLD_RED << "Index cannot be empty" << RESET << std::endl;
					continue ;
				}
				if (index == "Back" || index == "back" || index == "BACK")
				{
					clearScreen();
					isRunningChoiceBureaucrat = false;
					break ;
				}
				if (stringToInt(index.c_str()) == 0)
				{
					clearScreen();
					std::cout << BOLD_RED << "Index must be a number" << RESET << std::endl;
					continue ;
				}
				int	indexstring = stringToInt(index.c_str());
				if (indexstring < 0 || indexstring > countB)
				{
					clearScreen();
					std::cout << BOLD_RED << "Index out of range" << RESET << std::endl;
					continue ;
				}
				if (indexstring <= countB)
				{
					clearScreen();
					bool isRunningChoiceForm = true;
					std::string indexForm;
					while (isRunningChoiceForm)
					{
						int	count = 1;
						std::cout << "\033[1;36m" << "╔════════════════════════════════╗" << "\033[0m" << std::endl;
						std::cout << "\033[1;36m" << "║          Status Form :         ║" << "\033[0m" << std::endl;
						std::cout << "\033[1;36m" << "║┌──────────────┬───────────────┐║" << std::endl;
						std::cout << "\033[1;36m" << "║|" << std::setw(9) << "Name" << std::setw(6) << "|" << std::setw(10) << "Sign" << "     |║" << "\033[0m" << std::endl;
						std::cout << "\033[1;36m" << "║├──────────────┼───────────────┤║" << std::endl;
						for (int i = 0; i < countF; i++) {
							if (!dataF[i].second)
							{
								std::cout << "\033[1;36m" << "║|" << std::setw(10) << truncate(intToString(count) + " : " + dataF[i].first) << std::setw(5) << "|" << std::setw(8);
								if (!dataF[i].second)
									std::cout << "\033[1;36m" << std::setw(8) << forms[i]->getGradeSign() << std::setw(10) << "|║" << std::endl;
								if (i < countF - 1)
									std::cout << "\033[1;36m" << "║├──────────────┼───────────────├║" << "\033[0m" << std::endl;
							}
							count++;
						}
						std::cout << "\033[1;36m" << "║└──────────────┴───────────────┘║" << "\033[0m" << std::endl;
						std::cout << "\033[1;36m" << "╠════════════════════════════════╣" << "\033[0m" << std::endl;
						std::cout << "\033[1;36m" << "║ \033[1;31mBack\033[1;36m    - Exit                 ║" << "\033[0m" << std::endl;
						std::cout << "\033[1;36m" << "╚════════════════════════════════╝" << "\033[0m" << std::endl;
						std::cout << "\033[1;36m" << "Enter the index of the form for sign: " << "\033[0m";
						getline(std::cin, indexForm);
						if (std::cin.eof())
						{
							clearScreen();
							isRunning = false;
							isRunningChoiceBureaucrat = false;
							break;
						}
						if (indexForm.empty())
						{
							clearScreen();
							std::cout << BOLD_RED << "Index cannot be empty" << RESET << std::endl;
							continue;
						}
						if (indexForm == "Back" || indexForm == "back" || indexForm == "BACK")
						{
							clearScreen();
							isRunningChoiceForm = false;
							break ;
						}
						if (stringToInt(indexForm.c_str()) == 0)
						{
							clearScreen();
							std::cout << BOLD_RED << "Index must be a number" << RESET << std::endl;
							continue ;
						}
						int	indexstringF = stringToInt(indexForm.c_str());
						if (indexstringF < 0 || indexstringF > countF)
						{
							clearScreen();
							std::cout << BOLD_RED << "Index out of range" << RESET << std::endl;
							continue;
						}
						if (indexstringF <= countF)
						{
							clearScreen();
							try {
								bureaucrats[indexstring - 1]->signForm(*forms[indexstringF - 1]);
								dataF[indexstringF - 1].second = true;
								std::cout << BOLD_GREEN << "Form signed successfully" << RESET << std::endl;
								isRunningChoiceForm = false;
								break;
							}
							catch (std::exception &e) {
								clearScreen();
								std::cerr << BOLD_RED << "Finally Form is not signed because : " << RESET << std::endl;
								std::cerr << BOLD_RED << e.what() << RESET << std::endl;
							}
						}
					}
				}
			}
        }
		else if (input == "4")
		{
			clearScreen();
			bool isRunningChoiceBureaucrat = true;
			std::string indexForm;
			bool ifFormSigned = false;
			while (isRunningChoiceBureaucrat)
			{
				if (countB == 0 || countF == 0)
				{
					std::cout << BOLD_RED << "You need to create at least one bureaucrat and one form" << RESET << std::endl;
					continue ;
				}
				for (int i = 0; i < countF; i++)
				{
					if (dataF[i].second)
					{
						ifFormSigned = true;
						break ;
					}
				}
				if (!ifFormSigned)
				{
					clearScreen();
					std::cout << BOLD_RED << "You need to sign at least one form" << RESET << std::endl;
					isRunningChoiceBureaucrat = false;
					break ;
				}
				std::string indexForm;
				int	count = 1;
				std::cout << "\033[1;36m" << "╔════════════════════════════════╗" << "\033[0m" << std::endl;
				std::cout << "\033[1;36m" << "║       Status Bureaucrat :      ║" << "\033[0m" << std::endl;
				std::cout << "\033[1;36m" << "║┌──────────────┬───────────────┐║" << std::endl;
				std::cout << "\033[1;36m" << "║|" << std::setw(9) << "Name" << std::setw(6) << "|" << std::setw(10) << "Grade" << "     |║" << "\033[0m" << std::endl;
				std::cout << "\033[1;36m" << "║├──────────────┼───────────────┤║" << std::endl;
				while (ii < countB) {
					std::cout << "\033[1;36m" << "║|" << std::setw(10) << truncate(intToString(count) + " : " + dataB[ii].first) << std::setw(5) << "|" << std::setw(8) << dataB[ii].second << std::setw(11) << "|║" << "\033[0m" << std::endl;
					if (ii < countB - 1)
						std::cout << "\033[1;36m" << "║├──────────────┼───────────────├║" << "\033[0m" << std::endl;
					count++;
					ii++;
				}
				ii = 0;
				std::cout << "\033[1;36m" << "║└──────────────┴───────────────┘║" << "\033[0m" << std::endl;
				std::cout << "\033[1;36m" << "╠════════════════════════════════╣" << "\033[0m" << std::endl;
				std::cout << "\033[1;36m" << "║ \033[1;31mBack\033[1;36m    - Exit                 ║" << "\033[0m" << std::endl;
				std::cout << "\033[1;36m" << "╚════════════════════════════════╝" << "\033[0m" << std::endl;

				std::cout << "\033[1;36m" << "Enter the index of the bureaucrat you want to sign the form: " << "\033[0m";
				getline(std::cin, indexForm);
				if (std::cin.eof())
				{
					clearScreen();
					isRunning = false;
					isRunningChoiceBureaucrat = false;
					break;
				}
				if (indexForm.empty())
				{
					clearScreen();
					std::cout << BOLD_RED << "Index cannot be empty" << RESET << std::endl;
					continue ;
				}
				if (indexForm == "Back" || indexForm == "back" || indexForm == "BACK")
				{
					clearScreen();
					isRunningChoiceBureaucrat = false;
					break ;
				}
				if (stringToInt(indexForm.c_str()) == 0)
				{
					clearScreen();
					std::cout << BOLD_RED << "Index must be a number" << RESET << std::endl;
					continue ;
				}
				int	indexstringB = stringToInt(indexForm.c_str());
				if (indexstringB < 0 || indexstringB > countB)
				{
					clearScreen();
					std::cout << BOLD_RED << "Index out of range" << RESET << std::endl;
					continue ;
				}
				if (indexstringB <= countB)
				{
					clearScreen();
					int	count = 1;
					std::cout << "\033[1;36m" << "╔════════════════════════════════╗" << "\033[0m" << std::endl;
					std::cout << "\033[1;36m" << "║          Status Form :         ║" << "\033[0m" << std::endl;
					std::cout << "\033[1;36m" << "║┌──────────────┬───────────────┐║" << std::endl;
					std::cout << "\033[1;36m" << "║|" << std::setw(9) << "Name" << std::setw(6) << "|" << std::setw(10) << "Exec" << "     |║" << "\033[0m" << std::endl;
					std::cout << "\033[1;36m" << "║├──────────────┼───────────────┤║" << std::endl;
					for (int i = 0; i < countF; i++) {
						if (dataF[i].second)
						{
							std::cout << "\033[1;36m" << "║|" << std::setw(10) << truncate(intToString(count) + " : " + dataF[i].first) << std::setw(5) << "|" << std::setw(8);
							if (dataF[i].second)
								std::cout << "\033[1;36m" << std::setw(8) << forms[i]->getGradeExec() << std::setw(10) << "|║" << std::endl;
							if (i < countF - 1)
								std::cout << "\033[1;36m" << "║├──────────────┼───────────────├║" << "\033[0m" << std::endl;
						}
						count++;
					}
					std::cout << "\033[1;36m" << "║└──────────────┴───────────────┘║" << "\033[0m" << std::endl;
					std::cout << "\033[1;36m" << "╠════════════════════════════════╣" << "\033[0m" << std::endl;
					std::cout << "\033[1;36m" << "║ \033[1;31mBack\033[1;36m    - Exit                 ║" << "\033[0m" << std::endl;
					std::cout << "\033[1;36m" << "╚════════════════════════════════╝" << "\033[0m" << std::endl;
					std::cout << "\033[1;36m" << "Enter the index of the form for sign: " << "\033[0m";
					getline(std::cin, indexForm);
					if (std::cin.eof())
					{
						clearScreen();
						isRunning = false;
						isRunningChoiceBureaucrat = false;
						break;
					}
					if (indexForm.empty())
					{
						clearScreen();
						std::cout << BOLD_RED << "Index cannot be empty" << RESET << std::endl;
						continue;
					}
					if (indexForm == "Back" || indexForm == "back" || indexForm == "BACK")
					{
						clearScreen();
						isRunningChoiceBureaucrat = false;
						break ;
					}
					if (stringToInt(indexForm.c_str()) == 0)
					{
						clearScreen();
						std::cout << BOLD_RED << "Index must be a number" << RESET << std::endl;
						continue ;
					}
					int	indexstringF = stringToInt(indexForm.c_str());
					if (indexstringF < 0 || indexstringF > countF)
					{
						clearScreen();
						std::cout << BOLD_RED << "Index out of range" << RESET << std::endl;
						continue;
					}
					if (indexstringF <= countF)
					{
						clearScreen();
						try {
							bureaucrats[indexstringB - 1]->executeForm(*forms[indexstringF - 1]);
							isRunningChoiceBureaucrat = false;
							break;
						}
						catch (std::exception &e) {
							clearScreen();
							std::cerr << BOLD_RED << "Finally Form is not signed because : " << RESET << std::endl;
							std::cerr << BOLD_RED << e.what() << RESET << std::endl;
						}
					}
				}
				}
		}
        else if (input == "5")
        {
            clearScreen();
            isRunning = false;
            std::cout << BOLD_BLUE "Exiting Bureaucrat. Goodbye!" RESET << std::endl;
        }
        else
            clearScreen();
    }
	for (int i = 0; i < countB; i++)
		if (bureaucrats[i])
			delete bureaucrats[i];
	for (int i = 0; i < countF; i++)
		if (forms[i])
			delete forms[i];
    return (0);
}
