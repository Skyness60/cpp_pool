/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:50:32 by sperron           #+#    #+#             */
/*   Updated: 2024/11/26 14:55:03 by sperron          ###   ########.fr       */
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
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getNumphone() const;
		std::string getSecret() const;
		int getIndex() const;

		void setFirstName(std::string str);
		void setLastName(std::string str);
		void setNickName(std::string str);
		void setNumphone(std::string str);
		void setSecret(std::string str);
		void setIndex(int index);
		void clear();
};

// function

#endif