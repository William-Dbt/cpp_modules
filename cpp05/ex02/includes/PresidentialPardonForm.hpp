#ifndef __PRESIDENTIALPARDONFROM_HPP__
# define __PRESIDENTIALPARDONFROM_HPP__

# include "AForm.hpp"

class	PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const & ref);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm&	operator=(PresidentialPardonForm const & ref);

		virtual void	execute(Bureaucrat const & executor) const;

	private:
		std::string	_target;
};

#endif