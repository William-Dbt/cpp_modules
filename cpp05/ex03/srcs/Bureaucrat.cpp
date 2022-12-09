#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(LOWESTGRADE) {}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name) {
	if (grade < HIGHESTGRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWESTGRADE)
		throw Bureaucrat::GradeTooLowException();

	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & ref) {
	*this = ref;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const & ref) {
	if (this != &ref)
		new (this) Bureaucrat(ref._name, ref._grade);

	return *this;
}

std::string const	Bureaucrat::getName() const {
	return this->_name;
}

int	Bureaucrat::getGrade() const {
	return this->_grade;
}

void	Bureaucrat::upGrade() {
	if (this->_grade - 1 < HIGHESTGRADE)
		throw Bureaucrat::GradeTooHighException();
	
	this->_grade--;
}

void	Bureaucrat::downGrade() {
	if (this->_grade + 1 > LOWESTGRADE)
		throw Bureaucrat::GradeTooLowException();

	this->_grade++;
}

void	Bureaucrat::signForm(AForm& form) {
	if (form.isSigned())
		throw AForm::AlreadySignedException();

	if (this->_grade > form.getSignGrade()) {
		std::cerr << this->_name << " couldn't sign " << form.getName() << " because the sign grade is too high!" << std::endl;
		throw AForm::GradeTooHighException();
	}

	std::cout << this->_name << " signed " << form.getName() << std::endl;
	form.beSigned(*this);
}

void	Bureaucrat::executeForm(AForm const & form) {
	form.execute(*this);
	std::cout << this->_name << " executed " << form.getName() << std::endl;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat: Grade too high!");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat: Grade too low!");
}

std::ostream&	operator<<(std::ostream &stream, Bureaucrat const & ref) {
	stream << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return stream;
}
