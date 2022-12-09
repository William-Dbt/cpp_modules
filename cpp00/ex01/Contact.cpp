#include <iostream>
#include "Contact.hpp"

Contact::Contact() {
	m_index = 0;
	m_fields[firstName] = "UNKNOW";
}

Contact::~Contact() {}

static void	printFieldsInTab(int index, std::string fields[]) {
	char	buffer[10];

	std::cout << "|    ." << index << "    ";
	for (int i = Contact::firstName; i <= Contact::nickName; i++) {
		std::cout << '|';
		if (fields[i].size() > 10) {
			fields[i].copy(buffer, 9);
			buffer[9] = '\0';
			std::cout << buffer << '.';
		}
		else {
			for (int n = (int)fields[i].size(); n < 10; n++)
				std::cout << ' ';
			std::cout << fields[i];
		}
	}
	std::cout << '|' << std::endl;
}

void	Contact::printFields(bool tab) {
	if (!tab) {
		std::cout << std::endl;
		for (int i = firstName; i <= darkestSecret; i++) {
			switch (i) {
				case firstName: {
					std::cout << "- First name: ";
					break ;
				}
				case lastName: {
					std::cout << "- Last name: ";
					break ;
				}
				case nickName: {
					std::cout << "- Nickname: ";
					break ;
				}
				case phoneNumber: {
					std::cout << "- Phone number: ";
					break ;
				}
				case darkestSecret: {
					std::cout << "- Darkest secret: ";
					break ;
				}
				default:
					break ;
			}
			std::cout << m_fields[i] << std::endl;
		}
		return ;
	}
	printFieldsInTab(m_index, m_fields);
}

bool	Contact::isContactExist() const {
	return m_fields[firstName].compare("UNKNOW");
}

void	Contact::addNewContact(std::string contact[]) {
	for (int i = firstName; i <= darkestSecret; i++)
		m_fields[i] = contact[i];
}

void	Contact::setIndex(int index) {
	m_index = index;
}