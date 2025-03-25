#include "Bureaucrat.hpp"

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

int main(int ac, char **av) {
    clearScreen();
    try {
        if (ac not_eq 2)
            throw std::invalid_argument("./bureaucrat [grade]");
    }
    catch (std::exception &e) {
        std::cout << BOLD_RED "Usage: " << e.what() << RESET << std::endl;
        return (1);
    }
    std::string input;
    bool        isRunning = true;
    int         number = stringToInt(av[1]);
    try {
        if (number == 0 and av[1][0] not_eq '0')
            throw std::invalid_argument("Invalid grade");
    }
    catch (std::exception &e) {
        std::cout << BOLD_RED "Error: " << e.what() << RESET << std::endl;
        return (1);
    }
    std::cout << BOLD_BLUE "Welcome to the Bureaucrat program!" RESET << std::endl;
    try {
        Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", stringToInt(av[1]));
        while (isRunning)
        {
            std::cout << "\033[1;36m" << "╔════════════════════════════╗" << "\033[0m" << std::endl;
            std::cout << "\033[1;36m" << "║       Bureaucrat Menu      ║" << "\033[0m" << std::endl;
            std::cout << "\033[1;36m" << "╠════════════════════════════╣" << "\033[0m" << std::endl;
            if (bureaucrat->getGrade() >= 10 and bureaucrat->getGrade() < 100)
                std::cout << "\033[1;36m" << "║ Grade: " << bureaucrat->getGrade() << "                  ║" << "\033[0m" << std::endl;
            else if (bureaucrat->getGrade() < 10)
                std::cout << "\033[1;36m" << "║ Grade: " << bureaucrat->getGrade() << "                   ║" << "\033[0m" << std::endl;
            else if (bureaucrat->getGrade() >= 100)
                std::cout << "\033[1;36m" << "║ Grade: " << bureaucrat->getGrade() << "                 ║" << "\033[0m" << std::endl;
            std::cout << "\033[1;36m" << "╠════════════════════════════╣" << "\033[0m" << std::endl;
            std::cout << "\033[1;36m" << "║ \033[1;32m1\033[1;36m    - Increment           ║" << "\033[0m" << std::endl;
            std::cout << "\033[1;36m" << "║ \033[1;33m2\033[1;36m    - Decrement           ║" << "\033[0m" << std::endl;
            std::cout << "\033[1;36m" << "║ \033[1;31m3\033[1;36m    - Exit                ║" << "\033[0m" << std::endl;
            std::cout << "\033[1;36m" << "╚════════════════════════════╝" << "\033[0m" << std::endl;
            std::cout << "\033[1;36m" << "Enter your choice: " << "\033[0m";
            getline(std::cin, input);
            if (std::cin.eof())
            {
                isRunning = false;
                break;
            }
            if (input == "1")
            {
                try {
                    bureaucrat->incrementGrade();
                    clearScreen();
                }
                catch (std::exception &e) {
                    clearScreen();
                    std::cout << BOLD_RED "Error: " << e.what() << RESET << std::endl;
                }
            }
            else if (input == "2")
            {
                try {
                    bureaucrat->decrementGrade();
                    clearScreen();
                }
                catch (std::exception &e) {
                    clearScreen();
                    std::cout << BOLD_RED "Error: " << e.what() << RESET << std::endl;
                }
            }
            else if (input == "3")
            {
                clearScreen();
                isRunning = false;
                std::cout << BOLD_BLUE "Exiting Bureaucrat. Goodbye!" RESET << std::endl;
            }
            else
                clearScreen();
        }
		delete bureaucrat;
    }
    catch (std::exception &e) {
        std::cout << BOLD_RED "Error: " << e.what() << RESET << std::endl;
    }
    return (0);
}