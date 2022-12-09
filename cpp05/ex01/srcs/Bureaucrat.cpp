#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void	Bureaucrat::signForm(Form& ref) {
	if (ref.isSigned())
		throw Form::AlreadySignedException();

	if (this->_grade > ref.getSignGrade()) {
		std::cerr << this->_name << " couldn't sign " << ref.getName() << " because the sign grade is too high!" << std::endl;
		throw Form::GradeTooHighException();
	}

	std::cout << this->_name << " signed " << ref.getName() << std::endl;
	ref.beSigned(*this);
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
