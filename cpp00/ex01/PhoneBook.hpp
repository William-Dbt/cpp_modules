#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();

		void	addContact();
		void	showContacts();

	private:
		int		m_oldestContact;
		Contact	m_contacts[8];
};

#endif