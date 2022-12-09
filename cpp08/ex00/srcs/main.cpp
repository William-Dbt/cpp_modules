#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int	main() {
	std::vector<int>	vec;

	vec.push_back(1);
	vec.push_back(11);
	vec.push_back(22);
	vec.push_back(44);
	vec.push_back(88);
	vec.push_back(176);
	try {
		std::cout << "First search: " << *::easyfind(vec, 11) << std::endl;
	}
	catch (std::exception & e) { std::cerr << e.what() << std::endl; }

	try {
		std::cout << "Second search: " << *::easyfind(vec, 88) << std::endl;
	}
	catch (std::exception & e) { std::cerr << e.what() << std::endl; }

	try {
		std::cout << "Third search: " << *::easyfind(vec, 42) << std::endl;
		std::cerr << "error: exception" << std::endl;
	}
	catch (std::exception & e) { std::cerr << e.what() << std::endl; }

	std::cout << std::endl << "--------------------" << std::endl << std::endl;

	std::list<int>	list;

	list.push_back(346);
	list.push_back(71347);
	list.push_back(2123);
	list.push_back(48998);
	list.push_back(8);
	list.push_back(123516126);
	try {
		std::cout << "First search: " << *::easyfind(list, 123516126) << std::endl;
	}
	catch (std::exception & e) { std::cerr << e.what() << std::endl; }

	try {
		std::cout << "Second search: " << *::easyfind(list, 2123) << std::endl;
	}
	catch (std::exception & e) { std::cerr << e.what() << std::endl; }
	
	try {
		std::cout << "Third search: " << *::easyfind(list, 42) << std::endl;
		std::cerr << "error: exception" << std::endl;
	}
	catch (std::exception & e) { std::cerr << e.what() << std::endl; }
	
	return 0;
}
