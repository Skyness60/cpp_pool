#include "Bureaucrat.hpp"
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
    std::cout << BOLD_BLUE "Welcome to the Bureaucrat program!" RESET << std::endl;
    std::pair<std::string, int> dataB[] = {
        std::make_pair("Bureaucrat 1", 150),
    };
    std::pair<std::string, bool> dataF[] = {
        std::make_pair("Form 1", true),
        std::make_pair("Form 2", false),
    };
    int countB = sizeof(dataB) / sizeof(dataB[0]);
    int countF = sizeof(dataF) / sizeof(dataF[0]);
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
        std::cout << "\033[1;36m" << "║ \033[1;31m4\033[1;36m    - Exit                    ║" << "\033[0m" << std::endl;
        std::cout << "\033[1;36m" << "╚════════════════════════════════╝" << "\033[0m" << std::endl;
        std::cout << "\033[1;36m" << "Enter your choice: " << "\033[0m";
        getline(std::cin, input);
        if (std::cin.eof())
        {
            isRunning = false;
            break;
        }
        // if (input == "1")
        // {
        //     try {
        //         bureaucrat->incrementGrade();
        //         clearScreen();
        //     }
        //     catch (std::exception &e) {
        //         clearScreen();
        //         std::cout << BOLD_RED "Error: " << e.what() << RESET << std::endl;
        //     }
        // }
        // else if (input == "2")
        // {
        //     try {
        //         bureaucrat->decrementGrade();
        //         clearScreen();
        //     }
        //     catch (std::exception &e) {
        //         clearScreen();
        //         std::cout << BOLD_RED "Error: " << e.what() << RESET << std::endl;
        //     }
        // }
        // else if (input == "3")
        // {
        //     clearScreen();
        //     isRunning = false;
        //     std::cout << BOLD_BLUE "Exiting Bureaucrat. Goodbye!" RESET << std::endl;
        // }
        else if (input == "4")
        {
            clearScreen();
            isRunning = false;
            std::cout << BOLD_BLUE "Exiting Bureaucrat. Goodbye!" RESET << std::endl;
        }
        else
            clearScreen();
    }
    return (0);
}