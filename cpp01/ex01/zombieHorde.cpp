#include <iostream>
#include "Zombie.h"
#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	Zombie	*horde;

	horde = new Zombie[N];
	if (!horde) {
		std::cout << "Can't allocate memory for the horde." << std::endl;
		return NULL;
	}
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return horde;
}