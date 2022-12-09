#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const std::string	Intern::_formName[FORM_NUMBERS] = {"shrubbery creation", "robotmy request",
													"presidential pardon"};
const functions		Intern::_functions[FORM_NUMBERS] = { &Intern::createShrubberyCreationForm, 
														&Intern::createRobotomyRequestForm,
														&Intern::createPresidentialPardonForm };

Intern::Intern() {}

Intern::Intern(Intern const & ref) {
	(void)ref;
}

Intern::~Intern() {}

Intern&	Intern::operator=(Intern const & ref) {
	(void)ref;
	return *this;
}

AForm*	Intern::makeForm(std::string const & formName, std::string const & formTarget) {
	std::string	target(formTarget);

	if (target.empty() || target.size() == 0)
		target = "Unknow";

	for (int i = 0; i < FORM_NUMBERS; i++)
		if (formName.compare(this->_formName[i]) == 0)
			return (this->*_functions[i])(target);
	
	throw Intern::UnknowFormException();
}

const char*	Intern::UnknowFormException::what() const throw() {
	return ("Intern: Can't find the requested form!");
}

AForm*	Intern::createShrubberyCreationForm(std::string const target) const {
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::createRobotomyRequestForm(std::string const target) const {
	return new RobotomyRequestForm(target);
}

AForm*	Intern::createPresidentialPardonForm(std::string const target) const {
	return new PresidentialPardonForm(target);
}
