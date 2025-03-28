#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include "easyfind.hpp"

template <typename T>
void testContainer(const std::string &name, T &container, int searchValue)
{
	std::cout << BOLD_CYAN << "🔎 Test avec " << name << "..." << RESET << std::endl;
	try {
		typename T::iterator it = easyfind(container, searchValue);
		std::cout << BOLD_GREEN << "✅ Trouvé dans " << name << " : " << *it << RESET << std::endl;
	} catch (const std::exception &e) {
		std::cout << BOLD_RED << "❌ Erreur dans " << name << " : " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./easyfind [value]" << std::endl;
        return 1;
    }

    int value = std::atoi(av[1]); // Convertit l'argument en entier

    // Création des conteneurs
    std::vector<int> vec;
    std::list<int> lst;
    std::deque<int> deq;
    std::string str;

    int values[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        vec.push_back(values[i]);
        lst.push_back(values[i]);
        deq.push_back(values[i]);
		str.push_back(values[i] + '0');
    }

    // Test avec chaque conteneur
    testContainer("vector", vec, value);
    testContainer("list", lst, value);
    testContainer("deque", deq, value);
    testContainer("string", str, value + '0');

    return 0;
}
