/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:50:32 by sperron           #+#    #+#             */
/*   Updated: 2025/01/10 12:30:17 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>

// namespace
namespace Module00 {
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
			// Constructor
			Contact(void);
			// Destructor
			~Contact(void);
			// Getter
			std::string getFirstName() const;
			std::string getLastName() const;
			std::string getNickName() const;
			std::string getNumphone() const;
			std::string getSecret() const;
			int getIndex() const;
			// Setter
			void setFirstName(std::string str);
			void setLastName(std::string str);
			void setNickName(std::string str);
			void setNumphone(std::string str);
			void setSecret(std::string str);
			void setIndex(int index);
			// Method
			void clear();
	};
}
