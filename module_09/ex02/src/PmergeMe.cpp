#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _vector(other._vector), _deque(other._deque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::checkInput(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        std::string input = argv[i];
        for (size_t j = 0; j < input.length(); ++j) {
            if (!isdigit(input[j]))
                throw WrongInputException();
        }
        double val = atof(argv[i]);
        if (val < 0 || val > INT_MAX)
            throw WrongInputException();
    }
}

void PmergeMe::fillContainers(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        _vector.push_back(value);
        _deque.push_back(value);
    }
}

void PmergeMe::printBefore() const {
    std::cout << BOLD_YELLOW << "\nBefore: " << RESET;
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << BOLD_WHITE << _vector[i] << " ";
    std::cout << RESET << std::endl;
}

void PmergeMe::printAfter() const {
    std::cout << BOLD_GREEN << "\nAfter: " << RESET;
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << BOLD_WHITE << _vector[i] << " ";
    std::cout << RESET << std::endl;
}

void PmergeMe::printTime(int containerType, double time) const {
    std::string container = (containerType == VECTOR) ? "vector" : "deque";
    size_t size = (containerType == VECTOR) ? _vector.size() : _deque.size();
    std::cout << BOLD_BLUE << "\nTime to process a range of " << size
              << " elements with std::" << container
              << ": " << std::fixed << std::setprecision(4)
              << BOLD_WHITE << time << "ms." << RESET << std::endl;
}

template <typename Container>
Container PmergeMe::mergeInsertionSort(const Container& input) {
    if (input.size() <= 1)
        return input;

    Container result;
    typename Container::value_type straggler;
    Container tempInput = input;

    if (tempInput.size() % 2 != 0) {
        straggler = tempInput.back();
        tempInput.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < tempInput.size(); i += 2) {
        int first = tempInput[i];
        int second = tempInput[i + 1];
        if (first > second)
            pairs.push_back(std::make_pair(first, second));
        else
            pairs.push_back(std::make_pair(second, first));
    }

    Container largerElements;
    for (size_t i = 0; i < pairs.size(); ++i)
        largerElements.push_back(pairs[i].first);

    largerElements = mergeInsertionSort(largerElements);

    result = largerElements;

    for (size_t i = 0; i < pairs.size(); ++i) {
        int smaller = pairs[i].second;
        binaryInsert(result, smaller);
    }

    if (input.size() % 2 != 0)
        binaryInsert(result, straggler);

    return result;
}

template <typename Container>
void PmergeMe::binaryInsert(Container& sorted, int value) {
    typename Container::iterator low = sorted.begin();
    typename Container::iterator high = sorted.end();

    while (low < high) {
        typename Container::iterator mid = low + (high - low) / 2;
        if (value < *mid)
            high = mid;
        else
            low = mid + 1;
    }
    sorted.insert(low, value);
}

double getTime() {
    struct timeval tv;
    if (gettimeofday(&tv, NULL) == -1)
        throw ErrorTimeException();
    return (tv.tv_sec * 1000.0) + (tv.tv_usec / 1000.0);
}

// accessors definitions
const vector_t& PmergeMe::getVector() const {
    return _vector;
}

void PmergeMe::setVector(const vector_t& vec) {
    _vector = vec;
}

const deque_t& PmergeMe::getDeque() const {
    return _deque;
}

void PmergeMe::setDeque(const deque_t& deq) {
    _deque = deq;
}

// explicit template instantiations
template vector_t PmergeMe::mergeInsertionSort<vector_t>(const vector_t&);
template deque_t  PmergeMe::mergeInsertionSort<deque_t >(const deque_t&);
