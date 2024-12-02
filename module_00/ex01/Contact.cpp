/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:50:55 by sperron           #+#    #+#             */
/*   Updated: 2024/12/02 13:56:25 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructor & Destructor
Module00::Contact::Contact(void)
{
	return;
}

Module00::Contact::~Contact(void)
{
	return;
}

// Getter
std::string Module00::Contact::getFirstName(void) const
{
	return (this->_firstname);
}

std::string Module00::Contact::getLastName(void) const
{
	return (this->_lastname);
}

std::string Module00::Contact::getNickName(void) const
{
	return (this->_nickname);
}

std::string Module00::Contact::getNumphone(void) const
{
	return (this->_numphone);
}

std::string Module00::Contact::getSecret(void) const
{
	return (this->_secret);
}

int Module00::Contact::getIndex(void) const
{
	return (this->_index);
}

// Setter
void Module00::Contact::setFirstName(std::string str)
{
	this->_firstname = str;
}

void Module00::Contact::setLastName(std::string str)
{
	this->_lastname = str;
}

void Module00::Contact::setNickName(std::string str)
{
	this->_nickname = str;
}

void Module00::Contact::setNumphone(std::string str)
{
	this->_numphone = str;
}

void Module00::Contact::setSecret(std::string str)
{
	this->_secret = str;
}

void Module00::Contact::setIndex(int id)
{
	this->_index = id;
}

void Module00::Contact::clear()
{
	this->_index = 0;
    this->_firstname.clear();
    this->_lastname.clear();
    this->_nickname.clear();
    this->_numphone.clear();
    this->_secret.clear();
}
