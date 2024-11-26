#include "PhoneBook.hpp"

std::string truncate(std::string str)
{
	if (str.size() >= 10)
		return (str.substr(0, 7) + "...");
	return (str);
}

PhoneBook::PhoneBook(void)
{
	std::system("clear");
	this->id = 0;
	this->numberContacts = 0;
	std::string input;

	while (true)
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

		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof()) {
				std::cerr << "\033[1;31m" << "Input interrupted by EOF. Exiting program." << "\033[0m" << std::endl;
				std::exit(1);
			}
			std::cin.clear();
			break;
		}

		if (input == "ADD")
		{
			std::system("clear");
			this->AddContact();
		}
		else if (input == "SEARCH")
		{
			std::system("clear");
			this->SearchContact();
		}
		else if (input == "EXIT")
		{
			std::system("clear");
			std::cout << "\033[1;32m" << "Exiting PhoneBook. Goodbye!" << "\033[0m" << std::endl;
			std::exit(0);
		}
		else
		{
			std::cout << "\033[1;31m" << "Invalid choice. Please try again." << "\033[0m" << std::endl;
		}
	}
}


PhoneBook::~PhoneBook(void)
{
	return;
}

std::string PhoneBook::getInput(const std::string& prompt) {
	std::string str;
	std::cout << "\033[1;36m" << prompt << "\033[0m" << std::endl;
	while (!std::getline(std::cin, str) || str.empty()) {
		if (std::cin.eof()) {
			std::cerr << "\033[1;31m" << "Input interrupted by EOF. Exiting program." << "\033[0m" << std::endl;
			std::exit(1);
		}
		std::cout << "\033[1;31m" << prompt << " cannot be empty. Please enter again:" << "\033[0m" << std::endl;
	}
	return str;
}
#include <stdio.h>
void PhoneBook::ReindexContacts()
{
	int contactIndex = 1;
	for (int i = 0; i < 8; i++) {
		if (!this->_contacts[i].GetFirstName().empty()) {
			this->_contacts[i].SetIndex(contactIndex++);
			printf("index : %d\n", this->_contacts[i].GetIndex());
		}
	}
}


void PhoneBook::AddContact(void)
{
	Contact instance;
	instance.SetFirstName(getInput("First Name"));
	instance.SetLastName(getInput("Last Name"));
	instance.SetNickName(getInput("Nick Name"));
	instance.SetNumphone(getInput("Phone Number"));
	instance.SetSecret(getInput("shhhhhh secret ..."));
	bool added = false;
	for (int i = 0; i < 8; i++) {
		if (this->_contacts[i].GetFirstName().empty()) {
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
	ReindexContacts();
	std::cout << std::endl << "\033[1;32m" << "Contact Added ✓" << "\033[0m" << std::endl;
}

void PhoneBook::RemoveContact(int index)
{
	if (index < 0 || index >= 8 || this->_contacts[index].GetFirstName().empty()) {
		std::cout << "\033[1;31m" << "Invalid index or contact does not exist." << "\033[0m" << std::endl;
		return;
	}
	for (int i = index; i < 7; i++) {
		this->_contacts[i] = this->_contacts[i + 1];
	}
	this->_contacts[7].Clear();
	this->numberContacts--;
	ReindexContacts();
	std::cout << "\033[1;32m" << "Contact removed successfully!" << "\033[0m" << std::endl;
	std::system("clear");
	this->SearchContact();
}


void PhoneBook::SearchContact(void)
{
	std::string str;

	std::cout << "\033[1;36m" << "╔════════════════════════════╗" << "\033[0m" << std::endl;
	std::cout << "\033[1;36m" << "║        SEARCH MENU         ║" << "\033[0m" << std::endl;
	std::cout << "\033[1;36m" << "╠════════════════════════════╣" << "\033[0m" << std::endl;
	std::cout << "\033[1;36m" << "║ \033[1;32mID\033[1;36m    - Search Contact     ║" << "\033[0m" << std::endl;
	std::cout << "\033[1;31m" << "║ \033[1;31mBACK\033[1;36m   - Back              ║" << "\033[0m" << std::endl;
	std::cout << "\033[1;36m" << "╚════════════════════════════╝" << "\033[0m" << std::endl;

	if (this->numberContacts > 0) {
		std::cout << "\033[1;34m" << "┌──────────┬──────────┬──────────┬──────────┐" << "\033[0m" << std::endl;
		std::cout << "\033[1;34m" << "|" << std::setw(7) << "Index" << std::setw(4);
		std::cout << "|" << std::setw(10) << "First Name";
		std::cout << "|" << std::setw(9) << "Last Name" << std::setw(2);
		std::cout << "|" << std::setw(9) << "Nick Name" << std::setw(2) << "|" << "\033[0m" << std::endl;
		std::cout << "\033[1;34m" << "├──────────┼──────────┼──────────┼──────────┤" << "\033[0m" << std::endl;
		for (int i = 0; i < 8; i++) {
			if (!this->_contacts[i].GetFirstName().empty()) {
				Contact contact = this->_contacts[i];
				std::cout << "\033[1;34m" << "|" << std::setw(10) << std::right << contact.GetIndex();
				std::cout << "|" << std::setw(10) << std::right << truncate(contact.GetFirstName());
				std::cout << "|" << std::setw(10) << std::right << truncate(contact.GetLastName());
				std::cout << "|" << std::setw(10) << std::right << truncate(contact.GetNickName()) << "|" << "\033[0m" << std::endl;
			}
		}
		std::cout << "\033[1;34m" << "└──────────┴──────────┴──────────┴──────────┘" << "\033[0m" << std::endl;
		while (true)
		{
			 std::cout << "\033[1;36m" << "Enter your choice: " << "\033[0m";
			if (!std::getline(std::cin, str))
			{
				if (std::cin.eof()) {
					std::cerr << "\033[1;31m" << "Input interrupted by EOF. Exiting program." << "\033[0m" << std::endl;
					std::exit(1);
				}
				std::cin.clear();
				break;
			}

			if (str == "BACK")
			{
				std::system("clear");
				return;
			}

			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && !this->_contacts[str[0] - '1'].GetFirstName().empty())
			{
				Contact &contact = this->_contacts[str[0] - '1'];
				std::cout << "\033[1;33m" << "→ " << "First Name : " << "\033[1;36m" << contact.GetFirstName() << "\033[0m" << std::endl;
				std::cout << "\033[1;33m" << "→ " << "Last Name : " << "\033[1;36m" << contact.GetLastName() << "\033[0m" << std::endl;
				std::cout << "\033[1;33m" << "→ " << "Nick Name : " << "\033[1;36m" << contact.GetNickName() << "\033[0m" << std::endl;
				std::cout << "\033[1;33m" << "→ " << "Phone Number : " << "\033[1;36m" << contact.GetNumphone() << "\033[0m" << std::endl;
				std::cout << "\033[1;33m" << "→ " << "Secret : " << "\033[1;36m" << contact.GetSecret() << "\033[0m" << std::endl;

				while (true)
				{
					std::cout << "\033[1;36m" << "╔════════════════════════════╗" << "\033[0m" << std::endl;
					std::cout << "\033[1;36m" << "║        SEARCH MENU         ║" << "\033[0m" << std::endl;
					std::cout << "\033[1;36m" << "╠════════════════════════════╣" << "\033[0m" << std::endl;
					std::cout << "\033[1;36m" << "║ \033[1;32mMODIFY\033[1;36m   - To Edit         ║" << "\033[0m" << std::endl;
					std::cout << "\033[1;36m" << "║ \033[1;31mREMOVE\033[1;36m   - To Remove       ║" << "\033[0m" << std::endl;
					std::cout << "\033[1;36m" << "║ \033[1;31mFINISH\033[1;36m   - Return main menu║" << "\033[0m" << std::endl;
					std::cout << "\033[1;36m" << "║ \033[1;31mBACK\033[1;36m     - Search menu     ║" << "\033[0m" << std::endl;
					std::cout << "\033[1;36m" << "╚════════════════════════════╝" << "\033[0m" << std::endl;
					std::cout << "\033[1;36m" << std::endl << "Enter your choice: " << "\033[0m";
					if (!std::getline(std::cin, str))
					{
						if (std::cin.eof()) {
							std::cerr << "\033[1;31m" << "Input interrupted by EOF. Exiting program." << "\033[0m" << std::endl;
							std::exit(1);
						}
						std::cin.clear();
						break;
					}

					if (str == "MODIFY")
					{
						this->ModifyContact(contact);
						return ;
					}
					else if (str == "REMOVE")
					{
						RemoveContact(contact.GetIndex() - 1);
						return;
					}
					else if (str == "FINISH")
					{
						std::system("clear");
						return;
					}
					else if (str == "BACK")
					{
						std::system("clear");
						SearchContact();
						return ;
					}
					else
					{
						std::cout << "\033[1;31m" << "Invalid choice. Please try again." << "\033[0m" << std::endl;
					}
				}
			}
			else
			{
				std::cout << "\033[1;31m" << "Invalid ID. Please enter a valid ID (1-8):" << "\033[0m" << std::endl;
			}
		}
	}
	else
	{
		std::cout << "\033[1;34m" << "You don't have any contacts in your phonebook." << "\033[0m" << std::endl;
	}
}

void PhoneBook::ModifyContact(Contact &contact)
{
	std::string str;

	std::cout << "\033[1;36m" << "Modify First Name (current: " << contact.GetFirstName() << "): " << "\033[0m" << std::endl;
	if (std::getline(std::cin, str) && !str.empty())
		contact.SetFirstName(str);

	std::cout << "\033[1;36m" << "Modify Last Name (current: " << contact.GetLastName() << "): " << "\033[0m" << std::endl;
	if (std::getline(std::cin, str) && !str.empty())
		contact.SetLastName(str);

	std::cout << "\033[1;36m" << "Modify Nick Name (current: " << contact.GetNickName() << "): " << "\033[0m" << std::endl;
	if (std::getline(std::cin, str) && !str.empty())
		contact.SetNickName(str);

	std::cout << "\033[1;36m" << "Modify Phone Number (current: " << contact.GetNumphone() << "): " << "\033[0m" << std::endl;
	if (std::getline(std::cin, str) && !str.empty())
		contact.SetNumphone(str);

	std::cout << "\033[1;36m" << "Modify Secret (current: " << contact.GetSecret() << "): " << "\033[0m" << std::endl;
	if (std::getline(std::cin, str) && !str.empty())
		contact.SetSecret(str);

	std::cout << std::endl << "\033[1;32m" << "Contact Modified ✓" << "\033[0m" << std::endl;
}
