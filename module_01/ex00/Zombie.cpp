/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:26:58 by sperron           #+#    #+#             */
/*   Updated: 2024/12/03 16:30:56 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Zombie class constructor
Zombie::Zombie(std::string name) : name(name) {
	return ;
}

// Zombie class destructor
Zombie::~Zombie() {
	return ;
}

// Zombie class announce method
void	Zombie::announce( void ) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
