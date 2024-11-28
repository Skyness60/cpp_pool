/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:17:30 by sperron           #+#    #+#             */
/*   Updated: 2024/11/28 16:12:04 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook instance;
	std::string command;

	while (true)
	{
		std::getline(std::cin, command);
		if (command == "ADD")
			instance.addContact();
		if (command == "SEARCH")
			instance.searchContact();
		if (command == "EXIT")
			break;
	}
    return (0);
}
