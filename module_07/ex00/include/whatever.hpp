#pragma once

#include <iostream>

template <typename T> const T &max(const T &a, const T &b) {
	return (a > b ? a : b);
}
template <typename T> const T &min(const T &a, const T &b) {
	return (a < b ? a : b);
}
template <typename T> void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

// define color for the output
# define RESET  "\033[0m" /* Reset */
# define BOLD_RED  "\033[1m\033[31m"      /* Bold Red */
# define BOLD_GREEN  "\033[1m\033[32m"    /* Bold Green */
# define BOLD_YELLOW  "\033[1m\033[33m"   /* Bold Yellow */
# define BOLD_BLUE  "\033[1m\033[34m"     /* Bold Blue */
# define BOLD_MAGENTA  "\033[1m\033[35m"  /* Bold Magenta */
# define BOLD_CYAN  "\033[1m\033[36m"     /* Bold Cyan */
# define BOLD_WHITE  "\033[1m\033[37m"    /* Bold White */
