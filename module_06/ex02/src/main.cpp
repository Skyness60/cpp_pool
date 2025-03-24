#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	int random = std::rand() % 3;
	if (random == 0) {
		std::cout << BOLD_GREEN << "A created" << RESET << std::endl;
		return new A();
	} else if (random == 1) {
		std::cout << BOLD_GREEN << "B created" << RESET << std::endl;
		return new B();
	} else {
		std::cout << BOLD_GREEN << "C created" << RESET << std::endl;
		return new C();
	}
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << BOLD_GREEN << "A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << BOLD_GREEN << "B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << BOLD_GREEN << "C" << RESET << std::endl;
}

void identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << BOLD_GREEN << "A" << RESET << std::endl;
	} catch (std::exception &e) {
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << BOLD_GREEN << "B" << RESET << std::endl;
	} catch (std::exception &e) {
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << BOLD_GREEN << "C" << RESET << std::endl;
	} catch (std::exception &e) {
	}
}

int main() {
	std::srand(std::time(0));
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}