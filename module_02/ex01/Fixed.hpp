/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:06:05 by sperron           #+#    #+#             */
/*   Updated: 2025/01/10 19:07:39 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

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
		// Destructor
		~Fixed();
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