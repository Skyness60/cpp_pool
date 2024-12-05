/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:17:30 by sperron           #+#    #+#             */
/*   Updated: 2024/12/05 16:28:38 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void cleanUpAndExit(int signal)
{
	if (signal == SIGINT || signal == SIGQUIT)
	{
		return ;
	}
}

static std::string getInput(const std::string& prompt) {
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

static void addContact(Module00::PhoneBook& phoneBook)
{
	Module00::Contact instance;
	instance.setFirstName(getInput("First Name"));
	instance.setLastName(getInput("Last Name"));
	instance.setNickName(getInput("Nick Name"));
	instance.setNumphone(getInput("Phone Number"));
	instance.setSecret(getInput("shhhhhh secret ..."));
	phoneBook.addContact(instance);
	std::cout << std::endl << "\033[1;32m" << "Contact Added ✓" << "\033[0m" << std::endl;
}

static void removeContact(int index, Module00::PhoneBook& phoneBook)
{
	if (index < 0 || index >= 8 || phoneBook.getContact(index).getFirstName().empty()) {
		std::cout << "\033[1;31m" << "Invalid index or contact does not exist." << "\033[0m" << std::endl;
		return;
	}
	for (int i = index; i < 7; i++) {
		phoneBook.getContact(i) = phoneBook.getContact(i + 1);
	}
	phoneBook.getContact(7).clear();
	phoneBook.decrementNumberContacts();
	phoneBook.reIndexContacts();
	std::cout << "\033[1;32m" << "Contact removed successfully!" << "\033[0m" << std::endl;
	std::system("clear");
	phoneBook.searchContact();
}

static void searchContact(Module00::PhoneBook& phoneBook)
{
	std::string str;

	if (phoneBook.getNumberContacts() > 0)
	{
		while (true)
		{
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
			phoneBook.searchContact();
			std::cout << "\033[1;34m" << "└──────────┴──────────┴──────────┴──────────┘" << "\033[0m" << std::endl;
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

			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && !phoneBook.getContact(str[0] - '1').getFirstName().empty())
			{
				Module00::Contact contact = phoneBook.getContact(str[0] - '1');
				while (true)
				{
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
						std::string strModify;
						phoneBook.modifyContact(contact, strModify);
						phoneBook.setContact(contact.getIndex(), contact);
					}
					else if (str == "REMOVE")
					{
						removeContact(contact.getIndex(), phoneBook);
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
						searchContact(phoneBook);
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
		std::cout << "\033[1;34m" << "You don't have any contacts in your Module00." << "\033[0m" << std::endl;
	}
}

int main(void)
{
	Module00::PhoneBook instance;
	std::string command;
	std::signal(SIGINT, cleanUpAndExit);
	std::signal(SIGQUIT, cleanUpAndExit);
	std::system("clear");

	while (true)
	{
		std::cout << "\033[1;36m" << "╔════════════════════════════╗" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "║        PhoneBook Menu      ║" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "╠════════════════════════════╣" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "║ Contacts: " << instance.getNumberContacts() << "                ║" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "╠════════════════════════════╣" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "║ \033[1;32mADD\033[1;36m    - Add Contact       ║" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "║ \033[1;33mSEARCH\033[1;36m - Search Contact    ║" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "║ \033[1;31mEXIT\033[1;36m   - Exit              ║" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "╚════════════════════════════╝" << "\033[0m" << std::endl;
		std::cout << "\033[1;36m" << "Enter your choice: " << "\033[0m";
		if (!std::getline(std::cin, command))
		{
			if (std::cin.eof()) {
				std::cerr << "\033[1;31m" << "Input interrupted by EOF. Exiting program." << "\033[0m" << std::endl;
				std::exit(1);
			}
			std::cin.clear();
			break;
		}
		if (command == "ADD")
		{
			std::system("clear");
			addContact(instance);
		}
		else if (command == "SEARCH")
		{
			std::system("clear");
			searchContact(instance);
		}
		else if (command == "EXIT")
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
    return (0);
}
