#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <climits>
#include <sys/time.h>
#include <iomanip>

// define color for the output
# define RESET  "\033[0m" /* Reset */
# define BOLD_RED  "\033[1m\033[31m"      /* Bold Red */
# define BOLD_GREEN  "\033[1m\033[32m"    /* Bold Green */
# define BOLD_YELLOW  "\033[1m\033[33m"   /* Bold Yellow */
# define BOLD_BLUE  "\033[1m\033[34m"     /* Bold Blue */
# define BOLD_MAGENTA  "\033[1m\033[35m"  /* Bold Magenta */
# define BOLD_CYAN  "\033[1m\033[36m"     /* Bold Cyan */
# define BOLD_WHITE  "\033[1m\033[37m"    /* Bold White */

#define VECTOR 1
#define DEQUE 0

typedef std::vector<int> vector_t;
typedef std::deque<int> deque_t;

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void checkInput(int argc, char** argv);
    void fillContainers(int argc, char** argv);
    void printBefore() const;
    void printAfter() const;
    void printTime(int containerType, double time) const;

    template <typename Container>
    Container mergeInsertionSort(const Container& input);

    template <typename Container>
    void binaryInsert(Container& sorted, int value);
    const vector_t& getVector() const;
    void setVector(const vector_t& vec);
    const deque_t& getDeque() const;
    void setDeque(const deque_t& deq);

private:
    vector_t _vector;
    deque_t _deque;
};

double getTime();

class ErrorTimeException : public std::exception {
public:
    virtual const char* what() const throw() {
        return BOLD_RED "Error: an error occurred using gettimeofday()" RESET;
    }
};

class WrongInputException : public std::exception {
public:
    virtual const char* what() const throw() {
        return BOLD_RED "Error: please enter unsigned ints only" RESET;
    }
};

#endif
