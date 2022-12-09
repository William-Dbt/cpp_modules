#include <iostream>
#include "Form.hpp"

Form::Form() : _name("Unnamed"), _signed(false), _signGrade(LOWESTGRADE), _execGrade(LOWESTGRADE) {}

Form::Form(std::string const name, int const signGrade, int const execGrade) :
			_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > LOWESTGRADE || execGrade > LOWESTGRADE)
		throw Form::GradeTooLowException();
	
	if (signGrade < HIGHESTGRADE || execGrade < HIGHESTGRADE)
		throw Form::GradeTooHighException();
}

Form::Form(Form const & ref) : _name(ref._name), _signGrade(ref._signGrade), _execGrade(ref._execGrade) {
	*this = ref;
}

Form::~Form() {}

Form&	Form::operator=(Form const & ref) {
	if (this != &ref) {
		new (this) Form(ref._name, ref._signGrade, ref._execGrade);
		if (ref._signed)
			this->_signed = true;
	}
	return *this;
}

std::string const	Form::getName() const {
	return this->_name;
}

bool	Form::isSigned() const {
	return this->_signed;
}

int	Form::getSignGrade() const {
	return this->_signGrade;
}

int	Form::getExecGrade() const {
	return this->_execGrade;
}

void	Form::beSigned(Bureaucrat const & ref) {
	if (this->isSigned())
		throw Form::AlreadySignedException();

	if (ref.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();

	this->_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw() {
	return ("Form: Form grade too high!");
}

const char*	Form::GradeTooLowException::what() const throw() {
	return ("Form: Form grade too low!");
}

const char*	Form::AlreadySignedException::what() const throw() {
	return ("Form: Form is already signed!");
}

std::ostream&	operator<<(std::ostream &stream, Form const & ref) {
	stream << "Form \'" << ref.getName() << "\' ";
	if (ref.isSigned())
		stream << "is signed.";
	else
		stream << "isn't signed.";

	stream << std::endl;
	stream << "The sign grade is: " << ref.getSignGrade() << '.' << std::endl;
	stream << "The exec grade is: " << ref.getExecGrade() << '.';
	return stream;
}
