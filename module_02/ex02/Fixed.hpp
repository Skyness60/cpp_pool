/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:06:05 by sperron           #+#    #+#             */
/*   Updated: 2025/01/28 11:00:11 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>
#define RESET  "\033[0m"
#define BOLD_RED  "\033[1m\033[31m"      /* Bold Red */
#define BOLD_GREEN  "\033[1m\033[32m"    /* Bold Green */
#define BOLD_YELLOW  "\033[1m\033[33m"   /* Bold Yellow */
#define BOLD_BLUE  "\033[1m\033[34m"     /* Bold Blue */
#define BOLD_MAGENTA  "\033[1m\033[35m"  /* Bold Magenta */
#define BOLD_CYAN  "\033[1m\033[36m"     /* Bold Cyan */
#define BOLD_WHITE  "\033[1m\033[37m"    /* Bold White */
// Class Fixed 
class Fixed
{
	// The private section
	private:
		// The raw value of the fixed point value
		int value;
		// The number of fractional bits
		static const int bits = 8;
	// The public section
	public:
		// Constructor default
		Fixed(void);
		// Constructor int
		Fixed(const int integer);
		// Constructor float
		Fixed(const float floating);
		// Constructor copy
		Fixed(const Fixed &copy);
		// Operator assignation
		Fixed &operator=(const Fixed &copy);
		// Operator comparison
		bool operator>(const Fixed &compare) const;
		bool operator<(const Fixed &compare) const;
		bool operator>=(const Fixed &compare) const;
		bool operator<=(const Fixed &compare) const;
		bool operator==(const Fixed &compare) const;
		bool operator!=(const Fixed &compare) const;
		// Operator arithmetic
		Fixed operator+(const Fixed &add) const;
		Fixed operator-(const Fixed &sub) const;
		Fixed operator*(const Fixed &mul) const;
		Fixed operator/(const Fixed &div) const;
		// Operator incrementation
		Fixed &operator++(void); // Pre-incrementation
		Fixed operator++(int); // Post-incrementation
		Fixed &operator--(void); // Pre-decrementation
		Fixed operator--(int); // Post-decrementation
		// Destructor
		~Fixed();
		// Method public
		static Fixed &min(Fixed &a, Fixed &b); // reference
		static const Fixed &min(const Fixed &a, const Fixed &b); // const reference
		static Fixed &max(Fixed &a, Fixed &b); // reference
		static const Fixed &max(const Fixed &a, const Fixed &b); // const reference
		// Getter
		int getRawBits(void) const;
		// Setter
		void setRawBits(int const raw);
		// Method public
		float toFloat(void) const;
		int toInt(void) const;
};
// Overload operator <<
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // !FIXED_HPP