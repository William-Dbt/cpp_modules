#include <iostream>

int	main() {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "str: \t\t\t" << &str << std::endl;
	std::cout << "ptr from str: \t\t"<< stringPTR << std::endl;
	std::cout << "reference from str: \t" << &stringREF << std::endl << std::endl;

	std::cout << "str's value: " << str << std::endl;
	std::cout << "ptr's value: " << *stringPTR << std::endl;
	std::cout << "ref's value: " << stringREF << std::endl;
	return 0;
}