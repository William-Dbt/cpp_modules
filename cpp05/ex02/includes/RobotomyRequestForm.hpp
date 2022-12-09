#ifndef __ROBOTOMYREQUESTFORM_HPP__
# define __ROBOTOMYREQUESTFORM_HPP__

# include "AForm.hpp"

class	RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const & ref);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm&	operator=(RobotomyRequestForm const & ref);

		virtual void	execute(Bureaucrat const & executor) const;

	private:
		std::string	_target;
};

#endif