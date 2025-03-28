#include <iostream>
#include "MutantStack.hpp"
#include <list>
int main(void) {
	// Essayer d'itérer à travers une pile
	std::cout << std::endl << BOLD_YELLOW "Essayer d'itérer à travers une pile :" RESET << std::endl;
	std::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);   
	std::cout << "\tPile : ";
	for (std::stack<int> dump = s; !dump.empty(); dump.pop())
		std::cout << dump.top() << " ";
	std::cout << std::endl;
	std::cout << BOLD_RED "\t\tLes nombres sont à l'envers car c'est ainsi qu'une stack fonctionne." RESET << std::endl;
	std::cout << BOLD_RED "\t\tVous ne pouvez que ´empiler´ et ´dépiler´ des éléments depuis le sommet de la pile." RESET << std::endl;

	// Essayer d'itérer à travers une MutantStack
	std::cout << std::endl << BOLD_YELLOW "Essayer d'itérer à travers une MutantStack :" RESET << std::endl;
	MutantStack<int> ms;
	ms.push(1);
	ms.push(2);
	ms.push(3);
	ms.push(4);
	std::cout << "\tMutantStack : ";
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << BOLD_GREEN "\t\tLes nombres sont dans le bon ordre car c'est ainsi qu'une MutantStack fonctionne." RESET << std::endl;
	std::cout << BOLD_GREEN "\t\tVous pouvez itérer à travers elle en utilisant l'itérateur du conteneur sous-jacent." RESET << std::endl;
	
	// Tests du sujet
	std::cout << std::endl << BOLD_YELLOW "Tests du sujet #1 - Utilisation de MutantStack" RESET << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> stack(mstack);
	
	std::cout << std::endl << BOLD_YELLOW "Tests du sujet #2 - Utilisation de std::list" RESET << std::endl;
	std::list<int> lstack;
	lstack.push_back(5);
	lstack.push_back(17);
	std::cout << lstack.back() << std::endl;
	lstack.pop_back();
	std::cout << lstack.size() << std::endl;
	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	//[...]
	lstack.push_back(0);
	std::list<int>::iterator itl = lstack.begin();
	std::list<int>::iterator itle = lstack.end();
	++itl;
	--itl;
	while (itl != itle) {
		std::cout << *itl << std::endl;
		++itl;
	}
	std::list<int> list(lstack);

	std::cout << BOLD_GREEN "\t\tLes résultats des deux tests précédents doivent être identiques." RESET << std::endl;
	std::cout << BOLD_GREEN "\t\tCela signifie que nous pouvons utiliser l'itérateur sous-jacent pour la classe MutantStack." RESET << std::endl;
	
	return (0);
}
