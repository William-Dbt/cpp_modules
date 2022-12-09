#include <iostream>
#include <cstdlib>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(int argc, char *argv[]) {
	int	iTest;

	if (argc < 2) {
			std::cout << "Usage: ./form <test>" << std::endl;
			std::cout << "Available tests:" << std::endl;
			std::cout << "0: ShrubberyCreationForm" << std::endl;
			std::cout << "1: RobotomyRequestForm" << std::endl;
			std::cout << "2: PresidentialForm" << std::endl;
			return (2);
	}
	iTest = atoi(argv[1]);
	switch (iTest) {
		case 0: {
			std::cout << "Tests with ShrubberyCreationForm:" << std::endl << std::endl;
			std::cout << "Create new ShrubberyCreationForm that targets Office" << std::endl;
			ShrubberyCreationForm	ShrubberyAsk = ShrubberyCreationForm("Office");
			std::cout << ShrubberyAsk << std::endl;

			try {
				std::cout << std::endl << "New bureaucrat:" << std::endl;
				Bureaucrat	bobbi = Bureaucrat("Bobbi", 135);
				std::cout << bobbi << std::endl;

				std::cout << std::endl << "Try to execute when not signed:" << std::endl;
				bobbi.executeForm(ShrubberyAsk);
				std::cerr << "0: Exception error" << std::endl;
			}
			catch (std::exception & e) {
				std::cerr << e.what() << std::endl;
			}

			std::cout << std::endl << "--------------------" << std::endl;
			try {
				std::cout << std::endl << "New bureaucrat:" << std::endl;
				Bureaucrat	bob = Bureaucrat("Bob", 135);
				std::cout << bob << std::endl;

				std::cout << std::endl << "Try to execute " << ShrubberyAsk.getName() << " with " << bob.getName() << ':' << std::endl;
				bob.signForm(ShrubberyAsk);
				bob.executeForm(ShrubberyAsk);
			}
			catch (std::exception & e) {
				std::cerr << e.what() << std::endl;
			}

			std::cout << std::endl << "--------------------" << std::endl;
			try {
				std::cout << std::endl << "New bureaucrat:" << std::endl;
				Bureaucrat	bobbu = Bureaucrat("Bobbu", 150);
				std::cout << bobbu << std::endl;

				std::cout << std::endl << "Try to execute " << ShrubberyAsk.getName() << " with " << bobbu.getName() << ':' << std::endl;
				bobbu.executeForm(ShrubberyAsk);
				std::cerr << "1: Exception error" << std::endl;
			}
			catch (std::exception & e) {
				std::cerr << e.what() << std::endl;
			}

			
			break;
		}

		case 1: {
			std::cout << "Tests with RobotomyRequestForm:" << std::endl << std::endl;
			std::cout << "Create new RobotmyRequestForm that targets Fuel" << std::endl;
			RobotomyRequestForm	robotomyForm = RobotomyRequestForm("Fuel");
			std::cout << robotomyForm << std::endl;

			try {
				std::cout << std::endl << "New bureaucrat:" << std::endl;
				Bureaucrat	jean = Bureaucrat("Jean", 1);
				std::cout << jean << std::endl;

				std::cout << std::endl << "Try to execute when not signed:" << std::endl;
				jean.executeForm(robotomyForm);
				std::cerr << "2: Exception error" << std::endl;
			}
			catch (std::exception & e) {
				std::cerr << e.what() << std::endl;
			}

			std::cout << std::endl << "--------------------" << std::endl;
			try {
				std::cout << std::endl << "New bureaucrat:" << std::endl;
				Bureaucrat	alfred = Bureaucrat("Alfred", 45);
				std::cout << alfred << std::endl << std::endl;

				std::cout << "Sign form and execute multiple times:" << std::endl;
				alfred.signForm(robotomyForm);
				for (int i = 0; i < 25; i++) {
					alfred.executeForm(robotomyForm);
					std::cout << std::endl;
				}
			}
			catch (std::exception & e) {
				std::cerr << e.what() << std::endl;
			}

			std::cout << std::endl << "--------------------" << std::endl;
			try {
				std::cout << std::endl << "New bureaucrat:" << std::endl;
				Bureaucrat	joseph = Bureaucrat("Joseph", 150);
				std::cout << joseph << std::endl;

				std::cout << std::endl << "Try to execute " << robotomyForm.getName() << " with " << joseph.getName() << ':' << std::endl;
				joseph.executeForm(robotomyForm);
				std::cerr << "3: Exception error" << std::endl;
			}
			catch (std::exception & e) {
				std::cerr << e.what() << std::endl;
			}
			break;
		}
		
		case 2: {
			std::cout << "Tests with PresidentialForm:" << std::endl << std::endl;
			std::cout << "Create new PresidentialPardonForm that targets Serial Killer" << std::endl;
			PresidentialPardonForm	presidentialPardon = PresidentialPardonForm("Serial Killer");
			std::cout << presidentialPardon << std::endl;

			try {
				std::cout << std::endl << "New bureaucrat:" << std::endl;
				Bureaucrat	presidentialAssistant = Bureaucrat("Presidential Assistant", 26);
				std::cout << presidentialAssistant << std::endl;

				std::cout << std::endl << "Try to sign " << presidentialPardon.getName() << " with " << presidentialAssistant.getName() << ':' << std::endl;
				presidentialAssistant.signForm(presidentialPardon);
				std::cerr << "4: Exception error" << std::endl;
			}
			catch (std::exception & e) {
				std::cerr << e.what() << std::endl;
			}

			std::cout << std::endl << "--------------------" << std::endl;
			try {
				std::cout << std::endl << "New bureaucrat:" << std::endl;
				Bureaucrat	scndPresident = Bureaucrat("Second President", 6);
				std::cout << scndPresident << std::endl;

				std::cout << std::endl << "Sign " << presidentialPardon.getName() << " form:" << std::endl;
				scndPresident.signForm(presidentialPardon);
				std::cout << std::endl << "Try to execute when signed:" << std::endl;
				scndPresident.executeForm(presidentialPardon);
				std::cerr << "5: Exception error" << std::endl;
			}
			catch (std::exception & e) {
				std::cerr << e.what() << std::endl;
			}

			std::cout << std::endl << "--------------------" << std::endl;
			try {
				std::cout << std::endl << "New bureaucrat:" << std::endl;
				Bureaucrat	president = Bureaucrat("President", 1);
				std::cout << president << std::endl << std::endl;
				
				std::cout << "Execute " << presidentialPardon.getName() << " with " << president.getName() << ':' << std::endl;
				president.executeForm(presidentialPardon);
			}
			catch (std::exception & e) {
				std::cerr << e.what() << std::endl;
			}
			break;
		}
		default:
			std::cout << "Unknow test!" << std::endl;
	}
	return 0;
}
