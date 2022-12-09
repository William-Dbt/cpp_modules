#ifndef __INTERN_HPP__
# define __INTERN_HPP__

# define FORM_NUMBERS	3

# include "AForm.hpp"

class Intern;

typedef	AForm* (Intern::*functions)(std::string const target) const;

class	Intern {
	public:
		Intern();
		Intern(Intern const & ref);
		~Intern();

		Intern&	operator=(Intern const & ref);
		AForm*	makeForm(std::string const & formName, std::string const & formTarget);

		class	UnknowFormException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

	private:
		static const std::string	_formName[FORM_NUMBERS];
		static const functions		_functions[FORM_NUMBERS];

		AForm*	createShrubberyCreationForm(std::string const target) const;
		AForm*	createRobotomyRequestForm(std::string const target) const;
		AForm*	createPresidentialPardonForm(std::string const target) const;
};

#endif
