#include <iostream>
#include "Bureaucrat.hpp"

int	main() {
	try {
		std::cout << "Mid-class bureaucrat without exception:" << std::endl;
		Bureaucrat	bobbi = Bureaucrat("Bobbi", (int)(LOWESTGRADE / 2));
		std::cout << bobbi << std::endl;
		
		std::cout << std::endl << "Upgrade one time his grade:" << std::endl;
		bobbi.upGrade();
		std::cout << bobbi << std::endl;
		
		std::cout << std::endl << "Then downgrade two times:" << std::endl;
		bobbi.downGrade();
		bobbi.downGrade();
		std::cout << bobbi << std::endl;
	}
	catch (std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "------------------------------" << std::endl << std::endl;
	try {
		std::cout << "High-class bureaucrat with exception:" << std::endl;
		Bureaucrat	billi = Bureaucrat("Billi", HIGHESTGRADE);
		std::cout << billi << std::endl;
		
		std::cout << std::endl << "Upgrade his grade:" << std::endl;
		billi.upGrade();
		std::cerr << "Error: upgrade exception" << std::endl;
	}
	catch (std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "------------------------------" << std::endl << std::endl;
	try {
		std::cout << "Low-class bureaucrat with exception:" << std::endl;
		Bureaucrat	bobbu = Bureaucrat("Bobbu", LOWESTGRADE);
		std::cout << bobbu << std::endl;

		std::cout << std::endl << "Downgrade his grade:" << std::endl;
		bobbu.downGrade();
		std::cerr << "Error: downgrade exception" << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "------------------------------" << std::endl << std::endl;
	try {
		std::cout << "Bureaucrat overflow highest grade in constructor:" << std::endl;
		Bureaucrat	bibou = Bureaucrat("Bibou", HIGHESTGRADE - 1);
		std::cerr << "Error: constructor exception (high grade)" << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "------------------------------" << std::endl << std::endl;
	try {
		std::cout << "Bureaucrat overflow lowest grade in constructor:" << std::endl;
		Bureaucrat	boubi = Bureaucrat("Boubi", LOWESTGRADE + 1);
		std::cerr << "Error: constructor exception (low grade)" << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
