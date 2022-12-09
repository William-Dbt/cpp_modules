#include <iostream>
#include "convert_stuff.hpp"

static bool	isZero(char const *str) {
	int	i = 0;

	if (str[i] == '\0')
		return false;

	while (str[i] != '\0' && str[i] != '.') {
		if (str[i] != '0')
			return false;

		i++;
	}

	if (str[i] != '\0' && str[i] == '.')
		i++;

	if (str[i] == '\0')
		return true;

	while (str[i] != '\0' && str[i] != 'f') {
		if (str[i] != '0')
			return false;

		i++;
	}
	if (str[i] != '\0' && str[i] == 'f')
		i++;

	if (str[i] == '\0')
		return true;

	return false;
}

int	main(int argc, char const *argv[]) {
	int			argSize;
	long double	dNumber;

	if (argc != 2) {
		std::cout << "Usage: ./convert <number> (char, int, float, double)" << std::endl;
		return 1;
	}
	dNumber = strtold(argv[1], NULL);
	if (dNumber == 0 && !isZero(argv[1])) {
		argSize = strlen(argv[1]);
		if (argSize < 1) {
			std::cerr << "Error: Empty argument." << std::endl;
			return 2;
		}
		else if (argSize > 1) {
			std::cerr << "Error: String aren't accepted!" << std::endl;
			return 3;
		}
		else
			dNumber = static_cast<int>(argv[1][0]);
	}
	toChar(dNumber);
	toInt(dNumber);
	toFloat(dNumber);
	toDouble(dNumber);
	return 0;
}
