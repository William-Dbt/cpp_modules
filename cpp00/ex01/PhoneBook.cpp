#include <iostream>
#include <stdlib.h>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : m_oldestContact(0) {}

PhoneBook::~PhoneBook() {}

static bool	isStrNumbered(std::string str) {
	for (int i = 0; i < (int)str.size(); i++)
		if (!isdigit(str[i]))
			return false;
	return true;
}

void	PhoneBook::showContacts() {
	int			index;
	bool		contactFound = false;
	const char	*indexBuffer;
	std::string	buffer;

	std::cout << "|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|" << std::endl;
	std::cout << "|  .Index  | Fst name | Lst name | Nickname |" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	for (int i = 0; i < 8; i++) {
		if (m_contacts[i].isContactExist()) {
			m_contacts[i].printFields(true);
			contactFound = true;
		}
	}
	if (!contactFound)
		std::cout << "|     No contact found, try to add one!     |" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;

	if (contactFound) {
		std::cout << "To get all the information of a contact," << std::endl;
		std::cout << "please enter his index: ";
		if (!getline(std::cin, buffer)) {
			std::cout << std::endl << std::endl;
			std::cout << "\\!/ ERROR \\!/ Battery is low. \\!/ ERROR \\!/" << std::endl;
			exit(EXIT_FAILURE);
		}
		if (buffer.empty()) {
			std::cout << "I don't understand what you want." << std::endl;
			return ;
		}
		if (!isStrNumbered(buffer))
			std::cout << "Index must be a number!" << std::endl;
		else {
			indexBuffer = buffer.c_str();
			index = atoi(indexBuffer);
			if (index < 0 or index > 7)
				std::cout << "Index must be included between 0 and 7!" << std::endl;
			else if (index >= 0 and index <= 7) {
				if (m_contacts[index].isContactExist())
					m_contacts[index].printFields(false);
				else
					std::cout << "You don't have any contact at index " << index << '!' << std::endl;
			}
		}
	}
}

static bool	isStrEmpty(std::string str) {
	for (int i = 0; i < (int)str.size(); i++)
		if (!isspace(str[i]))
			return false;
	if (str.empty())
		return true;
	return true;
}

static void	printContactForm(int field) {
	std::cout << "Enter the contact's ";
	switch (field) {
		case Contact::firstName: {
			std::cout << "first name";
			break ;
		}
		case Contact::lastName: {
			std::cout << "last name";
			break ;
		}
		case Contact::nickName: {
			std::cout << "nick name";
			break ;
		}
		case Contact::phoneNumber: {
			std::cout << "phone number";
			break ;
		}
		case Contact::darkestSecret: {
			std::cout << "darkest secret";
			break ;
		}
		default:
			break ;
	}
	std::cout << ": ";
}

static std::string	getContactFields(int field) {
	std::string	buffer;

	printContactForm(field);
	while (getline(std::cin, buffer)) {
		if (isStrEmpty(buffer)) {
			std::cout << "The field can't be empty!" << std::endl;
			printContactForm(field);
			continue ;
		}
		break ;
	}
	return buffer;
}

void	PhoneBook::addContact() {
	int			i;
	std::string	newContact[5];

	for (i = Contact::firstName; i <= Contact::darkestSecret; i++) {
		newContact[i] = getContactFields(i);
		if (newContact[i].empty()) {
			std::cout << std::endl << "Don't throw your phone in the wall! 😡" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	for (i = 0; i < 8; i++)
		if (!m_contacts[i].isContactExist()) {
			m_contacts[i].addNewContact(newContact);
			m_contacts[i].setIndex(i);
			break ;
		}
	if (i == 8) {
		m_contacts[m_oldestContact].addNewContact(newContact);
		m_oldestContact = (m_oldestContact == 7) ? 0 : m_oldestContact + 1;
	}
}
