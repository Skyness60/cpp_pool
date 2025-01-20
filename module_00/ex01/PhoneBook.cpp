#include "PhoneBook.hpp"

// Constructor
Module00::PhoneBook::PhoneBook(void)
{
	std::cout << "\033[H\033[J";
	this->id = 0;
	this->numberContacts = 0;
	std::string input;
	bool isRunning = true;
	while (isRunning)
	{
		std::cout << "\033[1;36m" << "╔════════════════════════════╗" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "║        PhoneBook Menu      ║" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "╠════════════════════════════╣" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "║ Contacts: " << this->numberContacts << "                ║" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "╠════════════════════════════╣" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "║ \033[1;32mADD\033[1;36m    - Add Contact       ║" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "║ \033[1;33mSEARCH\033[1;36m - Search Contact    ║" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "║ \033[1;31mEXIT\033[1;36m   - Exit              ║" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "╚════════════════════════════╝" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "Enter your choice: " << "\033[0m";
		if (not std::getline(std::cin, input))
		{
			if (std::cin.eof()) {
				std::cout << "\033[1;31m" << "Input interrupted by EOF. Exiting program." << "\033[0m" << std::endl;
				return;
			}
			std::cin.clear();
			continue;
		}
		if (input == "ADD")
		{
			std::cout << "\033[H\033[J";
			this->addContact();
		}
		else if (input == "SEARCH")
		{
			std::cout << "\033[H\033[J";
			this->searchContact();
		}
		else if (input == "EXIT")
		{
			std::cout << "\033[H\033[J";
			std::cout << "\033[1;32m" << "Exiting Module00. Goodbye!" << "\033[0m" << std::endl;
			isRunning = false;
		}
		else
		{
			std::cout << "\033[1;31m" << "Invalid choice. Please try again." << "\033[0m" << std::endl;
		}
	}
}
// Destructor
Module00::PhoneBook::~PhoneBook(void)
{
	return;
}

//getter
std::string Module00::PhoneBook::getInput(const std::string& prompt) {
	std::string str;
	std::cout << "\033[1;36m" << prompt << "\033[0m" << std::endl;
	while (not std::getline(std::cin, str) or str.empty()) {
		if (std::cin.eof()) {
			std::cout << "\033[1;31m" << "Input interrupted by EOF. Exiting program." << "\033[0m" << std::endl;
			return "";
		}
		std::cout << "\033[1;31m" << prompt << " cannot be empty. Please enter again:" << "\033[0m" << std::endl;
	}
	return str;
}

void Module00::PhoneBook::addContact(void)
{
	Contact instance;
	instance.setFirstName(getInput("First Name"));
	instance.setLastName(getInput("Last Name"));
	instance.setNickName(getInput("Nick Name"));
	instance.setNumphone(getInput("Phone Number"));
	instance.setSecret(getInput("shhhhhh secret ..."));
	bool added = false;
	for (int i = 0; i < 8; i++) {
		if (this->_contacts[i].getFirstName().empty()) {
			this->_contacts[i] = instance;
			added = true;
			break;
		}
	}
	if (not added) {
		this->_contacts[this->id] = instance;
		this->id = (this->id + 1) % 8;
	}
	if (this->numberContacts < 8) {
		this->numberContacts++;
	}
	reIndexContacts();
	std::cout << std::endl << "\033[1;32m" << "Contact Added ✓" << "\033[0m" << std::endl;
}

void Module00::PhoneBook::removeContact(int index)
{
	if (index < 0 or index >= 8 or this->_contacts[index].getFirstName().empty()) {
		std::cout << "\033[1;31m" << "Invalid index or contact does not exist." << "\033[0m" << std::endl;
		return;
	}
	for (int i = index; i < 7; i++) {
		this->_contacts[i] = this->_contacts[i + 1];
	}
	this->_contacts[7].clear();
	this->numberContacts--;
	if (this->id > 0) {
		this->id--;
	}
	reIndexContacts();
	std::cout << "\033[1;32m" << "Contact removed successfully!" << "\033[0m" << std::endl;
	std::cout << "\033[H\033[J";
	this->searchContact();
}

void Module00::PhoneBook::searchContact(void)
{
	std::string str;



	if (this->numberContacts > 0) {
		std::cout << "\033[1;36m" << "╔════════════════════════════╗" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "║        SEARCH MENU         ║" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "╠════════════════════════════╣" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "║ \033[1;32mID\033[1;36m    - Search Contact     ║" << "\033[0m" << std::endl;
		std::cout << "\033[1;31m" << "║ \033[1;31mBACK\033[1;36m   - Back              ║" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "╚════════════════════════════╝" << "\033[0m" << std::endl;
		std::cout << "\033[1;34m" << "┌──────────┬──────────┬──────────┬──────────┐" << "\033[0m" << std::endl;
		std::cout << "\033[1;34m" << "|" << std::setw(7) << "Index" << std::setw(4);
		std::cout << "|" << std::setw(10) << "First Name";
		std::cout << "|" << std::setw(9) << "Last Name" << std::setw(2);
		std::cout << "|" << std::setw(9) << "Nick Name" << std::setw(2) << "|" << "\033[0m" << std::endl;
		std::cout << "\033[1;34m" << "├──────────┼──────────┼──────────┼──────────┤" << "\033[0m" << std::endl;
		for (int i = 0; i < 8; i++) {
			if (not this->_contacts[i].getFirstName().empty()) {
				Contact contact = this->_contacts[i];
				std::cout << "\033[1;34m" << "|" << std::setw(10) << std::right << contact.getIndex();
				std::cout << "|" << std::setw(10) << std::right << truncate(contact.getFirstName());
				std::cout << "|" << std::setw(10) << std::right << truncate(contact.getLastName());
				std::cout << "|" << std::setw(10) << std::right << truncate(contact.getNickName()) << "|" << "\033[0m" << std::endl;
			}
		}
		std::cout << "\033[1;34m" << "└──────────┴──────────┴──────────┴──────────┘" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "Enter your choice: " << "\033[0m";
		if (not std::getline(std::cin, str))
		{
			if (std::cin.eof()) {
				std::cout << "\033[1;31m" << "Input interrupted by EOF. Exiting program." << "\033[0m" << std::endl;
				return;
			}
			std::cin.clear();
			return;
		}

		if (str == "BACK")
		{
			std::cout << "\033[H\033[J";
			return;
		}

		if (str.size() == 1 and str[0] >= '1' and str[0] <= '8' and not this->_contacts[str[0] - '1'].getFirstName().empty())
		{
			Contact &contact = this->_contacts[str[0] - '1'];
			std::cout << "\033[1;33m" << "→ " << "First Name : " << "\033[1;36m" << contact.getFirstName() << "\033[0m" << std::endl;
			std::cout << "\033[1;33m" << "→ " << "Last Name : " << "\033[1;36m" << contact.getLastName() << "\033[0m" << std::endl;
			std::cout << "\033[1;33m" << "→ " << "Nick Name : " << "\033[1;36m" << contact.getNickName() << "\033[0m" << std::endl;
			std::cout << "\033[1;33m" << "→ " << "Phone Number : " << "\033[1;36m" << contact.getNumphone() << "\033[0m" << std::endl;
			std::cout << "\033[1;33m" << "→ " << "Secret : " << "\033[1;36m" << contact.getSecret() << "\033[0m" << std::endl;

			std::cout << "\033[1;36m" << "╔════════════════════════════╗" << "\033[0m" << std::endl;
			std::cout << "\033[1;36m" << "║        SEARCH MENU         ║" << "\033[0m" << std::endl;
			std::cout << "\033[1;36m" << "╠════════════════════════════╣" << "\033[0m" << std::endl;
			std::cout << "\033[1;36m" << "║ \033[1;32mMODIFY\033[1;36m   - To Edit         ║" << "\033[0m" << std::endl;
			std::cout << "\033[1;36m" << "║ \033[1;31mREMOVE\033[1;36m   - To Remove       ║" << "\033[0m" << std::endl;
			std::cout << "\033[1;36m" << "║ \033[1;31mFINISH\033[1;36m   - Return main menu║" << "\033[0m" << std::endl;
			std::cout << "\033[1;36m" << "║ \033[1;31mBACK\033[1;36m     - Search menu     ║" << "\033[0m" << std::endl;
			std::cout << "\033[1;36m" << "╚════════════════════════════╝" << "\033[0m" << std::endl;
			std::cout << "\033[1;36m" << std::endl << "Enter your choice: " << "\033[0m";
			if (not std::getline(std::cin, str))
			{
				if (std::cin.eof()) {
					std::cout << "\033[1;31m" << "Input interrupted by EOF. Exiting program." << "\033[0m" << std::endl;
					return;
				}
				std::cin.clear();
				return;
			}

			if (str == "MODIFY")
			{
				this->modifyContact(contact);
				return;
			}
			else if (str == "REMOVE")
			{
				removeContact(contact.getIndex() - 1);
				return;
			}
			else if (str == "FINISH")
			{
				std::cout << "\033[H\033[J";
				return;
			}
			else if (str == "BACK")
			{
				std::cout << "\033[H\033[J";
				searchContact();
				return;
			}
			else
			{
				std::cout << "\033[1;31m" << "Invalid choice. Please try again." << "\033[0m" << std::endl;
			}
		}
		else
		{
			std::cout << "\033[1;31m" << "Invalid ID. Please enter a valid ID (1-8):" << "\033[0m" << std::endl;
		}
	}
	else
	{
		std::cout << "\033[1;34m" << "You don't have any contacts in your Module00." << "\033[0m" << std::endl;
	}
}

void Module00::PhoneBook::modifyContact(Contact &contact)
{
	std::string str;

	std::cout << "\033[1;36m" << "Modify First Name (current: " << contact.getFirstName() << "): " << "\033[0m" << std::endl;
	if (std::getline(std::cin, str) and not str.empty())
		contact.setFirstName(str);

	std::cout << "\033[1;36m" << "Modify Last Name (current: " << contact.getLastName() << "): " << "\033[0m" << std::endl;
	if (std::getline(std::cin, str) and not str.empty())
		contact.setLastName(str);

	std::cout << "\033[1;36m" << "Modify Nick Name (current: " << contact.getNickName() << "): " << "\033[0m" << std::endl;
	if (std::getline(std::cin, str) and not str.empty())
		contact.setNickName(str);

	std::cout << "\033[1;36m" << "Modify Phone Number (current: " << contact.getNumphone() << "): " << "\033[0m" << std::endl;
	if (std::getline(std::cin, str) and not str.empty())
		contact.setNumphone(str);

	std::cout << "\033[1;36m" << "Modify Secret (current: " << contact.getSecret() << "): " << "\033[0m" << std::endl;
	if (std::getline(std::cin, str) and not str.empty())
		contact.setSecret(str);

	std::cout << std::endl << "\033[1;32m" << "Contact Modified ✓" << "\033[0m" << std::endl;
}

// utils
void Module00::PhoneBook::reIndexContacts()
{
	int contactIndex = 1;
	for (int i = 0; i < 8; i++)
		if (not this->_contacts[i].getFirstName().empty())
			this->_contacts[i].setIndex(contactIndex++);
}

std::string Module00::PhoneBook::truncate(std::string str)
{
	if (str.size() >= 10)
		return (str.substr(0, 7) + ".");
	return (str);
}

