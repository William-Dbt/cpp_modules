#include <iostream>
#include "Form.hpp"

int	main() {
	try {
		std::cout << "Mid-class bureaucrat:" << std::endl;
		Bureaucrat	bobbi = Bureaucrat("Bobbi", (int)(LOWESTGRADE / 2));
		std::cout << bobbi << std::endl;

		std::cout << std::endl << "A new form with mid access:" << std::endl;
		Form	ctrlMission = Form("Control mission", (int)(LOWESTGRADE / 2), (int)(LOWESTGRADE / 2));
		std::cout << ctrlMission << std::endl;

		std::cout << std::endl << "Can " << bobbi.getName() << " sign the form?" << std::endl;
		bobbi.signForm(ctrlMission);
		std::cout << ctrlMission << std::endl;

		std::cout << std::endl << "Try to resign the form:" << std::endl;
		bobbi.signForm(ctrlMission);
		std::cerr << "Error: sign exception" << std::endl;
	}
	catch (std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "------------------------------" << std::endl << std::endl;
	try {
		std::cout << "Mid-class bureaucrat:" << std::endl;
		Bureaucrat	bobbiSenior = Bureaucrat("Bobbi Senior", (int)(LOWESTGRADE / 2));
		std::cout << bobbiSenior << std::endl;

		std::cout << std::endl << "A new form with high access on sign:" << std::endl;
		Form	defenseSecret01 = Form("Defense Secret 01", HIGHESTGRADE, 142);
		std::cout << defenseSecret01 << std::endl;

		std::cout << std::endl << "Can " << bobbiSenior.getName() << " sign the form?" << std::endl;
		bobbiSenior.signForm(defenseSecret01);
		std::cerr << "Error: sign exception" << std::endl;
	}
	catch (std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "------------------------------" << std::endl << std::endl;
	try {
		std::cout << "Form with high grade in constructor with exception:" << std::endl;
		Form	secret00 = Form("Secret 00", HIGHESTGRADE - 1, HIGHESTGRADE);
		std::cout << "Error: exception form in constructor (high)" << std::endl;
	}
	catch (std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "------------------------------" << std::endl << std::endl;
	try {
		std::cout << "Form with low grade in constructor with exception:" << std::endl;
		Form	secret01 = Form("Secret 01", LOWESTGRADE, LOWESTGRADE + 1);
		std::cout << "Error: exception form in constructor (low)" << std::endl;
	}
	catch (std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
