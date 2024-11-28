/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:50:55 by sperron           #+#    #+#             */
/*   Updated: 2024/11/28 16:11:45 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructor & Destructor
Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

// Getter
std::string Contact::getFirstName(void) const
{
	return (this->_firstname);
}

std::string Contact::getLastName(void) const
{
	return (this->_lastname);
}

std::string Contact::getNickName(void) const
{
	return (this->_nickname);
}

std::string Contact::getNumphone(void) const
{
	return (this->_numphone);
}

std::string Contact::getSecret(void) const
{
	return (this->_secret);
}

int Contact::getIndex(void) const
{
	return (this->_index);
}

// Setter
void Contact::setFirstName(std::string str)
{
	this->_firstname = str;
}

void Contact::setLastName(std::string str)
{
	this->_lastname = str;
}

void Contact::setNickName(std::string str)
{
	this->_nickname = str;
}

void Contact::setNumphone(std::string str)
{
	this->_numphone = str;
}

void Contact::setSecret(std::string str)
{
	this->_secret = str;
}

void Contact::setIndex(int id)
{
	this->_index = id;
}

void Contact::clear()
{
	this->_index = 0;
    this->_firstname.clear();
    this->_lastname.clear();
    this->_nickname.clear();
    this->_numphone.clear();
    this->_secret.clear();
}
