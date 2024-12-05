/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:02:16 by sperron           #+#    #+#             */
/*   Updated: 2024/12/05 16:27:26 by sperron          ###   ########.fr       */
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
			void removeContact(int index);
			static void cleanUpAndExit(int signal);
			// getters
			std::string getInput(const std::string& prompt);
			// utils
			static std::string truncate(std::string str);

		public:
			// Constructor
			PhoneBook(void);
			// Destructor
			~PhoneBook(void);
			// Method
			void reIndexContacts();
			void addContact(Contact &instance);
			Contact getContact(int index) const;
			void searchContact(void);
			int getNumberContacts(void) const;
			void setContact(int index, Contact contact);
			Contact modifyContact(Contact &contact, std::string str);
			int decrementNumberContacts(void);
	};
}
#endif
