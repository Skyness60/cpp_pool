/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:02:16 by sperron           #+#    #+#             */
/*   Updated: 2024/11/25 19:02:26 by sperron          ###   ########.fr       */
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
		int _index;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void AddContact(void);
		void ModifyContact(Contact &contact);
		void SearchContact(void);
		Contact get_contact(int index);
};

// function

#endif
