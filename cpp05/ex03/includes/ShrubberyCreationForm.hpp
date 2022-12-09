#ifndef __SHRUBBERYCREATIONFORM_HPP__
# define __SHRUBBERYCREATIONFORM_HPP__

# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const & ref);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const & ref);

		virtual void	execute(Bureaucrat const & executor) const;

		class	FileNotOpenedException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

	private:
		std::string	_target;
};

#endif
