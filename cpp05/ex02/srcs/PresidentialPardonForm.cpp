#include <iostream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5), _target("Unknow") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("Presidential", 25, 5),
																			_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & ref) : AForm("Presidential", 25, 5) {
	*this = ref;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const & ref) {
	if (this != &ref) {
		AForm::operator=(ref);
		this->_target = ref._target;
	}
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	AForm::execute(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
