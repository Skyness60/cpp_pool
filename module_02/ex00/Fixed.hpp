/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:06:05 by sperron           #+#    #+#             */
/*   Updated: 2025/01/10 19:07:24 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

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
};

#endif // !FIXED_HPP