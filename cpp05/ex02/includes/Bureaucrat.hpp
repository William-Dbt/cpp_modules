#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

# define HIGHESTGRADE	1
# define LOWESTGRADE	150

# include <string>
# include <exception>

class	AForm;

class	Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const & ref);
		~Bureaucrat();

		Bureaucrat&			operator=(Bureaucrat const & ref);
		std::string const	getName() const;
		int					getGrade() const;

		void	upGrade();
		void	downGrade();
		void	signForm(AForm& form);
		void	executeForm(AForm const &form);

		class	GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

	private:
		std::string const	_name;
		int					_grade;
};

std::ostream&	operator<<(std::ostream &stream, Bureaucrat const & ref);

#endif
