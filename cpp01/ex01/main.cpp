#include <iostream>
#include <stdlib.h>
#include "Zombie.hpp"
#include "Zombie.h"

int	main(int argc, char const *argv[]) {
	Zombie		*horde;
	int			nbZombies;
	std::string	hordeName;

	if (argc != 3) {
		std::cout << "Usage: ./horde <numberOfZombies> <nameOfZombies>" << std::endl;
		return 1;
	}
	nbZombies = atoi(argv[1]);
	if (nbZombies <= 0)
		return 2;

	hordeName = argv[2];
	if (hordeName.empty())
		hordeName = "Unnamed";

	horde = zombieHorde(nbZombies, hordeName);
	for (int i = 0; i < nbZombies; i++) {
		std::cout << i + 1 << ": ";
		horde[i].announce();
	}
	delete []horde;
	return 0;
}