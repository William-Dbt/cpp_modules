#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact {
	public:
		Contact();
		~Contact();
		
		enum e_fields {
			firstName = 0,
			lastName,
			nickName,
			phoneNumber,
			darkestSecret
		};

		void	printFields(bool tab);
		bool	isContactExist() const;
		void	addNewContact(std::string contact[]);
		void	setIndex(int index);

	private:
		int			m_index;
		std::string	m_fields[5];
};

#endif