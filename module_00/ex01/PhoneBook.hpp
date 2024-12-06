/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:02:16 by sperron           #+#    #+#             */
/*   Updated: 2024/12/02 13:50:14 by sperron          ###   ########.fr       */
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

// namespace
namespace Module00 {
	// class
	class PhoneBook {

		private:
			// attributes
			Contact _contacts[8];
			int id;
			int	numberContacts;
			// methods
			void modifyContact(Contact &contact);
			void removeContact(int index);
			static void cleanUpAndExit(int signal);
			// getters
			std::string getInput(const std::string& prompt);
			// utils
			void reIndexContacts();
			static std::string truncate(std::string str);

		public:
			// Constructor
			PhoneBook(void);
			// Destructor
			~PhoneBook(void);
			// Method
			void addContact(void);
			void searchContact(void);
	};
}
#endif
