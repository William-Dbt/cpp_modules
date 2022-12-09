#include <iostream>
#include "AForm.hpp"

AForm::AForm() : _name("Unnamed"), _signed(false), _signGrade(LOWESTGRADE), _execGrade(LOWESTGRADE) {}

AForm::AForm(std::string const name, int const signGrade, int const execGrade) :
			_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > LOWESTGRADE || execGrade > LOWESTGRADE)
		throw AForm::GradeTooLowException();
	
	if (signGrade < HIGHESTGRADE || execGrade < HIGHESTGRADE)
		throw AForm::GradeTooHighException();
}

AForm::AForm(AForm const & ref) {
	*this = ref;
}

AForm::~AForm() {}

AForm&	AForm::operator=(AForm const & ref) {
	if (this != &ref) {
		this->_name = ref._name;
		this->_signGrade = ref._signGrade;
		this->_execGrade = ref._execGrade;
		if (ref._signed)
			this->_signed = true;
	}
	return *this;
}

std::string const	AForm::getName() const {
	return this->_name;
}

bool	AForm::isSigned() const {
	return this->_signed;
}

int	AForm::getSignGrade() const {
	return this->_signGrade;
}

int	AForm::getExecGrade() const {
	return this->_execGrade;
}

void	AForm::beSigned(Bureaucrat const & ref) {
	if (this->isSigned())
		throw AForm::AlreadySignedException();

	if (ref.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();

	this->_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const {
	if (!this->isSigned())
		throw AForm::NotSignedException();

	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooHighException();
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return ("Form: Form grade too high!");
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return ("Form: Form grade too low!");
}

const char*	AForm::AlreadySignedException::what() const throw() {
	return ("Form: Form is already signed!");
}

const char*	AForm::NotSignedException::what() const throw() {
	return ("Form: Form isn't signed!");
}

std::ostream&	operator<<(std::ostream &stream, AForm const & ref) {
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
