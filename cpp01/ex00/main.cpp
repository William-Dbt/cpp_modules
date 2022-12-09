#include <iostream>
#include "Zombie.hpp"
#include "Zombie.h"

int	main() {
	Zombie	*z_gamma;

	std::cout << "Calling three zombies from constructors:" << std::endl;
	Zombie	z_alpha("Alpha"), z_beta("Beta"), z_unnamed;
	z_alpha.announce();
	z_beta.announce();
	z_unnamed.announce();
	std::cout << std::endl;

	std::cout << "Calling two zombies from functions:" << std::endl;
	z_gamma = newZombie("Gamma");
	if (z_gamma == NULL)
		std::cout << "Gamma can't fight for us, memory problem..." << std::endl;
	else {
		z_gamma->announce();
		std::cout << "Gamma is now on the heap!" << std::endl;
	}
	std::cout << "Delta on the stack, let's go!" << std::endl;
	randomChump("Delta");
	std::cout << std::endl;

	std::cout << "Gamma, you play too much Fornite, I've to delete you! Bye." << std::endl;
	if (z_gamma)
		delete z_gamma;
	std::cout << std::endl;
	return 0;
}