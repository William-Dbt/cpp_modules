#ifndef __FORM_HPP__
# define __FORM_HPP__

# include "Bureaucrat.hpp"

class	Form {
	public:
		Form();
		Form(std::string const name, int const signGrade, int const execGrade);
		Form(Form const & ref);
		~Form();

		Form&	operator=(Form const & ref);
		std::string const	getName() const;
		bool				isSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void				beSigned(Bureaucrat const & ref);

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

	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_execGrade;
};

std::ostream&	operator<<(std::ostream &stream, Form const & ref);

#endif