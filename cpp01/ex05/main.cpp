#include <iostream>
#include "Harl.hpp"

int	main() {
	Harl		harl;

	std::cout << "The dark story of Harl and his 7XL-double-cheese-triple-pickle-specialketchup..." << std::endl << std::endl;
	std::cout << "Let's go to the fast food!" << std::endl;
	std::cout << "Son ask for me a 7XL-double-cheese-triple-pickle-specialketchup burger please." << std::endl;
	std::cout << "And don't forget the bacon!" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "How much you said ?!" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	std::cout << "I'll speak to the employee, stay here." << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	std::cout << "*After a lot of negotiations and four cokes on the floor*" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	harl.complain("");

	return 0;
}