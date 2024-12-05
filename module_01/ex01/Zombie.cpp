/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:26:58 by sperron           #+#    #+#             */
/*   Updated: 2024/12/05 12:35:16 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Zombie class announce method
void	Zombie::announce( void ) {
	std::cout << BLUE_BOLD << this->name << ": " << GREEN_BOLD << "BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
