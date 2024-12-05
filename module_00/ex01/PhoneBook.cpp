#include "PhoneBook.hpp"

// Constructor
Module00::PhoneBook::PhoneBook(void)
{
	this->id = 0;
	this->numberContacts = 0;
}
// Destructor
Module00::PhoneBook::~PhoneBook(void)
{
	return;
}

//getter
int Module00::PhoneBook::getNumberContacts(void) const
{
	return this->numberContacts;
}

Module00::Contact Module00::PhoneBook::getContact(int index) const
{
	if (index < 0 || index >= 8 || this->_contacts[index].getFirstName().empty()) {
		std::cout << "\033[1;31m" << "Invalid index or contact does not exist." << "\033[0m" << std::endl;
		return Contact();
	}
	return this->_contacts[index];
}

// add && remove && search
void Module00::PhoneBook::addContact(Contact &instance)
{
	bool added = false;
	for (int i = 0; i < 8; i++) {
		if (this->_contacts[i].getFirstName().empty() || this->_contacts[i].getLastName().empty() || this->_contacts[i].getNickName().empty() || this->_contacts[i].getNumphone().empty() || this->_contacts[i].getSecret().empty()) {
			this->_contacts[i] = instance;
			added = true;
			break;
		}
	}
	if (!added) {
		this->_contacts[this->id] = instance;
		this->id = (this->id + 1) % 8;
	}
	if (this->numberContacts < 8) {
		this->numberContacts++;
	}
	reIndexContacts();
}

void Module00::PhoneBook::removeContact(int index)
{
	if (index < 0 || index >= 8 || this->_contacts[index].getFirstName().empty()) {
		std::cout << "\033[1;31m" << "Invalid index or contact does not exist." << "\033[0m" << std::endl;
		return;
	}
	for (int i = index; i < 7; i++) {
		this->_contacts[i] = this->_contacts[i + 1];
	}
	this->_contacts[7].clear();
	this->numberContacts--;
	reIndexContacts();
	std::cout << "\033[1;32m" << "Contact removed successfully!" << "\033[0m" << std::endl;
	std::system("clear");
	this->searchContact();
}

void Module00::PhoneBook::searchContact(void)
{
	for (int i = 0; i < 8; i++) {
		if (!this->_contacts[i].getFirstName().empty()) {
			Contact contact = this->_contacts[i];
			std::cout << "\033[1;34m" << "|" << std::setw(10) << std::right << contact.getIndex();
			std::cout << "|" << std::setw(10) << std::right << truncate(contact.getFirstName());
			std::cout << "|" << std::setw(10) << std::right << truncate(contact.getLastName());
			std::cout << "|" << std::setw(10) << std::right << truncate(contact.getNickName()) << "|" << "\033[0m" << std::endl;
		}
	}
}

void Module00::PhoneBook::setContact(int index, Contact contact)
{
	if (index < 0 || index >= 8 || contact.getFirstName().empty()) {
		std::cout << "\033[1;31m" << "Invalid index or contact does not exist." << "\033[0m" << std::endl;
		return;
	}
	this->_contacts[index] = contact;
}

Module00::Contact Module00::PhoneBook::modifyContact(Contact &contact, std::string str)
{
	std::cout << "\033[1;36m" << "Modify First Name (current: " << contact.getFirstName() << "): " << "\033[0m" << std::endl;
	if (std::getline(std::cin, str) && !str.empty())
		contact.setFirstName(str);

	std::cout << "\033[1;36m" << "Modify Last Name (current: " << contact.getLastName() << "): " << "\033[0m" << std::endl;
	if (std::getline(std::cin, str) && !str.empty())
		contact.setLastName(str);

	std::cout << "\033[1;36m" << "Modify Nick Name (current: " << contact.getNickName() << "): " << "\033[0m" << std::endl;
	if (std::getline(std::cin, str) && !str.empty())
		contact.setNickName(str);

	std::cout << "\033[1;36m" << "Modify Phone Number (current: " << contact.getNumphone() << "): " << "\033[0m" << std::endl;
	if (std::getline(std::cin, str) && !str.empty())
		contact.setNumphone(str);

	std::cout << "\033[1;36m" << "Modify Secret (current: " << contact.getSecret() << "): " << "\033[0m" << std::endl;
	if (std::getline(std::cin, str) && !str.empty())
		contact.setSecret(str);

	std::cout << std::endl << "\033[1;32m" << "Contact Modified ✓" << "\033[0m" << std::endl;

	return contact;
}

// utils
void Module00::PhoneBook::reIndexContacts()
{
	int contactIndex = 1;
	for (int i = 0; i < 8; i++)
		if (!this->_contacts[i].getFirstName().empty())
			this->_contacts[i].setIndex(contactIndex++);
}

int Module00::PhoneBook::decrementNumberContacts(void)
{
	if (this->numberContacts > 0)
		this->numberContacts--;
	return this->numberContacts;
}

std::string Module00::PhoneBook::truncate(std::string str)
{
	if (str.size() >= 10)
		return (str.substr(0, 7) + ".");
	return (str);
}

void Module00::PhoneBook::cleanUpAndExit(int signal)
{
	if (signal == SIGINT || signal == SIGQUIT)
	{
		return ;
	}
}
