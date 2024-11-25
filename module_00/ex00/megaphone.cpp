/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:28:59 by sperron           #+#    #+#             */
/*   Updated: 2024/11/25 11:37:47 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define RED_BOLD "\033[1;31m"
#define MAGENTA_BOLD "\033[1;35m"
#define RESET "\033[0m"

int main(int ac, char **av)
{
    try {
        if (ac == 1)
            throw std::invalid_argument("LOUD AND UNBEARABLE FEEDBACK NOISE");
        for (int i = 1; i < ac; i++)
            for (int j = 0; av[i][j]; j++)
                std::cout << MAGENTA_BOLD << (char)std::toupper(av[i][j]);
        std::cout << std::endl << RESET;
    } catch (const std::exception &e) {
        return (std::cerr << RED_BOLD << "* " << e.what() << " *" << RESET << std::endl, 1);
	}
    return (0);
}
