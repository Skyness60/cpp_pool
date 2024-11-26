/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:02:16 by sperron           #+#    #+#             */
/*   Updated: 2024/11/26 12:52:36 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

class PhoneBook {
	private:
		Contact _contacts[8];
		int id;
		int	numberContacts;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void AddContact(void);
		void ModifyContact(Contact &contact);
		void SearchContact(void);
		void RemoveContact(int index);
		std::string getInput(const std::string& prompt);
		void ReindexContacts();
		Contact get_contact(int index);
};

// function

#endif
