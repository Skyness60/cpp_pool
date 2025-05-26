#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << BOLD_RED << "Usage: ./PmergeMe <sequence of positive integers>" << RESET << std::endl;
        return 1;
    }

    PmergeMe sorter;

    try {
        sorter.checkInput(argc, argv);
        sorter.fillContainers(argc, argv);
        sorter.printBefore();

        double start = getTime();
        vector_t sortedVec = sorter.mergeInsertionSort(sorter.getVector());
        sorter.setVector(sortedVec);
        sorter.printAfter();
        sorter.printTime(VECTOR, getTime() - start);

        start = getTime();
        deque_t sortedDeque = sorter.mergeInsertionSort(sorter.getDeque());
        sorter.setDeque(sortedDeque);
        sorter.printTime(DEQUE, getTime() - start);

        return 0;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 1;
}
