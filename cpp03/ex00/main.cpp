#include <iostream>
#include "ClapTrap.hpp"

int	main() {
	ClapTrap	clap("Clap");
	ClapTrap	trap("Trap");
	ClapTrap	test(clap);

	std::cout << std::endl;
	test.attack(clap.getName());
	clap.attack(trap.getName());
	trap.takeDamage(clap.getDamages());

	std::cout << std::endl;
	trap.attack(clap.getName());
	clap.takeDamage(trap.getDamages());

	std::cout << std::endl;
	trap.beRepaired(5);

	std::cout << std::endl;

	return 0;
}
