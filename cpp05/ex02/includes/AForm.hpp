#ifndef __AFORM_HPP__
# define __AFORM_HPP__

# include "Bureaucrat.hpp"

class	AForm {
	public:
		AForm();
		AForm(std::string const name, int const signGrade, int const execGrade);
		AForm(AForm const & ref);
		virtual ~AForm();

		AForm&				operator=(AForm const & ref);
		std::string const	getName() const;
		bool				isSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void				beSigned(Bureaucrat const & ref);

		virtual void		execute(Bureaucrat const & executor) const = 0;

		class	GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

		class	AlreadySignedException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

		class	NotSignedException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

	private:
		std::string	_name;
		bool		_signed;
		int			_signGrade;
		int			_execGrade;
};

std::ostream&	operator<<(std::ostream &stream, AForm const & ref);

#endif