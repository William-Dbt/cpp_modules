#include <iostream>
#include "convert_stuff.hpp"

void	toChar(long double num) {
	std::cout << "char: ";
	if (std::isnan(num) || num < 0 || num > 127) {
		std::cout << "impossible" << std::endl;
		return ;
	}
	else if (!isprint(num)) {
		std::cout << "non displayable" << std::endl;
		return ;
	}
	std::cout << static_cast<char>(num) << std::endl;
}

static bool	isIntLimit(long double num) {
	if (num < -2147483648)
		return true;

	if (num > 2147483647)
		return true;
	
	return false;
}

void	toInt(long double num) {
	std::cout << "int: ";
	if (std::isnan(num) || std::isinf(num) || isIntLimit(num)) {
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << static_cast<int>(num) << std::endl;
}

void	toFloat(long double num) {
	std::cout << "float: ";
	std::cout << static_cast<float>(num);
	if (num == static_cast<int>(num))
		std::cout << ".0";

	std::cout << 'f' << std::endl;
}

void	toDouble(long double num) {
	std::cout << "double: ";
	std::cout << static_cast<double>(num);
	if (num == static_cast<int>(num))
		std::cout << ".0";

	std::cout << std::endl;
}
