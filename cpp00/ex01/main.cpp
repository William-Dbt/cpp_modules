#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

static void	printMainMenuMessage() {
	std::cout << std::endl;
	std::cout << "~~~~~~~~ Main  Menu ~~~~~~~~" << std::endl;
	std::cout << "~ Type what you want to do ~" << std::endl;
	std::cout << "~                          ~" << std::endl;
	std::cout << "~ Add new contact: ADD     ~" << std::endl;
	std::cout << "~ Search a contact: SEARCH ~" << std::endl;
	std::cout << "~ Put my phone away: EXIT  ~" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

int	main() {
	bool		status;
	std::string	s_buffer;
	PhoneBook	phoneBook;

	printMainMenuMessage();
	status = true;
	while (status and getline(std::cin, s_buffer)) {
		if (s_buffer.compare("ADD") == 0) {
			std::cout << std::endl;
			phoneBook.addContact();
		}
		else if (s_buffer.compare("SEARCH") == 0) {
			std::cout << std::endl;
			phoneBook.showContacts();
		}
		else if (s_buffer.compare("EXIT") == 0) {
			status = false;
			break ;
		}
		else
			std::cout << "I didn't understand what you want." << std::endl;
		printMainMenuMessage();
	}
	if (status == true) {
		std::cout << "Why did you drop your phone on the floor ?! (╯°□°）╯" << std::endl;
		return 1;
	}
	return 0;
}