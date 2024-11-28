/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:02:16 by sperron           #+#    #+#             */
/*   Updated: 2024/11/28 16:27:27 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <csignal>

// class
class PhoneBook {

	private:
		Contact _contacts[8];
		int id;
		int	numberContacts;
		void modifyContact(Contact &contact);
		void removeContact(int index);
		static void cleanUpAndExit(int signal);
		std::string getInput(const std::string& prompt);
		void reIndexContacts();
		static std::string truncate(std::string str);

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void addContact(void);
		void searchContact(void);
};

// function

#endif
