#include <iostream>
#include <string>
#include "iter.hpp"

static void	displayStr(std::string const & str) {
	std::cout << str << std::endl;
}

static void	displayInt(int const & i) {
	std::cout << i << std::endl;
}

static void	increment(int& value) {
	value += 1;
}

int	main() {
	std::string	strTab[] = {"coucou", "je", "suis", "toto", "le", "rigolo"};

	std::cout << "Try to display strTab:" << std::endl;
	::iter(strTab, 6, &displayStr);
	std::cout << std::endl;

	int	intTab[] = {10, 15, 20, 30, 40, 50};
	
	std::cout << "Try to display intTab:" << std::endl;
	::iter(intTab, 6, displayInt);
	std::cout << std::endl;

	std::cout << "Now increment intTab array and print them:" << std::endl;
	::iter(intTab, 6, increment);
	::iter(intTab, 6, displayInt);
}
