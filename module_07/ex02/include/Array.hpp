#pragma once

#include <iostream>

// define color for the output
# define RESET  "\033[0m" /* Reset */
# define BOLD_RED  "\033[1m\033[31m"      /* Bold Red */
# define BOLD_GREEN  "\033[1m\033[32m"    /* Bold Green */
# define BOLD_YELLOW  "\033[1m\033[33m"   /* Bold Yellow */
# define BOLD_BLUE  "\033[1m\033[34m"     /* Bold Blue */
# define BOLD_MAGENTA  "\033[1m\033[35m"  /* Bold Magenta */
# define BOLD_CYAN  "\033[1m\033[36m"     /* Bold Cyan */
# define BOLD_WHITE  "\033[1m\033[37m"    /* Bold White */

template <typename T>

class Array {
	public:
		Array() : array(new T(0)), arraySize(0) {};
		Array(unsigned int n) : array(new T[n]), arraySize(n) {};
		Array(const Array &copy) : array(new T[copy.arraySize]), arraySize(copy.arraySize) {
			for (unsigned int i = 0; i < arraySize; i++)
				array[i] = copy.array[i];
		};
		~Array() {
			delete[] array;
		};
		Array &operator=(const Array &copy) {
			if (this not_eq &copy) {
				delete[] array;
				array = new T[copy.arraySize];
				arraySize = copy.arraySize;
				for (unsigned int i = 0; i < arraySize; i++)
					array[i] = copy.array[i];
			}
			return *this;
		};
		T &operator[](unsigned int index) {
			if (index >= arraySize)
				throw std::out_of_range("Index out of range");
			return array[index];
		};
		unsigned int size() const {
			return this->arraySize;
		};
	private:
		T *array;
		unsigned int arraySize;
};