#include <iostream>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"

#define COLOR_END	"\033[0m"
#define COLOR_RED	"\033[91m"
#define COLOR_GREEN	"\033[92m"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45), _target("Unknow") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequest", 72, 45),
																	_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & ref) : AForm("RobotomyRequest", 72, 45) {
	*this = ref;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const & ref) {
	if (this != &ref) {
		AForm::operator=(ref);
		this->_target = ref._target;
	}
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	static int	seedGenerated = false;
	int			randomInt;

	if (!seedGenerated) {
		srand(time(NULL));
		seedGenerated = true;
	}
	randomInt = rand() % 100 + 1; // Generate random int between 1 and 100;
	// std::cout << "DEBUG: " << randomInt << std::endl;
	AForm::execute(executor);
	std::cout << "BRRRRRRRRR FRRRR KRRR FROUUUUUU KRRRR KRRRRRRRRK PAF POUF PIF" << std::endl;
	if (randomInt < 50)
		std::cout << COLOR_GREEN << this->_target << " has been robotomized!" << COLOR_END << std::endl;
	else
		std::cout << COLOR_RED << "Robotomy failed for target " << this->_target << COLOR_END << std::endl;
}
