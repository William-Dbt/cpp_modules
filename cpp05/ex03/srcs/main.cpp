#include <iostream>
#include <cstdlib>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main() {
	std::cout << "Create a bureaucrat to execute/sign forms:" << std::endl;
	Bureaucrat	boss = Bureaucrat("Boss", 5);
	std::cout << boss << std::endl << std::endl;
	std::cout << "Create new intern that will create forms" << std::endl;
	Intern	bob = Intern();
	std::cout << std::endl;
	try {
		AForm*	shrubbery;

		std::cout << "Create a Shrubbery form:" << std::endl;
		shrubbery = bob.makeForm("shrubbery creation", "garden");
		std::cout << *shrubbery << std::endl;

		std::cout << std::endl << "Boss want to sign and execute the form:" << std::endl;
		boss.signForm(*shrubbery);
		boss.executeForm(*shrubbery);
		delete shrubbery;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "--------------------" << std::endl;

	try {
		AForm*	robotmyrequest;

		std::cout << std::endl << "Create RobotomyRequest form:" << std::endl;
		robotmyrequest = bob.makeForm("robotmy request", "upgrade request");
		std::cout << *robotmyrequest << std::endl;

		std::cout << std::endl << "Boss sign and execute the form:" << std::endl;
		boss.signForm(*robotmyrequest);
		boss.executeForm(*robotmyrequest);
		delete robotmyrequest;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "--------------------" << std::endl;

	try {
		AForm*	presidentialpardon;

		std::cout << std::endl << "Create PresidentialPardon form:" << std::endl;
		presidentialpardon = bob.makeForm("presidential pardon", "serial killer");
		std::cout << *presidentialpardon << std::endl;

		std::cout << std::endl << "Boss sign and execute the form:" << std::endl;
		boss.signForm(*presidentialpardon);
		boss.executeForm(*presidentialpardon);
		delete presidentialpardon;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "--------------------" << std::endl;

	std::cout << std::endl << "Create unexisted form:" << std::endl;
	AForm*	unknowForm;
	try {
		unknowForm = bob.makeForm("new keyboards at school", "serial killer");
		std::cerr << "Unknow Form: exeception error" << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	(void)unknowForm;
	return 0;
}
