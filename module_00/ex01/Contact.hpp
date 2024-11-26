/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:50:32 by sperron           #+#    #+#             */
/*   Updated: 2024/11/26 12:55:27 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

// class
class Contact {
	private:
		int _index;
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _numphone;
		std::string _secret;
	public:
		Contact(void);
		~Contact(void);
		// Getter & Setter
		std::string GetFirstName() const;
		std::string GetLastName() const;
		std::string GetNickName() const;
		std::string GetNumphone() const;
		std::string GetSecret() const;
		int GetIndex() const;

		void SetFirstName(std::string str);
		void SetLastName(std::string str);
		void SetNickName(std::string str);
		void SetNumphone(std::string str);
		void SetSecret(std::string str);
		void SetIndex(int index);
		void Clear();
};

// function

#endif