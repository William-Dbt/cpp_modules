#include <iostream>
#include "Zombie.hpp"

Zombie*	newZombie(std::string name) {
	Zombie	*newZombie;

	newZombie = new Zombie(name);
	if (!newZombie) {
		std::cout << "Cannot allocate memory." << std::endl;
		return NULL;
	}
	return (newZombie);
}