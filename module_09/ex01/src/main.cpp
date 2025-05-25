#include "RPN.hpp" 

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << BOLD_RED << "Error: " << RESET << "Usage: " << argv[0] << " <expression>" << std::endl;
        return 1;
    }

    try {
        RPN rpn;
        rpn.processInput(argv[1]);
        rpn.calculate(argv[1]);
    } catch (const std::exception &e) {
        std::cerr << BOLD_RED << "Error: " << RESET << e.what() << std::endl;
        return 1;
    }

    return 0;
}

