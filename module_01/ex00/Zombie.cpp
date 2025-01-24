/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:26:58 by sperron           #+#    #+#             */
/*   Updated: 2025/01/24 15:51:52 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Zombie class constructor
Zombie::Zombie(std::string name) : name(name) {
	return ;
}

// Zombie class destructor
Zombie::~Zombie() {
	std::cout << RED_BOLD << "Zombie " << this->name << " has been destroyed." << RESET << std::endl;
}

// Zombie class announce method
void	Zombie::announce( void ) {
	std::cout << BLUE_BOLD << this->name << ": " << GREEN_BOLD << "BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
